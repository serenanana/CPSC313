//
//  writeBackStage.h
//  A2
//
//  Created by Donald  Acton on 2017-10-01.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#ifndef writeBackStage_h
#define writeBackStage_h

#include <stdio.h>
#include "instructionSpecifications.h"
struct writeBackStateStruct {
    uint64_t PC;  // The program counter associated with this instruction

  // Add fields here to capture stage registers and state associated with 
  // processing and managing the stage. Note that when the simulation starts
  // the stage registers are initailized to indicate that on the first 
  // clock tick that this stage is working on a NOP instruction from address 
  // 0.

} ;


void processWriteBackStage(void) ;

#endif /* writeBackStage_h */
