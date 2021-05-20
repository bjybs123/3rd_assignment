#include "horse.h"

//horse's methods
horse::horse()
{
	live = ALIVE;
	horseName = nullptr;
	pNext = nullptr;
	pCarry = nullptr;
	pPos = nullptr;
}
horse::horse(const char* nameIn)
{
	live = ALIVE;
	horseName = new char[10];
	int i = 0;
	while (nameIn[i] != '\0')
	{
		horseName[i] = nameIn[i];
		++i;
	}
	horseName[i] = '\0';
	pNext = nullptr;
	pCarry = nullptr;
	pPos = nullptr;
}
bool horse::getLive()
{
	return live;
}
void horse::dead()
{
	live = DEAD;
}
char* horse::getHorseName()
{
	return horseName;
}
horse* horse::getpNext()
{
	return pNext;
}
void horse::setpNext(horse* horseIn)
{
	pNext = horseIn;
}
horse* horse::getpCarry()
{
	return pCarry;
}
void horse::setpCarry(horse* horseIn)
{
	pCarry = horseIn;
}
block* horse::getpPos()
{
	return pPos;
}
void horse::setpPos(block* blockIn)
{
	pPos = blockIn;
}
void horse::printYut()
{
	cout << horseName;
}
