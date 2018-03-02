//
//  writeBackStage.c
//  A2
//
//  Created by Donald  Acton on 2017-10-01.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#include "writeBackStage.h"
#include "instructionSpecifications.h"
#include "printInternalReg.h"

// Use this struct to store state information for this stage. By making it 
// static the structure and its fields can be accessed in this file
// but not in the reset of the program. 
static struct writeBackStateStruct wbs;

void processWriteBackStage(void) {
  // Probably empty, but here is an example of printing
  printReg("W", 82, 0x299, 7, 2, 0, UNNEEDED_REG, UNNEEDED_REG,
	   0, UNNEEDED_REG, UNNEEDED_REG,
	   1, 0xF, 0xF, 0, UNNEEDED_ADDR, 0, UNNEEDED_ADDR, 
	   getInstructionMnemonic(7, 2));
    return;
}
