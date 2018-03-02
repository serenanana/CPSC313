//
//  decodeStage.h
//  A2
//
//  Created by Donald  Acton on 2017-10-01.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#ifndef decodeStage_h
#define decodeStage_h
#include <sys/types.h>
#include "instructionSpecifications.h"


struct decodeStateStruct {

  uint64_t PC;  // The program counter associated with this instruction

  // Add fields here to capture stage registers and state associated with 
  // processing and managing the stage. Note that when the simulation starts
  // the stage registers are initailized to indicate that on the first 
  // clock tick that this stage is working on a NOP instruction from address 
  // 0.
    nibble icd, ifn, rA, rB, srcA, srcB, dstE, dstM;
    uint64_t valC, valP, valA, valB;
};

nibble decodeGetrA();
void passToDecode(nibble icd, nibble ifn, nibble rA, nibble rB, uint64_t valC, uint64_t valP, uint64_t PC);
void processDecodeStage(void);

#endif /* decodeStage_h */
