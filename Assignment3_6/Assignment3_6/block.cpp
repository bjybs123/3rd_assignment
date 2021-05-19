#include "block.h"


//block's methods
block::block()
{
	nodeNumber = 0;
	pNext = nullptr;
	pPrev = nullptr;
	pShortcut = nullptr;
	pOn = nullptr;
}
block::block(int numberIn)
{
	nodeNumber = numberIn;
	pNext = nullptr;
	pPrev = nullptr;
	pShortcut = nullptr;
	pOn = nullptr;
}
int block::getNodeNumber()
{
	return nodeNumber;
}
void block::setNodeNumber(int numberIn)
{
	nodeNumber = numberIn;
}
block* block::getpNext()
{
	return pNext;
}
void block::setpNext(block* blockIn)
{
	pNext = blockIn;
}
block* block::getpPrev()
{
	return pPrev;
}
void block::setpPrev(block* blockIn)
{
	pPrev = blockIn;
}
block* block::getpShortcut()
{
	return pShortcut;
}
void block::setpShortcut(block* blockIn)
{
	pShortcut = blockIn;
}
horse* block::getpOn()
{
	return pOn;
}
void block::setpOn(horse* horseIn)
{
	pOn = horseIn;
}



