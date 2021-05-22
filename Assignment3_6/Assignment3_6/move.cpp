#include "move.h"

//move's methods
_move::_move()
{
	step = 0;
	pNext = nullptr;
}
_move::_move(int stepNum)
{
	step = stepNum;
	pNext = nullptr;
}
int _move::getStep()
{
	return step;
}
void _move::setStep(int stepIn)
{
	step = stepIn;
}
_move* _move::getpNext()
{
	return pNext;
}
void _move::setpNext(_move* moveIn)
{
	pNext = moveIn;
}


//moveLink's methos
_move* moveLink::getHead()
{
	return pHead;
}
int moveLink::getMoves()
{
	return moves;
}
void moveLink::setMoves(int movesIn)
{
	moves = movesIn;
}
void moveLink::movesIncrement()
{
	++moves;
}
void moveLink::setHead(_move* moveIn)
{
	pHead = moveIn;
}
int moveLink::throwYut()
{
	bool yut1 = false;
	bool yut2 = false;
	bool yut3 = false;
	bool yut4 = false;

	srand((unsigned int)time(NULL));

	int number = rand() % 10;
	if (number >= 0 && number <= 5)
	{
		yut1 = true;
	}
	else
		yut1 = false;

	number = rand() % 10;
	if (number >= 0 && number <= 5)
	{
		yut2 = true;
	}
	else
		yut2 = false;

	number = rand() % 10;
	if (number >= 0 && number <= 5)
	{
		yut3 = true;
	}
	else
		yut3 = false;

	number = rand() % 10;
	if (number >= 0 && number <= 5)
	{
		yut4 = true;
	}
	else
		yut4 = false;
	//yut1µÞ¸éÀÌ xÀÚ 
	//µµ 1, °³ 2, °É 3, À· 4, ¸ð 5, µÞµµ -1
	if (yut1)
	{
		int count = 1;
		if (yut2)
			++count;
		if (yut3)
			++count;
		if (yut4)
			++count;

		if (count == 4)
			return 4;
		else if (count == 3)
			return 3;
		else if (count == 2)
			return 2;
		else if (count == 1)
			return 1;

	}
	else if (!yut1)
	{
		int count = 0;
		if (yut2)
			++count;
		if (yut3)
			++count;
		if (yut4)
			++count;

		if (count == 0)
			return 5;
		else if (count == 1)
			return 1;
		else if (count == 2)
			return 2;
		else if (count == 3)
			return -1;
	}
}

void moveLink::insert(int moveNum)
{
	_move* movingNode = pHead;
	_move* newMove = new _move(moveNum);
	if (pHead == nullptr)
	{
		pHead = newMove;
	}
	else
	{
		while (movingNode)
		{
			if (movingNode->getpNext() == nullptr)
			{
				movingNode->setpNext(newMove);
				break;
			}
			movingNode = movingNode->getpNext();
		}
	}

}
void moveLink::clear()
{
	_move* moving2 = pHead;
	_move* deleteNode;
	while (moving2 != nullptr)
	{
		deleteNode = moving2;
		moving2 = moving2->getpNext();
		delete deleteNode;
	}
	pHead = nullptr;
	setMoves(0);
	
}
void moveLink::delMove(int moveIn)
{
	_move* prevNode = NULL;
	_move* currNode = pHead;
	while (currNode && currNode->getStep() !=moveIn) {
		prevNode = currNode;
		currNode = currNode->getpNext();
	}
	if (currNode) {
		if (prevNode) {
			prevNode->setpNext(currNode->getpNext());
			delete currNode;
		}
		else {
			pHead = currNode->getpNext();
			delete currNode;
		}
	}
}
void moveLink::printMoves(int count)
{
	_move* checking = pHead;
	int i = 1;
	while (i <= count)
	{
		cout << i << ". ";
		cout << checking->getStep();
		cout << "\t";
		checking = checking->getpNext();
		++i;
	}
}