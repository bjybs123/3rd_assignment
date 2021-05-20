#pragma once
class block;
#include "move.h"

class horse
{
private:
	int live;
	char* horseName;
	horse* pNext;
	horse* pCarry;
	block* pPos;

public:
	horse();
	horse(const char*);
	bool getLive();
	void dead();
	char* getHorseName();
	horse* getpNext();
	void setpNext(horse*);
	horse* getpCarry();
	void setpCarry(horse*);
	block* getpPos();
	void setpPos(block*);
	void printYut();
};

