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

template<typename T>
int Compare(T a, T b)
{
	return a - b;
}

template<>
int Compare<char>(char c1, char c2)
{
	return c1 - c2;
}

template<>
int Compare<char*>(char* str1, char* str2)
{
	return strcmp(str1, str2);
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

template<typename T>
class node
{
private:
	T data;
	node* pNext;
	student_node* sNext;

public:

	node()
	{
		data = NULL;
		pNext = nullptr;
		sNext = nullptr;
	}
	node(T dataIn)
	{
		data = dataIn;
		pNext = nullptr;
		sNext = nullptr;
	}
	void setNext(node* nextIn)
	{
		pNext = nextIn;
	}
	node* getNext()
	{
		return pNext;
	}
	student_node* getSnext()
	{
		return sNext;
	}
	void setSnext(student_node* nextIn)
	{
		sNext = nextIn;
	}
	void print()
	{
		student_node* movingNode = sNext;
		while (movingNode)
		{
			cout << "id : " << movingNode->getID() << " major : " << movingNode->getMajor() << " name : " << movingNode->getName() << "\n";
			movingNode = movingNode->getPnext();
		}
	}

	

};

template<typename T>
class Link
{
private:
	student_node* stuHead;
	node<T>* lHead;

public:
	Link()
	{
		stuHead = nullptr;
		lHead = nullptr;
	}
	void addNode(T data)
	{
		node<T>* newNode = new node<T>;
	}
	void setstuHead(student_node* headIn)
	{
		stuHead = headIn;
	}
	student_node* getstuHead()
	{
		return stuHead;
	}
	node<T>* getlHead()
	{
		return lHead;
	}
	void setlHead(node<T>* headIn)
	{
		lHead = headIn;
	}
	void insert_stu(char* idIn, char* majorIn, char* nameIn)
	{
		student_node* newNode = new student_node(idIn, majorIn, nameIn);
		if (stuHead == nullptr)
		{
			stuHead = newNode;
		}
		else
		{
			student_node* movingNode = stuHead;
			while (movingNode->getPnext() != nullptr)
			{
				movingNode = movingNode->getPnext();
			}
			movingNode->setPnext(newNode);

		}
	}
	void print()
	{
		student_node* movingNode = stuHead;
		while (movingNode)
		{
			cout << "id : " << movingNode->getID() << "\t" << "major : " << movingNode->getMajor() << "\t" << "name : " << movingNode->getName() << "\n";
			movingNode = movingNode->getPnext();
		}
	}
};

