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
	void setData(T dataIn)
	{
		data = dataIn;
	}
	T getData()
	{
		return data;
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

	node(char* dataIn)
	{
		data = new char[100];
		my_strcpy(data, dataIn);
		pNext = nullptr;
		sNext = nullptr;
	}
	char* getData()
	{
		return data;
	}
	void setPnext(node<char*>* nextIn)
	{
		pNext = nextIn;
	}
	node<char*>* getPnext()
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
class node<int>
{
private:
	int data;
	node<int>* pNext;
	student_node* sNext;

public:

	node()
	{
		data = 0;
		pNext = nullptr;
		sNext = nullptr;
	}
	node(int dataIn)
	{
		data = dataIn;
		pNext = nullptr;
		sNext = nullptr;
	}
	void setData(int dataIn)
	{
		data = dataIn;
	}
	int getData()
	{
		return data;
	}
	void setPnext(node<int>* nextIn)
	{
		pNext = nextIn;
	}
	node<int>* getPnext()
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
	void insertStuNode(student_node* nodeIn)
	{

	}
};

template<>
class node<char>
{
private:
	char data;
	node<char>* pNext;
	student_node* sNext;

public:

	node(char dataIn)
	{
		data = dataIn;
		pNext = nullptr;
		sNext = nullptr;
	}
	char getData()
	{
		return data;
	}
	void setPnext(node<char>* nextIn)
	{
		pNext = nextIn;
	}
	node<char>* getPnext()
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
