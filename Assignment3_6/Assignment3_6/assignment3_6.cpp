
#include "block.h"



void printHorse(horse* yut1, horse* yut2, horse* yut3, horse* yut4)
{
	int i = 1;
	if (yut1->getGoal() == true || yut1->getLive() == false || yut1->ifCarried() == true);
	else if (yut1->getpPos() == NULL)
	{
		cout << i << ". Hand";
		++i;
	}
	else
	{
		cout << i << ". " << yut1->getHorseName();
		++i;
	}
	if (yut2->getGoal() == true || yut2->getLive() == false || yut2->ifCarried() == true);
	else if (yut2->getpPos() == NULL)
	{
		cout << "\t" << i << ". Hand";
		++i;
	}
	else
	{
		cout << "\t" << i << ". " << yut2->getHorseName();
		++i;
	}

	if (yut3->getGoal() == true || yut3->getLive() == false || yut3->ifCarried() == true);
	else if (yut3->getpPos() == NULL)
	{
		cout << "\t" << i << ". Hand";
		++i;
	}
	else
	{
		cout << "\t" << i << ". " << yut3->getHorseName();
		++i;
	}

	if (yut4->getGoal() == true || yut4->getLive() == false || yut4->ifCarried() == true);
	else if (yut4->getpPos() == NULL)
	{
		cout << "\t" << i << ". Hand";
		++i;
	}
	else
	{
		cout << "\t" << i << ". " << yut4->getHorseName();
		++i;
	}
	cout << "\n";

}
horse* selectHorse(horse* yut1, horse* yut2, horse* yut3, horse* yut4, int numIn)
{
	int i = 0;
	horse** yutArray = new horse *[4];
	for (i = 0; i < 4; ++i)
		yutArray[i] = new horse;
	
	yutArray[0] = yut1;
	yutArray[1] = yut2;
	yutArray[2] = yut3;
	yutArray[3] = yut4;

	int index = 1;
	for (i = 0; i < 4; ++i)
	{
		if (yutArray[i]->getGoal() == true || yutArray[i]->ifCarried() == true)
		{
			continue;
		}
		else
		{
			if (index == numIn)
				return yutArray[i];
			++index;
		}
	}

}

