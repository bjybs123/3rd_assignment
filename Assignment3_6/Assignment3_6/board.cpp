#include "board.h"

block* board::setpHead()
{
	return pHead;
}
void board::setpHead(block* headIn)
{
	pHead = headIn;
}
void board::initial()
{
	int numberCount = 1;
	block* rightCorner = nullptr;
	block* leftCorner = nullptr;
	block* startNode = nullptr;
	block* leftDownCorner = nullptr;
	while (numberCount <= 30)
	{
		
		block* movingNode = pHead;
		block* newNode = new block(numberCount);

		
		if (numberCount == 6)
			rightCorner = newNode;			//������ �ڳ� ��ġ ����
		else if (numberCount == 11)
			leftCorner = newNode;			//���� �ڳ� ��ġ ����
		else if (numberCount == 1)
			startNode = newNode;
		else if (numberCount == 16)
			leftDownCorner = newNode;

		if (pHead == nullptr)
		{
			pHead = newNode;
		}
		else
		{
			while (movingNode)
			{
				if (movingNode->getNodeNumber() == 6 && numberCount >= 21)
				{
					block* prevNode = rightCorner;
					block* movingNode = rightCorner;
					
					while (numberCount <= 25)
					{
						block* newNode = new block(numberCount);
						while (movingNode)
						{
							if (movingNode->getpShortcut() == nullptr && numberCount == 21)
							{
								newNode->setpPrev(movingNode);
								movingNode->setpShortcut(newNode);
								prevNode = newNode;
								movingNode = movingNode->getpShortcut();
								break;
							}
							else if (movingNode->getpNext() == nullptr)
							{
								newNode->setpPrev(newNode);
								movingNode->setpNext(newNode);
								prevNode = newNode;
								movingNode = movingNode->getpNext();
								break;
							}

						}
						++numberCount;
					}
					movingNode->setpNext(leftDownCorner);
				}
				else if (movingNode->getNodeNumber() == 11 && numberCount >= 26)
				{
					block* prevNode = leftCorner;
					block* movingNode = leftCorner;

					while (numberCount <= 30)
					{
						block* newNode = new block(numberCount);
						while (movingNode)
						{
							if (movingNode->getpShortcut() == nullptr && numberCount == 26)
							{
								newNode->setpPrev(movingNode);
								movingNode->setpShortcut(newNode);
								prevNode = newNode;
								movingNode = movingNode->getpShortcut();
								break;
							}
							else if (movingNode->getpNext() == nullptr)
							{
								newNode->setpPrev(newNode);
								movingNode->setpNext(newNode);
								prevNode = newNode;
								movingNode = movingNode->getpNext();
								break;
							}

						}
						++numberCount;
					}
					movingNode->setpNext(startNode);
				}
				else if (movingNode->getpNext() == nullptr && numberCount <= 20)
				{
					newNode->setpPrev(movingNode);
					movingNode->setpNext(newNode);
					break;
				}
				movingNode = movingNode->getpNext();
			}
		}
		++numberCount;
	}
}
void board::printNode(int nodeNum)
{
	block* right =  nullptr;
	block* left = nullptr;
	block* movingNode = pHead;
	
	while (movingNode)
	{
		if (movingNode->getNodeNumber() == nodeNum)
		{
			if (movingNode->getpOn() == nullptr)
			{
				cout << "��";
			}
			else
				movingNode->getpOn()->printYut();						//print mal
			return;
		}
		movingNode = movingNode->getpNext();
	}

	movingNode = pHead;
	while (movingNode)
	{
		if (movingNode->getNodeNumber() == RIGHTUP)
			right = movingNode;
		else if (movingNode->getNodeNumber() == LEFTUP)
			left = movingNode;
		movingNode = movingNode->getpNext();
	}

	if (right->getpShortcut()->getNodeNumber() == nodeNum)
	{
		if (right->getpShortcut()->getpOn() == nullptr)
		{
			cout << "��";
		}
		else
			right->getpOn()->printYut();						//print mal
		return;
	}
	else
	{
		right = right->getpShortcut();
		while (right)
		{
			if (right->getNodeNumber() == nodeNum)
			{
				if (right->getpOn() == nullptr)
				{
					cout << "��";
				}
				else
					right->getpOn()->printYut();						//print mal
				return;
			}
			right = right->getpNext();
		}
	}

	if (left->getpShortcut()->getNodeNumber() == nodeNum)
	{
		if (left->getpShortcut()->getpOn() == nullptr)
		{
			cout << "��";
		}
		else
			left->getpOn()->printYut();						//print mal
		return;
	}
	else
	{
		left = left->getpShortcut();
		while (left)
		{
			if (left->getNodeNumber() == nodeNum)
			{
				if (left->getpOn() == nullptr)
				{
					cout << "��";
				}
				else
					left->getpOn()->printYut();				//print mal
				return;
			}
			left = left->getpNext();
		}
	}
}
void board::printBoard()
{
	cout << "\n";
	int	gboard[7][7] = { {11, 10, 9, 0, 8, 7, 6},
						{12, 26, 0, 0, 0, 21, 5},
						{13, 0, 27, 0, 22, 0, 4},
						{0, 0, 0, 28, 0, 0, 0},
						{14, 0, 24, 0, 29, 0, 3},
						{15, 25, 0, 0, 0, 30, 2},
						{16, 17, 18, 0, 19, 20, 1} };
	int i, j;
	for (i = 0; i < 7; ++i)
	{
		for (j = 0; j < 7; ++j)
		{
			printNode(gboard[i][j]);
			cout << "\t";
		}
		cout << "\n";
	}
	cout << "\n";
}
void board::goYut(horse* yut, int go)
{
	block* movingNode = pHead;
	if (yut->getpPos() != NULL)
	{
		movingNode = yut->getpPos();
		movingNode->setpOn(NULL);
		if (yut->getpPos()->getNodeNumber() == RIGHTUP || yut->getpPos()->getNodeNumber() == LEFTUP)
		{
			--go;
			movingNode = movingNode->getpShortcut();
		}
	}

	if (yut->getpPos() != NULL)
	{
		while (movingNode && go)
		{
			movingNode = movingNode->getpNext();
			--go;
		}
		movingNode->setpOn(yut);
		yut->setpPos(movingNode);
	}
	else
	{
		--go;
		while (movingNode && go)
		{
			movingNode = movingNode->getpNext();
			--go;
		}
		movingNode->setpOn(yut);
		yut->setpPos(movingNode);
	}

	
}