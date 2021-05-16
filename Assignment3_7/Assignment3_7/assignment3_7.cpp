#include <fstream>
#include "link.h"

template<typename Y>
void FiletoData(Link<Y>* link)
{
	ifstream fin("students.txt");
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
	int i = 0;
	char* tempID = new char[100];
	char* tempMajor = new char[100];
	char* tempName = new char[100];
	bool idIn = false;
	bool majorIn = false;
	while (fin.get(c))
	{
		
		if (c == ',')
		{
			if (idIn == false && majorIn == false)
			{
				tempID[i] = '\0';
				i = 0;
				idIn = true;
			}
			else if (idIn == true && majorIn == false)
			{
				tempMajor[i] = '\0';
				i = 0;
				majorIn = true;
			}
		}
		else if (c == '\n' && idIn == true && majorIn == true)
		{

			tempName[i] = '\0';
			link->insert_stu(tempID, tempMajor, tempName);

			i = 0;
			idIn = false;
			majorIn = false;
		}
		else if (c == '\n' && idIn == false && majorIn == false);	//처음 data가 들어오기 전 whitespace제거
		else
		{
			if (idIn == false)
			{
				tempID[i] = c;
			}
			else if (idIn == true && majorIn == false)
			{
				tempMajor[i] = c;
			}
			else if (idIn == true && majorIn == true)
			{
				tempName[i] = c;
			}
			++i;
		}
	}
	tempName[i] = '\0';
	link->insert_stu(tempID, tempMajor, tempName);

	delete[] tempID;
	delete[] tempMajor;
	delete[] tempName;
	fin.close();
}

int main()
{
	Link<int>* Input = new Link<int>();			//linked list that listed by input order
	FiletoData(Input);

	char* command = new char[100];

	cout << "1. Print File\n";
	cout << "2. Print by ID\n";
	cout << "3. Print by Major\n";
	cout << "4. Print by Name\n";
	cout << "5. Program END\n";
	cout << "CMD>> ";
	cin >> command;


	Input->print();




	delete[] command;
	return 0;
}