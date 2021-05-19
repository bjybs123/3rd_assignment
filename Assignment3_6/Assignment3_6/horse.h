#pragma once
class block;
#include "move.h"


class horse
{
private:
	char* horseName;
	horse* pNext;
	horse* pCarry;
	block* pPos;

public:
	horse();
	horse(const char*);
	char* getHorseName();
	horse* getpNext();
	void setpNext(horse*);
	horse* getpCarry();
	void setpCarry(horse*);
	block* getpPos();
	void setpPos(block*);
	void printYut();
};

