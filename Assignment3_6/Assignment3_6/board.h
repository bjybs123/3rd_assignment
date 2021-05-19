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
	void goYut(horse*, int);
	void printNode(int);
	void printBoard();
};