int main()
{

	int yutCount = 0;
	char* command = new char[100];
	board* Gboard = new board();
	moveLink* moves = new moveLink();

	horse* yut1 = new horse("A1");
	horse* yut2 = new horse("A2");
	horse* yut3 = new horse("A3");
	horse* yut4 = new horse("A4");

	horse* yut5 = new horse("B1");
	horse* yut6 = new horse("B2");
	horse* yut7 = new horse("B3");
	horse* yut8 = new horse("B4");

	Gboard->initial();
	Gboard->printBoard();



	
	while (true)
	{
		while (true)
		{
			cout << "Player 1 turn!throw/exit)\n";
			cout << "CMD>> ";
			cin >> command;

			if (strcmp(command, "throw") == 0)
			{
				int result;
				result = moves->throwYut();
				++yutCount;
				moves->insert(result);
				moves->movesIncrement();
				cout << "moves : " << result << "\n";

				//다시 할지 안할지
				if (result == 4 || result == 5)
				{
					cout << "Throw again!\n";
					continue;
				}
				_move* checking = moves->getHead();
				cout << "Yut Results : ";



				//고르기
				while (yutCount)
				{
					moves->printMoves(yutCount);

					cout << "\n";
					char c;
					horse* selectedHorse;
					char selHorse;
					char selmove;
					cout << "Select move : ";
					cin >> selmove;
					selmove -= 48;
					if (selmove <= yutCount && selmove > 0)
					{
						cout << "good\n";
					}
					else
					{
						cout << "invaild input\n";
						while (cin.get(c) && c != '\n');
						continue;
					}
					printHorse(yut1, yut2, yut3, yut4);
					cout << "Selecet horse : ";
					cin >> selHorse;
					selHorse -= 48;
					int yuts = 0;
					if (yut1->getGoal() == false && yut1->ifCarried() == false)
						++yuts;
					if (yut2->getGoal() == false && yut2->ifCarried() == false)
						++yuts;
					if (yut3->getGoal() == false && yut3->ifCarried() == false)
						++yuts;
					if (yut4->getGoal() == false && yut4->ifCarried() == false)
						++yuts;

					if (selHorse > yuts || selHorse < 0)
					{
						cout << "invaild input\n";
						while (cin.get(c) && c != '\n');
						continue;
					}
					selectedHorse = selectHorse(yut1, yut2, yut3, yut4, selHorse);

					//backDo should be covered
					Gboard->moveYut(selectedHorse, moves, yutCount, selmove, selectedHorse->getBack());

					cout << "yut1 back is : " << yut1->getBack() << "\n";
					cout << "yut2 back is : " << yut2->getBack() << "\n";
					cout << "yut3 back is : " << yut3->getBack() << "\n";
					cout << "yut4 back is : " << yut4->getBack() << "\n";
					Gboard->printBoard();
					--yutCount;
				}
				moves->clear();
				yutCount = 0;
				break;
			}
			else if (strcmp(command, "exit") == 0)
			{
				return 0;
			}
		}
		/// ///////////////////////////////////////////////////////////////////////////////////
		while (true)
		{
			cout << "Player 2 turn!throw/exit)\n";
			cout << "CMD>> ";
			cin >> command;

			if (strcmp(command, "throw") == 0)
			{
				int result = moves->throwYut();
				++yutCount;
				moves->insert(result);
				moves->movesIncrement();
				cout << "moves : " << result << "\n";

				//다시 할지 안할지
				if (result == 4 || result == 5)
				{
					cout << "Throw again!\n";
					continue;
				}
				_move* checking = moves->getHead();
				cout << "Yut Results : ";



				//고르기
				while (yutCount)
				{
					moves->printMoves(yutCount);

					cout << "\n";
					char c;
					horse* selectedHorse;
					char selHorse;
					char selmove;
					cout << "Select move : ";
					cin >> selmove;
					selmove -= 48;
					if (selmove <= yutCount && selmove > 0)
					{
						cout << "good\n";
					}
					else
					{
						cout << "invaild input\n";
						while (cin.get(c) && c != '\n');
						continue;
					}
					printHorse(yut5, yut6, yut7, yut7);
					cout << "Selecet horse : ";
					cin >> selHorse;
					selHorse -= 48;
					int yuts = 0;
					if (yut5->getGoal() == false && yut5->ifCarried() == false)
						++yuts;
					if (yut6->getGoal() == false && yut6->ifCarried() == false)
						++yuts;
					if (yut7->getGoal() == false && yut7->ifCarried() == false)
						++yuts;
					if (yut8->getGoal() == false && yut8->ifCarried() == false)
						++yuts;

					if (selHorse > yuts || selHorse < 0)
					{
						cout << "invaild input\n";
						while (cin.get(c) && c != '\n');
						continue;
					}
					selectedHorse = selectHorse(yut5, yut6, yut7, yut8, selHorse);

					//backDo should be covered
					Gboard->moveYut(selectedHorse, moves, yutCount, selmove, selectedHorse->getBack());

					cout << "yut5 back is : " << yut5->getBack() << "\n";
					cout << "yut6 back is : " << yut6->getBack() << "\n";
					cout << "yut7 back is : " << yut7->getBack() << "\n";
					cout << "yut8 back is : " << yut8->getBack() << "\n";
					Gboard->printBoard();
					--yutCount;
				}
				moves->clear();
				yutCount = 0;
				break;
			}
			else if (strcmp(command, "exit") == 0)
			{
				return 0;
			}
		}
		if (yut1->getGoal() == true && yut2->getGoal() == true && yut3->getGoal() == true && yut4->getGoal() == true)
		{
			cout << "player 1 win..\n";
			return 0;
		}
		else if (yut1->getLive() == false && yut2->getLive() == false && yut3->getLive() == false && yut4->getLive() == false)
		{
			cout << "player 2 win..\n";
			return 0;
		}
		if (yut5->getGoal() == true && yut6->getGoal() == true && yut7->getGoal() == true && yut8->getGoal() == true)
		{
			cout << "player 2 win..\n";
			return 0;
		}
		else if (yut5->getLive() == false && yut6->getLive() == false && yut7->getLive() == false && yut8->getLive() == false)
		{
			cout << "player 1 win..\n";
			return 0;
		}
	}

	cout << "fin";
	return 0;
}


