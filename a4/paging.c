
//
//  paging.c
//  A4
//
//  Created by Donald  Acton on 2017-09-30.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#include "main.h"
#include "paging.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// You must use this function to pagein a page from the
// backing store . The function takes the
// virtualPageNumber (not the virtual address) and reads the page in 
// from that location and puts it into the page location specified 
// by the physical page number. Access to the backing store (i.e. paging file)
// is through the file descriptor passed in the parameter bakingStorefd. 
// The size of the page is given in pageSize. (Hint pass in the the page size in bytes)
// The value returned is 1 if it worked and 0 if it failed. Note that one
// possible failure is the result of a read error, so be sure to check for
// that.

int numP = 0;

void initPageTable(int numPageEntry, int numPhysicalPage) {
	pageTable = malloc(sizeof(struct pageEntry) * numPageEntry);
	for(int i=0; i<numPageEntry; i++){
		pageTable[i].ppn = -1;
		pageTable[i].valid = 0;
	}
	physicalMemoryTable = malloc(sizeof(struct physicalEntry) * numPhysicalPage);
	for(int i=0; i<numPhysicalPage; i++){
		physicalMemoryTable[i].vpn = -1;
		physicalMemoryTable[i].time = -1;
	}
	numP = numPhysicalPage;
}

uint32_t findLRU(){
	int currentTime = 10000;
	uint32_t ppn = 0;
	for(int i=0; i<numP; i++){
		if(physicalMemoryTable[i].vpn != -1 && physicalMemoryTable[i].time < currentTime){
			currentTime = physicalMemoryTable[i].time;
			ppn = i;
		}
	}
	return ppn;
}

uint32_t findPPN(uint32_t vpn){
	if(pageTable[vpn].valid == 1)
		return pageTable[vpn].ppn;
	return -1;
}

int pagein(uint32_t virtualPageNumber,
	   uint32_t physicalPageNumber,
	   char * physicalMemoryStart,
	   uint32_t  pageSize,
	   int  backingStorefd ) {

	//uint32_t oldPPN = pageTable[virtualPageNumber].ppn;
	uint32_t oldVPN = physicalMemoryTable[physicalPageNumber].vpn;
	//printf("hi\n");
	if(oldVPN != -1)
		pageTable[oldVPN].valid = 0; 
	//printf("yi\n");
	lseek(backingStorefd, virtualPageNumber * (1<<pageSize), SEEK_SET);
	read(backingStorefd, physicalMemoryStart + physicalPageNumber * (1<<pageSize) ,1<<pageSize);

	pageTable[virtualPageNumber].ppn = physicalPageNumber;
	pageTable[virtualPageNumber].valid = 1;

	physicalMemoryTable[physicalPageNumber].vpn = virtualPageNumber;
  return 0;
}

