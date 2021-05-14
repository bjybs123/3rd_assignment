#pragma once

#include <iostream>

using namespace std;

class A_Node
{
private:
	char* information;
	A_Node* pNext;
	W_Node* list;

public:
	A_Node();
	~A_Node();
	char* getInfo();
	void setInfo(char*);
	A_Node* getNext();
	void setNext(A_Node*);
	W_Node* getList();
	void setList(W_Node*);


};

class W_Node
{
private:
	char* Word;
	W_Node* pNext;
public:
	W_Node();
	~W_Node();
	W_Node* getNext();
	void setNext(W_Node*);
};


class students
{
private:
	A_Node* pHead;
	W_Node* yearHead;
	W_Node* majorHead;
	W_Node alphaHead;

public:
	students();
	~students();
	A_Node* getHead();
	W_Node* getYearhead();
	W_Node* getMajorhead();
	W_Node* getAlphahead();
	void setHead(A_Node*);
	void setYearhead(W_Node*);
	void setMajorhead(W_Node*);
	void setAlphahead(W_Node*);
};


//A_Node's method functions
A_Node::A_Node()
{
	information = new char[100];
	pNext = nullptr;
	list = nullptr;
}
A_Node::~A_Node()
{
	delete[] information;
}
char* A_Node::getInfo()
{
	return information;
}
void A_Node::setInfo(char* infoIn)
{
	int i = 0;
	while ((information[i] = infoIn[i]) != '\0')
		++i;
	return;
}
A_Node* A_Node::getNext()
{
	return pNext;
}
void A_Node::setNext(A_Node* nextIn)
{
	pNext = nextIn;
}
W_Node* A_Node::getList()
{
	return list;
}
void A_Node::setList(W_Node* listIn)
{
	list = listIn;
}

//W_Node's method functions
W_Node::W_Node()
{
	Word = new char[100];
	pNext = nullptr;
}
W_Node::~W_Node()
{
	delete[] Word;
}
W_Node* W_Node::getNext()
{
	return pNext;
}
void W_Node::setNext(W_Node* nextIn)
{
	pNext = nextIn;
}

//students' methos functions
students::students()
{
	pHead = nullptr;
	yearHead = nullptr;
	majorHead = nullptr;
	alphaHead = nullptr;
}
students::~students()
{
	;
}
A_Node* students::getHead()
{
	return pHead;
}
W_Node* students::getYearhead()
{
	return yearHead;
}
W_Node* students::getMajorhead()
{
	return majorHead;
}
W_Node* students::getAlphahead()
{
	return alphaHead;
}
void students::setHead(A_Node* headIn)
{
	pHead = headIn;
}
void students::setYearhead(W_Node* headIn)
{
	yearHead = headIn;
}
void students::setMajorhead(W_Node* headIn)
{
	majorHead = headIn;
}
void students::setAlphahead(W_Node* headIn)
{
	alphaHead = headIn;
}