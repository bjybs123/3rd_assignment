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
	block* outerNode = nullptr;

	while (numberCount <= 30)
	{
		
		block* movingNode = pHead;
		block* newNode = new block(numberCount);
		
		if (numberCount == 6)
			rightCorner = newNode;			//오른쪽 코너 위치 저장
		else if (numberCount == 11)
			leftCorner = newNode;			//왼쪽 코너 위치 저장
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
				}
				else if (movingNode->getpNext() == nullptr && numberCount <= 20)
				{
					newNode->setpPrev(movingNode);
					movingNode->setpNext(newNode);
					if (numberCount == 20)
						outerNode = newNode;
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
				cout << "ㅇ";
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
	block* originLeft = left;
	block* originRight = right;

	if (right->getNodeNumber() == nodeNum)
	{
		if (right->getpOn() == nullptr)
		{
			cout << "ㅇ";
		}
		else
			right->getpOn()->printYut();						//print mal
		return;
	}
	else if (left->getNodeNumber() == nodeNum)
	{
		if (left->getpOn() == nullptr)
		{
			cout << "ㅇ";
		}
		else
			left->getpOn()->printYut();						//print mal
		return;
	}
	else if (nodeNum >= 21 && nodeNum <= 25)
	{
		right = right->getpShortcut();
		while (right)
		{
			if (right->getNodeNumber() == nodeNum)
			{
				if (right->getpOn() == nullptr)
				{
					cout << "ㅇ";
				}
				else
					right->getpOn()->printYut();				//print mal
				return;
			}
			right = right->getpNext();
		}
	}
	else if (nodeNum >= 26 && nodeNum <= 30)
	{
		left = left->getpShortcut();
		while (left)
		{
			if (left->getNodeNumber() == nodeNum)
			{
				if (left->getpOn() == nullptr)
				{
					cout << "ㅇ";
				}
				else
					left->getpOn()->printYut();				//print mal
				return;
			}
			left = left->getpNext();
		}
	}
	else if (nodeNum == 99)
	{
		bool isSomething = false;
		left = originLeft;
		right = originRight;
		left = left->getpShortcut();
		while (left)
		{
			if (left->getNodeNumber() == leftCenter)
			{
				if (left->getpOn() != nullptr)
				{
					isSomething = true;
					left->getpOn()->printYut();
					break;
				}

			}
			left = left->getpNext();
		}

		right = right->getpShortcut();
		while (right)
		{
			if (right->getNodeNumber() == rightCenter)
			{
				if (right->getpOn() != nullptr)
				{
					isSomething = true;
					right->getpOn()->printYut();				//print mal
				}
				if (isSomething == false)
					cout << "ㅇ";
				return;
			}
			right = right->getpNext();
		}
		
	}
	
}
void board::printBoard()
{
	cout << "\n";
	int	gboard[7][7] = { {11, 10, 9, 0, 8, 7, 6},
						{12, 26, 0, 0, 0, 21, 5},
						{13, 0, 27, 0, 22, 0, 4},
						{0, 0, 0, 99, 0, 0, 0},		//99의 임의의 값으로 지정해준 후 함수 안에서 두개의 중앙을 처리
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
void board::goYut(horse* yut, int goes, int backDo)
{
	block* movingNode = pHead;
	if (goes == -1)
	{
		if (backDo == 1)
		{
			yut->getpPos()->setpOn(NULL);
			yut->setGoal(true);
			return;
		}
		//back이 원점일때
		
		while (movingNode)
		{
			block* leftNode = movingNode;
			block* rightNode = movingNode;
			if (leftNode->getNodeNumber() == LEFTUP)
			{
				leftNode = leftNode->getpShortcut();
				while (leftNode)
				{
					
					if (leftNode->getNodeNumber() == backDo)
					{
						movingNode = leftNode;
						break;
					}
					if (leftNode->getNodeNumber() == 30)
						break;
					leftNode = leftNode->getpNext();
				}
				

			}
			else if (rightNode->getNodeNumber() == RIGHTUP)
			{
				rightNode = rightNode->getpShortcut();
				while (rightNode)
				{
					if (rightNode->getNodeNumber() == 16)
						break;
					if (rightNode->getNodeNumber() == backDo)
					{
						movingNode = rightNode;
						break;
					}
					rightNode = rightNode->getpNext();
				}
				

			}
			if (movingNode->getNodeNumber() == backDo)
			{
				if (movingNode->getpOn() != nullptr)
				{
					if (movingNode->getpOn()->getHorseName()[0] != yut->getHorseName()[0])
					{
						yut->getpPos()->setpOn(NULL);
						movingNode->setpOn(yut);
						horse* tempHorse = movingNode->getpOn();
						while (tempHorse)
						{
							if (tempHorse->getpCarry() == nullptr)
							{

								tempHorse->setpPos(NULL);
								tempHorse->dead();
								break;
							}
							tempHorse = tempHorse->getpCarry();
						}
					}
					else if (movingNode->getpOn()->getHorseName()[0] == yut->getHorseName()[0])
					{
						horse* tempHorse = movingNode->getpOn();
						while (tempHorse)
						{
							if (tempHorse->getpCarry() == nullptr)
							{
								yut->getpPos()->setpOn(NULL);
								tempHorse->setpCarry(yut);
								break;
							}
							tempHorse = tempHorse->getpCarry();
						}
						yut->setCarried();
						yut->setpPos(NULL);
					}
				}
				else
				{
					yut->getpPos()->setpOn(NULL);
					movingNode->setpOn(yut);
					yut->setpPos(movingNode);
					break;
				}
			}
			movingNode = movingNode->getpNext();
		}
		return;
	}
	

	horse* goalNode = yut;
	horse* tempHorse = nullptr;
	movingNode = pHead;
	//만약 윳이 판에 위치한다면
	if (yut->getpPos() != NULL)
	{
		movingNode = yut->getpPos();
		movingNode->setpOn(NULL);
		//만약 윷이 판에 위치하고 좌측 코너 혹은 우측 코너에 위치할 경우
		if (yut->getpPos()->getNodeNumber() == RIGHTUP || yut->getpPos()->getNodeNumber() == LEFTUP)
		{
			--goes;						//움직일 수 잇는 위치를 하나 줄이고 
			yut->setBack(movingNode->getNodeNumber());		//전 값을 백도 블록에 저장한다.
			movingNode = movingNode->getpShortcut(); //지름길으로 한칸 이동
		}
	}
	//윷이 판 위에 존재할 경우 나머지 무브를 이동시킨다
	if (yut->getpPos() != NULL)
	{
		if (yut->getpPos()->getNodeNumber() == rightCenter)				//윷이 오른쪽 링크의 중앙에 위치했을때 지름길을 이용하기위해 왼쪽 중앙에 위치시킨다.
		{
			yut->getpPos()->setpOn(NULL);
			movingNode = pHead;
			while (movingNode)
			{
				if (movingNode->getNodeNumber() == LEFTUP)
				{
					movingNode = movingNode->getpShortcut();
				}
				if (movingNode->getNodeNumber() == leftCenter)
				{
					if (movingNode->getpOn())
					{
						if (movingNode->getpOn()->getHorseName()[0] != yut->getHorseName()[0])
						{
							movingNode->setpOn(NULL);
							horse* tempHorse = movingNode->getpOn();
							while (tempHorse)
							{
								if (tempHorse->getpCarry() == nullptr)
								{
									tempHorse->setpPos(NULL);
									tempHorse->dead();
									break;
								}
								tempHorse = tempHorse->getpCarry();
							}
						}
						else if (movingNode->getpOn()->getHorseName()[0] == yut->getHorseName()[0])
						{
							horse* tempHorse = movingNode->getpOn();
							while (tempHorse)
							{
								if (tempHorse->getpCarry() == nullptr)
								{
									tempHorse->setpCarry(yut);
									break;
								}
								tempHorse = tempHorse->getpCarry();
							}
							yut->setCarried();
							yut->setpPos(NULL);
						}
					}
					else
					{
						
						movingNode->setpOn(yut);
						yut->setpPos(movingNode);
					}
					break;
				}
				yut->setBack(movingNode->getNodeNumber());
				movingNode = movingNode->getpNext();
			}
		}
		while (movingNode && goes)
		{
			if (movingNode->getpNext() == nullptr)
			{
				cout << "go out\n";
				yut->getpPos()->setpOn(NULL);
				yut->setpPos(NULL);
				yut->setGoal(true);
				while (goalNode)
				{
					goalNode->setGoal(true);
					if (goalNode->getpCarry() == nullptr)
					{
						break;
					}
					goalNode = goalNode->getpCarry();
				}
				return;
			}
			yut->setBack(movingNode->getNodeNumber());
			movingNode = movingNode->getpNext();
			--goes;
		}
		//jkhhkh
		if (movingNode->getpOn())
		{
			//중앙일때
			if (movingNode->getpOn()->getHorseName()[0] != yut->getHorseName()[0])
			{
				movingNode->setpOn(NULL);
				horse* tempHorse = movingNode->getpOn();
				while (tempHorse)
				{
					if (tempHorse->getpCarry() == nullptr)
					{
						tempHorse->setpPos(NULL);
						tempHorse->dead();
						break;
					}
					tempHorse = tempHorse->getpCarry();
				}
			}
			else if (movingNode->getpOn()->getHorseName()[0] == yut->getHorseName()[0])
			{
				horse* tempHorse = movingNode->getpOn();
				while (tempHorse)
				{
					if (tempHorse->getpCarry() == nullptr)
					{
						tempHorse->setpCarry(yut);
						break;
					}
					tempHorse = tempHorse->getpCarry();
				}
				yut->setCarried();
				yut->setpPos(NULL);
			}
		}
		else
		{
			if (movingNode->getNodeNumber() == rightCenter)				//윷이 오른쪽 링크의 중앙에 위치했을때 지름길을 이용하기위해 왼쪽 중앙에 위치시킨다.
			{
				yut->getpPos()->setpOn(NULL);
				movingNode = pHead;
				while (movingNode)
				{
					if (movingNode->getNodeNumber() == LEFTUP)
					{
						movingNode = movingNode->getpShortcut();
					}
					if (movingNode->getNodeNumber() == leftCenter)
					{
						if (movingNode->getpOn() != nullptr)
						{
							if (movingNode->getpOn()->getHorseName()[0] != yut->getHorseName()[0])
							{
								movingNode->setpOn(NULL);
								horse* tempHorse = movingNode->getpOn();
								while (tempHorse)
								{
									if (tempHorse->getpCarry() == nullptr)
									{
										tempHorse->setpPos(NULL);
										tempHorse->dead();
										break;
									}
									tempHorse = tempHorse->getpCarry();
								}
							}
							else if (movingNode->getpOn()->getHorseName()[0] == yut->getHorseName()[0])
							{
								horse* tempHorse = movingNode->getpOn();
								while (tempHorse)
								{
									if (tempHorse->getpCarry() == nullptr)
									{
										tempHorse->setpCarry(yut);
										break;
									}
									tempHorse = tempHorse->getpCarry();
								}
								yut->setCarried();
								yut->setpPos(NULL);
							}
						}
						else
						{
							movingNode->setpOn(yut);
							yut->setpPos(movingNode);
						}
						break;
					}
					movingNode = movingNode->getpNext();
				}
			}
			movingNode->setpOn(yut);
			yut->setpPos(movingNode);
		}
	}
	else
	{
		while (movingNode && goes)
		{
			yut->setBack(movingNode->getNodeNumber());
			movingNode = movingNode->getpNext();
			--goes;
		}
		if (movingNode->getpOn())
		{
			if (movingNode->getpOn()->getHorseName()[0] != yut->getHorseName()[0])
			{
				movingNode->setpOn(NULL);
				horse* tempHorse = movingNode->getpOn();
				while (tempHorse)
				{
					if (tempHorse->getpCarry() == nullptr)
					{
						tempHorse->setpPos(NULL);
						tempHorse->dead();
						break;
					}
					tempHorse = tempHorse->getpCarry();
				}
			}
			else if (movingNode->getpOn()->getHorseName()[0] == yut->getHorseName()[0])
			{
				horse* tempHorse = movingNode->getpOn();
				while (tempHorse)
				{
					if (tempHorse->getpCarry() == nullptr)
					{
						tempHorse->setpCarry(yut);
						break;
					}
					tempHorse = tempHorse->getpCarry();
				}
				yut->setCarried();
				yut->setpPos(NULL);
			}
		}
		else
		{
			movingNode->setpOn(yut);
			yut->setpPos(movingNode);
		}
	}

}
void board::moveYut(horse* selectedHorse, moveLink* moves, int yutCount, int selMove, int backDo)
{
	
	if (yutCount > 1)
	{
		while (yutCount > 0)
		{
			_move* movingNode = moves->getHead();
			while (movingNode)
			{
				--selMove;
				if (selMove == 0 && selectedHorse->getGoal() != true)
				{
					goYut(selectedHorse, movingNode->getStep(), backDo);
					moves->delMove(movingNode->getStep());
					return;
				}
				movingNode = movingNode->getpNext();
			}
			--yutCount;
		}
	}
	else
	{
		if (selectedHorse->getGoal() != true)
		{
			goYut(selectedHorse, moves->getHead()->getStep(), backDo);
		}
		yutCount = 0;
	}
	
}