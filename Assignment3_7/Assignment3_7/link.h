#pragma once

#include "node.h"



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



//template<typename T, template<typename L> class NODE>

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

template<>
class Link<char*>
{
private:
	student_node* stuHead;
	node<char*>* lHead;

public:
	Link()
	{

		stuHead = nullptr;
		lHead = nullptr;
	}
	void setstuHead(student_node* headIn)
	{
		stuHead = headIn;
	}
	student_node* getstuHead()
	{
		return stuHead;
	}
	node<char*>* getlHead()
	{
		return lHead;
	}
	void setlHead(node<char*>* headIn)
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
