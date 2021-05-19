#pragma once


#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
class _move
{
private:
	int step;
	_move* pNext;

public:
	int getStep();
	void setStep(int);
	_move* getpNext();
	void setpNext(_move*);
};



class moveLink
{
private:
	_move* pHead;

public:
	_move* getHead();
	void setHead(_move*);
	int throwYut();
};

