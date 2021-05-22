#pragma once
#include "block.h"
class board
{
private:
	block* pHead;

public:
	block* setpHead();
	void setpHead(block* headIn);
	void initial();
	void goYut(horse*, int, int&);
	void printNode(int);
	void printBoard();
	void moveYut(horse*, moveLink*, int, int, int&);
};