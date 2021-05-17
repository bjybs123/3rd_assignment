#pragma once

#include <iostream>
using namespace std;

void my_strcpy(char* str1, char* str2)
{
	int i = 0;
	while ((str1[i] = str2[i++]) != '\0');
	str1[i] = '\0';

	return;
}
class student_node
{
private:
	char* ID;
	char* major;
	char* name;
	student_node* pNext;
	student_node* yearNext;
	student_node* majorNext;
	student_node* alphaNext;

public:
	student_node()
	{
		ID = new char[100];
		major = new char[100];
		name = new char[100];
		pNext = nullptr;
		yearNext = nullptr;
		majorNext = nullptr;
		alphaNext = nullptr;
	}
	student_node(char* idIn, char* majorIn, char* nameIn)
	{
		ID = new char[100];
		major = new char[100];
		name = new char[100];
		pNext = nullptr;
		yearNext = nullptr;
		majorNext = nullptr;
		alphaNext = nullptr;

		my_strcpy(ID, idIn);
		my_strcpy(major, majorIn);
		my_strcpy(name, nameIn);
	}
	~student_node()
	{
		delete[] ID;
		delete[] major;
		delete[] name;
	}
	char* getID()
	{
		return ID;
	}
	char* getMajor()
	{
		return major;
	}
	char* getName()
	{
		return name;
	}
	void setID(char* idIn)
	{
		int i = 0;
		while ((ID[i] = idIn[i]) != '\0')
		{
			++i;
		}
		ID[i] = '\0';
	}
	void setMajor(char* majorIn)
	{
		int i = 0;
		while ((major[i] = majorIn[i]) != '\0')
		{
			++i;
		}
		major[i] = '\0';
	}
	void setName(char* nameIn)
	{
		int i = 0;
		while ((name[i] = nameIn[i]) != '\0')
		{
			++i;
		}
		name[i] = '\0';
	}
	student_node* getPnext()
	{
		return pNext;
	}
	student_node* getYearnext()
	{
		return yearNext;
	}
	student_node* getMajornext()
	{
		return majorNext;
	}
	student_node* getAlphanext()
	{
		return alphaNext;
	}
	void setPnext(student_node* nextIn)
	{
		pNext = nextIn;
	}
	void setYearnext(student_node* nextIn)
	{
		yearNext = nextIn;
	}
	void setMajornext(student_node* nextIn)
	{
		majorNext = nextIn;
	}
	void setAlphanext(student_node* nextIn)
	{
		alphaNext = nextIn;
	}

};