#pragma once
class block;
#include "move.h"

class horse
{
private:
	bool isCarried;
	bool goal;
	bool live;
	char* horseName;
	horse* pNext;
	horse* pCarry;
	block* pPos;

public:
	horse();
	~horse();
	horse(const char*);
	bool getLive();
	void dead();
	bool getGoal();
	void setGoal(bool);
	char* getHorseName();
	horse* getpNext();
	void setpNext(horse*);
	horse* getpCarry();
	void setpCarry(horse*);
	block* getpPos();
	void setpPos(block*);
	void printYut();
	void setCarried();
	bool ifCarried();
};

