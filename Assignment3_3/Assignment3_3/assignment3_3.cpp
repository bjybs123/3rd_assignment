
#include <fstream>
#include "menu_node.h"
#include "bst_node.h"
#include <crtdbg.h>

void getName(char*tempName)
{
	int i = 0;
	char c;
	while (cin.get(c) && c != '\n')
	{
		tempName[i] = c;
		++i;
	}
	tempName[i] = '\0';
}

void FiletoData(Link* menu, BST* tree)
{
	ifstream fin("cafe_menu.txt");
	if (fin.fail())
	{
		cerr << "file can not be found\n";
		exit(100);
	}
	else
	{
		cout << "file opened\n";
	}

	char c;
	char* name = new char[100];
	int i = 0;
	int price;
	while (fin.get(c) && c != EOF)
	{
		if (c == ',')
		{
			name[i] = '\0';
			fin >> price;
			tree->insert(name, price);
			menu->insert(name, price);
			i = 0;
			price = 0;
		}
		else if (c == '\n');		//null statement
		else
		{
			name[i] = c;
			++i;
		}

	}

	delete[] name;

	fin.close();
}

int main()
{
	//_CrtSetBreakAlloc(257);
	int words = 0;
	BST tree;
	char* command = new char[100];
	Link menu;
	

	while (true)
	{
		cout << "Command list : LOAD, PRINT, INSERT, SEARCH, DELETE, EXIT\n";
		cout << "CMD>> ";
		cin >> command;
		
		if (strcmp(command, "LOAD") == 0)
		{

			FiletoData(&menu, &tree);
			cout << "load menu count : " << menu.getCount() << "\n";
			cout << "load tree count : " << tree.getCount() << "\n";
			words = menu.getCount();
			
		}
		else if (strcmp(command, "PRINT") == 0)
		{
			if (words == 0)
			{
				cout << "Cafe Menu is Empty\n";
				continue;
			}
			cout << "Command list: MENU, PRICE\n";
			cin >> command;
			if (strcmp(command, "MENU") == 0)
			{
				cout << "Print by Menu order\n";
				tree.Print_IN(tree.getRoot());
			}
			else if (strcmp(command, "PRICE") == 0)
			{
				cout << "Print by Price order\n";
				menu.print();
			}
		}
		else if (strcmp(command, "INSERT") == 0)
		{
			int price;
			cout << "Menu name : ";
			cin.get();
			getName(command);
			cout << "price : ";
			cin >> price;
			tree.insert(command, price);
			menu.insert(command, price);

			words = menu.getCount();
		}
		else if (strcmp(command, "SEARCH") == 0)
		{
			if (words == 0)
			{
				cout << "Cafe Menu is Empty\n";
				continue;
			}

			cout << "Menu name : ";
			cin.get();
			getName(command);
			menu.search(command);

		}
		else if (strcmp(command, "DELETE") == 0)
		{
			if (words == 0)
			{
				cout << "Cafe Menu is Empty\n";
				continue;
			}

			cin.get();
			getName(command);


			menu.delNode(command);
			tree.delNode(command);
			words = menu.getCount();

		}
		else if (strcmp(command, "EXIT") == 0)
		{
			break;
		}

	}

	delete[] command;


	return 0;
}