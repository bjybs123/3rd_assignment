#pragma once
#include "horse.h"
#include "board.h"

#define RIGHTUP 6
#define LEFTUP 11


class block
{
private:
	int nodeNumber;
	block* pNext;
	block* pPrev;
	block* pShortcut;
	horse* pOn;
public:
	block();
	block(int numberIn);
	int getNodeNumber();
	void setNodeNumber(int numberIn);
	block* getpNext();
	void setpNext(block*);
	block* getpPrev();
	void setpPrev(block*);
	block* getpShortcut();
	void setpShortcut(block*);
	horse* getpOn();
	void setpOn(horse*);

};

