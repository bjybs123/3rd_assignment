#pragma once


#include <iostream>
#include <ctime>
#include <cstdlib>
#define ALIVE true
#define DEAD false
#define leftCenter 28
#define rightCenter 23
using namespace std;
class _move
{
private:
	int step;
	_move* pNext;

public:
	_move();
	_move(int);
	int getStep();
	void setStep(int);
	_move* getpNext();
	void setpNext(_move*);
};



class moveLink
{
private:
	int moves;
	_move* pHead;

public:
	_move* getHead();
	int getMoves();
	void setMoves(int);
	void movesIncrement();
	void setHead(_move*);
	int throwYut();
	void insert(int moveNum);
	void clear();
};

