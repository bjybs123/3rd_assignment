#include <iostream>
#include <fstream>
#include "menu_node.h"
#include "bst_node.h"

using namespace std;

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
	int words = 0;
	char* command = new char[100];
	Link* menu = new Link();
	BST* tree = new BST();

	while (true)
	{
		cout << "Command list : LOAD, PRINT, INSERT, SEARCH, DELETE, EXIT\n";
		cout << "CMD>> ";
		cin >> command;
		
		if (strcmp(command, "LOAD") == 0)
		{
			FiletoData(menu, tree);
			cout << "load menu count : " << menu->getCount() << "\n";
			cout << "load tree count : " << tree->getCount() << "\n";
			words = menu->getCount();
		}
		else if (strcmp(command, "PRINT") == 0)
		{
			if (words == 0)
			{
				cout << "Cafe Menu is Empty\n";
				continue;
			}
			char* order = new char[100];
			cout << "Command list: MENU, PRICE\n";
			cin >> order;
			if (strcmp(order, "MENU") == 0)
			{
				cout << "Print by Menu order\n";
				tree->Print_IN(tree->getRoot());
			}
			else if (strcmp(order, "PRICE") == 0)
			{
				cout << "Print by Price order\n";
				menu->print();
			}
		}
		else if (strcmp(command, "INSERT") == 0)
		{
			char* tempName = new char[100];
			int price;
			cout << "Menu name : ";
			cin >> tempName;
			cout << "price : ";
			cin >> price;
			tree->insert(tempName, price);
			menu->insert(tempName, price);

			words = menu->getCount();
			delete[] tempName;
		}
		else if (strcmp(command, "SEARCH") == 0)
		{
			if (words == 0)
			{
				cout << "Cafe Menu is Empty\n";
				continue;
			}
			char* tempName = new char[100];
			cout << "Menu name : ";
			cin >> tempName;
			menu->search(tempName);
		}
		else if (strcmp(command, "DELETE") == 0)
		{
			if (words == 0)
			{
				cout << "Cafe Menu is Empty\n";
				continue;
			}
			char* tempName = new char[100];
			cout << "Menu name : ";
			cin >> tempName;
			menu->delNode(tempName);
			tree->delNode(tree->getRoot(), tempName);
			words = menu->getCount();
		}
		else if (strcmp(command, "EXIT") == 0)
		{
			exit(100);
		}

	}

	delete[] command;
}