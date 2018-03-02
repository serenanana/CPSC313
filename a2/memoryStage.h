//
//  memoryStage.h
//  A2
//
//  Created by Donald  Acton on 2017-10-01.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#ifndef memoryStage_h
#define memoryStage_h

#include <stdio.h>
#include "instructionSpecifications.h"
struct memoryStateStuct {
    uint64_t PC; // The program counter associated with this instruction

  // Add fields here to capture stage registers and state associated with 
  // processing and managing the stage. Note that when the simulation starts
  // the stage registers are initailized to indicate that on the first 
  // clock tick that this stage is working on a NOP instruction from address 
  // 0.
};

void processMemoryStage(void);

#endif /* memoryStage_h */
