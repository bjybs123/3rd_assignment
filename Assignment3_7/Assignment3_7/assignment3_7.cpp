#include <fstream>
#include "link.h"

void FiletoData(Link<int>* link, Link<int>* id, Link<char*>* major, Link<char>* name)
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
			student_node* newNode = new student_node(tempID, tempMajor, tempName);
			link->insert_stu(newNode);
			id->insert_2D(newNode);
			major->insert_2D(newNode);
			name->insert_2D(newNode);

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
	student_node* newNode = new student_node(tempID, tempMajor, tempName);
	link->insert_stu(newNode);
	major->insert_2D(newNode);
	id->insert_2D(newNode);
	name->insert_2D(newNode);

	delete[] tempID;
	delete[] tempMajor;
	delete[] tempName;
	fin.close();
}


int main()
{
	Link<int>* input = new Link<int>();			//linked list that listed by input order
	Link<int>* year = new Link<int>();			//linked list that listed by year order
	Link<char*>* major = new Link<char*>();			//linked list that listed by major order
	Link<char>* alpha = new Link<char>();			//linked list that listed by alpha order
	

	FiletoData(input, year, major, alpha);

	char* command = new char[100];

	cout << "1. Print File\n";
	cout << "2. Print by ID\n";
	cout << "3. Print by Major\n";
	cout << "4. Print by Name\n";
	cout << "5. Program END\n";
	cout << "CMD>> ";
	cin >> command;

	
	input->print();

	delete[] command;
	return 0;
}