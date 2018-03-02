//
//  paging.h
//  A4
//
//  Created by Donald  Acton on 2017-09-30.
//  Copyright © 2017 Donald  Acton. All rights reserved.
//

#ifndef PAGING_H
#define PAGING_H 1
#include <sys/types.h>
#include <unistd.h>
#include <inttypes.h>

struct pageEntry{
	uint32_t ppn;
	int valid;
};

struct pageEntry * pageTable;

struct physicalEntry{
	uint32_t vpn;
	int time;
};

struct physicalEntry* physicalMemoryTable;

void initPageTable(int numPageEntry, int numPhysicalPage);

uint32_t findLRU();
uint32_t findPPN(uint32_t vpn);

int pagein(uint32_t virtualPageNumber,
	   uint32_t physicalPageNumber,
	   char * physicalMemoryStart,
	   uint32_t  pageSize,
	   int  backingStorefd);

// You probably want to add structure definitions for page table entries and for
// tracking physical page usage along with functions to do things like:
// * initialize the paging system
// * check to see if a virtual page is mapped in and at what location
// * locate the page to to replace


#endif
