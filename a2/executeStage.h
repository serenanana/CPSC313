//
//  executeStage.h
//  A2
//
//  Created by Donald  Acton on 2017-10-01.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#ifndef executeStage_h
#define executeStage_h
#include "instructionSpecifications.h"
#include <stdio.h>

struct executeStateStruct {
    uint64_t PC ;  // The program counter associated with this instruction

  // Add fields here to capture stage registers and state associated with 
  // processing and managing the stage. Note that when the simulation starts
  // the stage registers are initailized to indicate that on the first 
  // clock tick that this stage is working on a NOP instruction from address 
  // 0.
    
    nibble icd, dstE, dstM;
    nibble cnd;
    uint64_t valE, valA, valP;
};

void passToExecute(nibble icd, nibble dstE, nibble dstM, uint64_t valP, uint64_t PC);

void processExecuteStage(void) ;

#endif /* executeStage_h */
