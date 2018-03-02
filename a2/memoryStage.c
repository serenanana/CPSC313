//
//  memoryStage.c
//  A2
//
//  Created by Donald  Acton on 2017-10-01.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#include "memoryStage.h"
#include "writeBackStage.h"
#include "printInternalReg.h"
#include "instructionSpecifications.h"

// Use this struct to store state information for this stage. By making it 
// static the structure and its fields can be accessed in this file
// but not in the reset of the program. 
static struct memoryStateStuct ms;


void processMemoryStage(void) {
  // probably empty as well but here is sample of printing
   printReg("M", 10, 45, 1, 0, 0, UNNEEDED_REG, UNNEEDED_REG,
	     0, UNNEEDED_REG, UNNEEDED_REG,
             1, 0xf, 0xf, 0, UNNEEDED_ADDR, 0, UNNEEDED_ADDR, "NOP");
  return;
}
