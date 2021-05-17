#pragma once
#include "student_node.h"

template<typename T>
class node
{
private:
	T data;
	node<T>* pNext;
	student_node* sNext;

public:

	node()
	{
		data = NULL;
		pNext = nullptr;
		sNext = nullptr;
	}
	void setNext(node<T>* nextIn)
	{
		pNext = nextIn;
	}
	node<T>* getNext()
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

template<>
class node<char*>
{
private:
	char* data;
	node<char*>* pNext;
	student_node* sNext;

public:

	node()
	{
		data = new char[100];
		pNext = nullptr;
		sNext = nullptr;
	}
	void setNext(node<char*>* nextIn)
	{
		pNext = nextIn;
	}
	node<char*>* getNext()
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