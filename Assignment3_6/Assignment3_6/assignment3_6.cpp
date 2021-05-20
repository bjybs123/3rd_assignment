
#include "block.h"
void printHorse(horse* yut1, horse* yut2, horse* yut3, horse* yut4)
{
	if (yut1 == NULL)
	{
		cout << "1. Hand";
	}
	else
		cout << "1. " << yut1->getHorseName();
	if (yut2 == NULL)
	{
		cout << "\t2. Hand";
	}
	else
		cout << "\t2. " << yut2->getHorseName();
	if (yut3 == NULL)
	{
		cout << "\t. Hand";
	}
	else
		cout << "\t3. " << yut3->getHorseName();
	if (yut4 == NULL)
	{
		cout << "\t4. Hand";
	}
	else
		cout << "\t4. " << yut4->getHorseName();
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
			if(yutCount > 2)
				moves->insert(result);
			else
				moves->insert(result);
			cout << "moves : " << result << "\n";

			//�ٽ� ���� ������
			if (result == 4 || result == 5)
			{
				cout << "Throw again!\n";
				continue;
			}
			if (yutCount > 1)
			{
				_move* checking = moves->getHead();
				cout << "Yut Results : ";
				for (int i = 1; i <= yutCount && checking; ++i)
				{
					if (i > 1)
						cout << "\t";
					cout << i << ". ";
					cout << checking->getStep();
					checking = checking->getpNext();
				}
				cout << "\n";
			}
			else
			{
				_move* checking = moves->getHead();
				cout << "Yut Results : ";
				for (int i = 1; i <= yutCount && checking; ++i)
				{
					cout  << i << ". ";
					cout << checking->getStep();
					checking = checking->getpNext();
				}
				cout << "\n";
			}


			//������
			horse* selectedHorse;
			int selHorse;
			int selmove;
			cout << "Select move : ";
			cin >> selmove;
			cout << "Selecet horse : ";
			printHorse(yut1, yut2, yut3, yut4);
			cin >> selHorse;
			if (selHorse == 1 && yut1 == nullptr)
			{
				yut1 = new horse("A1");
			}
			if (selHorse == 2 && yut2 == nullptr)
			{
				yut2 = new horse("A2");
			}
			if (selHorse == 3 && yut3 == nullptr)
			{
				yut3 = new horse("A3");
			}
			if (selHorse == 4 && yut4 == nullptr)
			{
				yut4 = new horse("A4");
			}
			selectedHorse = selectHorse(yut1, yut2, yut3, yut4, selHorse);

			if (yutCount > 1)
			{
				while (yutCount > 0)
				{
					_move* movingNode = moves->getHead();
					while (movingNode)
					{
						--selHorse;
						if (!selHorse)
						{
							Gboard->goYut(selectedHorse, movingNode->getStep());
						}
						movingNode = movingNode->getpNext();
					}
					--yutCount;
				}
			}
			else
			{
				Gboard->goYut(selectedHorse, moves->getHead()->getStep());
				yutCount = 0;
			}
			moves->clear();
		}
		else if (strcmp(command, "exit") == 0)
		{
			break;
		}
		Gboard->printBoard();
	}

	cout << "fin";
	return 0;
}