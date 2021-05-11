#include "link.h"
#include <crtdbg.h>
int main()
{
	Link revolver;

	revolver.initial();
	revolver.rotate();

	char* command = new char[100];
	cout << "Command list(shoot/rotate)\n";
	while (true)
	{
		cout << "CMD>> ";
		cin >> command;

		if (strcmp(command, "shoot") == 0)
		{
			if (revolver.getHead()->getBullet() == true)
			{
				cout << "You Died....\n";
				break;
			}
			else
			{
				cout << "You Survived!\n";
			}
			cout << "buller : " << revolver.getHead()->getBullet() << "\n";
			revolver.goNext();
		}
		else if (strcmp(command, "rotate") == 0)
		{
			revolver.clean();
			revolver.rotate();
			system("cls");
			
			revolver.print();
			cout << "Command list(shoot/rotate)\n";
		}
		else
		{
			cout << "Wrong Command!\n";
		}
	}

	delete[] command;

	return 0;
}