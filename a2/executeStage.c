//
//  executeStage.c
//  A2
//
//  Created by Donald  Acton on 2017-10-01.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#include "executeStage.h"
#include "memoryStage.h"
#include "printInternalReg.h"
#include "instructionSpecifications.h"


// Use this struct to store state information for this stage. By making it 
// static the structure and its fields can be accessed in this file
// but not in the reset of the program. 
static struct executeStateStruct es;

void passToExecute(nibble icd, nibble dstE, nibble dstM, uint64_t valC, uint64_t valP, uint64_t PC){
    es.icd = icd;
    es.dstE = dstE;
    es.dstM = dstM;
    es.valE = valC;
    es.valP = valP;
    es.PC = PC;
}

void processExecuteStage(void) {
  // This function probably remains empty but here is sample of 
  // printing
    
    if (es.icd == 2 || es.icd == 3 || es.icd == 6) {
        
    }
    
  
  printReg("E", 10, 8, 2, 2, 0, UNNEEDED_REG, UNNEEDED_REG,
           1, 3, 4,
           1, 4, 0xF, 0, UNNEEDED_ADDR, 0, UNNEEDED_ADDR, getInstructionMnemonic(2,2));
}

