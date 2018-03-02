//
//  decodeStage.c
//  A2
//
//  Created by Donald  Acton on 2017-10-01.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#include "decodeStage.h"
#include "instructionSpecifications.h"
#include "executeStage.h"
#include "printInternalReg.h"

// Use this struct to store state information for this stage. By making it 
// static the structure and its fields can be accessed in this file
// but not in the reset of the program. 

static struct decodeStateStruct ds;


void passToDecode(nibble icd, nibble ifn, nibble rA, nibble rB, uint64_t valC, uint64_t valP, uint64_t PC){
    ds.icd = icd;
    ds.ifn = ifn;
    ds.rA = rA;
    ds.rB = rB;
    ds.valC = valC;
    ds.valP = valP;
    ds.PC = PC;//current PC
}

void processDecodeStage(void) {

  // Add code to perform fetch stage processing. 

  // The following line illustrates how to print information for this stage. 
  // This is an example only and you should delete it or replace it with an 
  // appropriate one.
    ds.dstE = UNNEEDED_REG;
    ds.dstM = UNNEEDED_REG;
    ds.srcA = UNNEEDED_REG;
    ds.srcB = UNNEEDED_REG;
    
    //dstE dstM (load value into register)
    if(ds.icd == 2 || ds.icd == 3 || ds.icd == 6) {
        ds.dstE = ds.rB;
    } else if (ds.icd == 5 || ds.icd == 11) {
        ds.dstM = ds.rB;
    } else if (ds.icd == PUSH || ds.icd == 11 || ds.icd == 8 || ds.icd == 9) {
        ds.dstE = STACK_PTR;
    }
    
    //srcA srcB (register needed to read)
    if (ds.icd == 2 || ds.icd == 10) {
        ds.srcA = ds.rA;
    }else if (ds.icd == 4 || ds.icd == 6) {
        ds.srcA = ds.rA;
        ds.srcB = ds.rB;
    }else if (ds.icd == 5) {
        ds.srcB = ds.rB;
    }else if (ds.icd == 11) {
        ds.srcB = STACK_PTR;
    }
    
    ds.valP = ds.PC + getInstructionSize(ds.icd);

    printReg("D", 0, ds.PC, ds.icd, ds.ifn, 1, ds.rA, ds.rB,
             1, ds.srcA, ds.srcB,
             1, ds.dstE, ds.dstM, 1, ds.valC ,
             1, ds.valP, getInstructionMnemonic(ds.icd,ds.ifn));
   //PC?
    ds.PC = ds.valP;
    
    
    passToExecute(ds.icd, ds.dstE, ds.dstM, ds.srcA, ds.srcB, ds.valP, ds.PC)

}
