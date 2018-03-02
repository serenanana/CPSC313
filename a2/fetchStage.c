//
//  fetchStage.c
//  A2
//
//  Created by Donald  Acton on 2017-10-01.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#include "fetchStage.h"
#include "instructionSpecifications.h"
#include <sys/stat.h>
#include <sys/mman.h>
#include "decodeStage.h"

// Use this struct to store state information for this stage. By making it 
// static the structure and its fields can be accessed in this file
// but not in the reset of the program. 
static struct fetchStateStruct fs;


// This maps the file into main memory so that pointers can be used to access
// the instruction directly

int initializeFetchState(int memoryFileFD, uint64_t initialPC) {
    struct stat statBuff;
    
    if (fstat(memoryFileFD, &statBuff)) {
        return -2;
    }
 
    // Do the actual mapping.
    fs.instBase =  mmap(0, statBuff.st_size, PROT_READ,
                                MAP_PRIVATE, memoryFileFD, 0);
    if (fs.instBase == MAP_FAILED) {
        return -3;
    }
    fs.lastAddr = fs.instBase + statBuff.st_size;
    fs.PC = initialPC;
    
    return 0;
}

void processFetchStage(void) {
  // Add code to perform fetch stage processing. 

  // The following line illustrates how to print information for this stage. 
  // This is an example only and you should delete it or replace it with an 
  // appropriate one. 

  // This example is for a stall
    void* start = fs.instBase + fs.PC;
    
    fs.icd = *((char*)start) >> 4 & 0x0F;
    fs.ifn = *((char*)start) & 0xF;
    
    if (fs.icd != 0 || fs.icd != 1 || fs.icd != 7 || fs.icd != 8 || fs.icd != 9) {
        fs.rA = *((char*)start+1) >> 4 & 0x0F;
        fs.rB = *((char*)start+1) & 0xF;
    }
    
    if (fs.icd >= 3 && id.icd <= 5) {
        fs.valC = *(uint64_t*)((char*)start + 2);
    } else if (fs.icd == 7 || fs.icd == 8){
        fs.valC = *(uint64_t*)((char*)start + 1);
    }
    
    fs.valP = fs.PC + getInstructionSize(fs.icd);
    
//  printReg("F W", 10, 0x100, 6,  2, 1, 10, 11,
//	   1, 10, 11,
//	   0, UNNEEDED_REG, UNNEEDED_REG, 1, 0, 1, 12, "andq");
  // Something that uses valC
    printReg("F", 0, fs.PC,fs.icd, fs.ifn, 1, fs.rA , fs.rB,
             0, UNNEEDED_REG, UNNEEDED_REG,
             0, UNNEEDED_REG, UNNEEDED_REG, 1, fs.valC, 1, fs.valP,
             getInstructionMnemonic(fs.icd, fs.ifn));
    
    if (fs.icd == 7 || fs.icd == 8) {
        fs.PC = fs.valC;
    }else{
        fs.PC = fs.valP;
    }
    
    passToDecode(fs.icd,fs.ifn, fs.rA, fs.rB, fs.valC, fs.valP, fs.PC);
//    
//    if (fs.icd == 7 || fs.icd == 8) {
//        fs.PC = fs.valC;
//    }else{
//        fs.PC = fs.valP;
//    }
}


