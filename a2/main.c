//
//  main.c
//  A2
//
//  Created by Donald  Acton on 2017-09-30.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include "printInternalReg.h"
#include "fetchStage.h"
#include "instructionSpecifications.h"
#include "decodeStage.h"
#include "executeStage.h"
#include "memoryStage.h"
#include "writeBackStage.h"

int main(int argc, char **argv) {
    
    int machineCodeFD = -1;       // File descriptor of file with object code
    
    // Verify that the command line has an appropriate number
    // of arguments
    
    if (argc < 2 || argc > 4) {
        printf("Usage: %s InputFilename [startingOffset] [ClockTicks]\n", argv[0]);
        return ERROR_RETURN;
    }
    
    // First argument is the file to open, attempt to open it
    // for reading and verify that the open did occur.
    machineCodeFD = open(argv[1], O_RDONLY);
    
    if (machineCodeFD < 0) {
        printf("Failed to open: %s\n", argv[1]);
        return ERROR_RETURN;
    }
    
    // Get the initial offset into the file
    
    uint64_t PC = 0;
    if (3 <= argc) {
        // See man page for strtol() as to why
        // we check for errors by examining errno
        errno = 0;
        PC = strtol(argv[2], NULL, 0);
        if (errno != 0) {
            perror("Invalid offset on command line");
            return ERROR_RETURN;
        }
    }
    
    // Get the count of how many clock ticks to run for.
    int endTime = -1;
    if (4 == argc) {
        errno = 0;
        endTime = strtol(argv[3], NULL, 0);
        if (errno != 0) {
            perror("Invalid end time on command line");
            return ERROR_RETURN;
        }
    }
    
    if (initializeFetchState(machineCodeFD, PC)) {
        printf("Initialization of fetch stage failed\n");
        return -99;
    };
   
    printf("Opened %s, starting offset 0x%016llX stop time = %d\n",
	   argv[1], PC, endTime);

    int OK = 1;

    for (int clock = 0; OK ; clock++) {
      processWriteBackStage();
      processMemoryStage();
      processExecuteStage();
      processDecodeStage();
      processFetchStage();      
      printf("\n");
      // Here might be a good spot to add code or make function calls 
      // to check for hazards cause stage registers to be updated etc.

      if (endTime != -1) {
          if (clock >= endTime) {
              printf("Time expired %d %d \n", clock, endTime);
              OK = 0;
          }
      }
    }
    printf("Normal termination\n");
    return SUCCESS;
}


