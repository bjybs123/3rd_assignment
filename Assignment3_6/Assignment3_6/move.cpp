#include "move.h"

//move's methods
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
	//yut1µŞ¸éÀÌ xÀÚ 
	//µµ 1, °³ 2, °É 3, À· 4, ¸ğ 5, µŞµµ 6
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
			return 6;
	}
}