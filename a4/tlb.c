
//
//  tlb.c
//  A4
//
//  Created by Donald  Acton on 2017-09-30.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//
#include "tlb.h"

// The following are a few hints to get you going. Feel free
// to change names, to add more functions, to change parameter types,
// to change the number of parameters, to change the return value, or to
// not use any of these functions at all. 
// 

int numtlbEntry = 16;

// Add code here to implement the TLB functionality
void TLBinit(uint32_t pageSize) {
	
	tlbTable = malloc(sizeof(struct tlbEntry) * numtlbEntry);
	for(int i = 0; i< numtlbEntry; i++){
		tlbTable[i].valid = 0;
	}
}

// Check to see if the virtual page number is in the in the TLB
// If it is return the physical page number otherwise return TLBFAULT;
uint32_t checkTLB(int accessCnt, uint32_t virtualPageNumber) {
	//int index = virtualPageNumber & 0xF; //last 4 digit is index
	int tag = virtualPageNumber; //& 0xF0; 

	for(int i = 0; i< numtlbEntry; i++){
		if(tlbTable[i].valid && tlbTable[i].tag == tag){
			tlbTable[i].accessTime = accessCnt;
			return tlbTable[i].ppn;
		}
	}
  return TLBFAULT;
}


// Add this mapping to the TLB
void updateTLB(int accessCnt, uint32_t virtualPageNumber, 
	       uint32_t physicalPageNumber) {
	//int index = virtualPageNumber & 0xF; //last 4 digit is index
	int tag = virtualPageNumber; // & 0xF0; rest is tag

	for(int i = 0; i < numtlbEntry; i++){
		if(tlbTable[i].valid == 0){
			tlbTable[i].valid = 1;
	 		//tlbTable[i].index = index;
			tlbTable[i].tag = tag;
			tlbTable[i].ppn = physicalPageNumber;
			tlbTable[i].accessTime = accessCnt;
			return;
		}
	}

	//if we used up all invalid entries, we will choose LRU one
	int currentTime = 10000;
	int lruIndex = -1;
	for(int i = 0; i < numtlbEntry; i++){
		if(tlbTable[i].accessTime < currentTime){
			currentTime = tlbTable[i].accessTime;
			lruIndex = i;
		}
	}

	tlbTable[lruIndex].valid = 1;
	//tlbTable[lruIndex].index = index;
	tlbTable[lruIndex].tag = tag;
	tlbTable[lruIndex].ppn = physicalPageNumber;
	tlbTable[lruIndex].accessTime = accessCnt;
	return;
}

//remove this maping to tlb

void removeTLB(uint32_t physicalPageNumber){
	for(int i = 0; i < numtlbEntry; i++){
		if(tlbTable[i].ppn == physicalPageNumber){
			tlbTable[i].valid = 0;
		}
	}
}




