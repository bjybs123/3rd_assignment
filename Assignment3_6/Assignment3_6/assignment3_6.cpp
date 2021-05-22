
#include "block.h"



void printHorse(horse* yut1, horse* yut2, horse* yut3, horse* yut4)
{
	int i = 1;
	if (yut1 == NULL)
	{
		cout << i << ". Hand";
		++i;
	}
	else if (yut1->getGoal() == true || yut1->getLive() == false);
	else
	{
		cout << i << ". " << yut1->getHorseName();
		++i;
	}

	if (yut2 == NULL)
	{
		cout << "\t" << i << ". Hand";
		++i;
	}
	else if (yut2->getGoal() == true || yut2->getLive() == false);
	else
	{
		cout << "\t" << i << ". " << yut2->getHorseName();
		++i;
	}

	if (yut3 == NULL)
	{
		cout << "\t" << i << ". Hand";
		++i;
	}
	else if (yut3->getGoal() == true || yut3->getLive() == false);
	else
	{
		cout << "\t" << i << ". " << yut3->getHorseName();
		++i;
	}

	if (yut4 == NULL)
	{
		cout << "\t" << i << ". Hand";
		++i;
	}
	else if (yut4->getGoal() == true || yut4->getLive() == false);
	else
	{
		cout << "\t" << i << ". " << yut4->getHorseName();
		++i;
	}
	cout << "\n";

}
horse* selectHorse(horse* yut1, horse* yut2, horse* yut3, horse* yut4, int numIn)
{
	if (yut1 != NULL && yut1->getLive() == DEAD)
		cout << "yut1 is dead\n";
	if (yut2 != NULL && yut2->getLive() == DEAD)
		cout << "yut2 is dead\n";
	if (yut3 != NULL && yut3->getLive() == DEAD)
		cout << "yut3 is dead\n";
	if (yut4 != NULL && yut4->getLive() == DEAD)
		cout << "yut4 is dead\n";

	if (yut1 != NULL && numIn == (yut1->getHorseName()[1] - 48))
	{
		return yut1;
	}
	else if (yut2 != NULL && numIn == (yut2->getHorseName()[1] - 48))
	{
		return yut2;
	}
	else if (yut3 != NULL && numIn == (yut3->getHorseName()[1] - 48))
	{
		return yut3;
	}
	else if (yut4 != NULL && numIn == (yut4->getHorseName()[1] - 48))
	{
		return yut4;
	}
}

int main()
{
	int yutCount = 0;
	char* command = new char[100];
	board* Gboard = new board();
	moveLink* moves = new moveLink();

	horse* yut1 = nullptr;
	horse* yut2 = nullptr;
	horse* yut3 = nullptr;
	horse* yut4 = nullptr;

	Gboard->initial();
	Gboard->printBoard();



	cout << "Player 1 turn!throw/exit)\n";
	while (true)
	{

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
				if (selHorse == 1 && yut1 == nullptr)
				{
					yut1 = new horse("A1");
				}
				else if (selHorse == 2 && yut2 == nullptr)
				{
					yut2 = new horse("A2");
				}
				else if (selHorse == 3 && yut3 == nullptr)
				{
					yut3 = new horse("A3");
				}
				else if (selHorse == 4 && yut4 == nullptr)
				{
					yut4 = new horse("A4");
				}
				if(selHorse  > 4 || selHorse < 0)
				{
					cout << "invaild input\n";
					while (cin.get(c) && c != '\n');
					continue;
				}
				selectedHorse = selectHorse(yut1, yut2, yut3, yut4, selHorse);

				//backDo should be covered
				Gboard->moveYut(selectedHorse, moves, yutCount, selmove);

				Gboard->printBoard();
				--yutCount;
			}
			moves->clear();
			yutCount = 0;
		}
		else if (strcmp(command, "exit") == 0)
		{
			break;
		}

	}

	cout << "fin";
	return 0;
}


