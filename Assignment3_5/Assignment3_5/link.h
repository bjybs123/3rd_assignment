#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Node
{
private:
	Node* next;
	bool bullet;

public:
	Node();
	~Node();
	Node* getNext();
	void setNext(Node*);
	bool getBullet();
	void setBullet(bool);
};

class Link
{
private:
	Node* head;
	int count;

public:
	Link();
	~Link();
	int getCount();
	void setCount(int);
	void initial();
	void rotate();
	void print();
	Node* getHead();
	void goNext();
	void clean();
};

//Link's method functions

Link::Link()
{
	head = nullptr;
	count = 0;
}
Link::~Link()
{
	int maxNum = 6;
	Node* delNode;
	while (head && maxNum)
	{
		delNode = head;
		head = head->getNext();
		delete delNode;
		--maxNum;
	}
	_CrtDumpMemoryLeaks();
}
void Link::clean()
{
	int maxNum = 6;
	Node* movingNode = head;
	while (movingNode && maxNum)
	{
		movingNode->setBullet(false);
		movingNode = movingNode->getNext();
		--maxNum;
	}
}
void Link::initial()
{
	Node* origin = nullptr;
	int maxNode = 6;
	while (maxNode)
	{
		Node* newNode = new Node();
		if (head == nullptr)
		{
			head = newNode;
			origin = head;
		}
		else
		{
			Node* movingNode = head;
			while (movingNode->getNext() != nullptr)
			{
				movingNode = movingNode->getNext();
			}
			movingNode->setNext(newNode);
			if (maxNode == 1)
			{
				movingNode = movingNode->getNext();
				movingNode->setNext(origin);
			}
		}
		--maxNode;
	}
	
}
void Link::rotate()
{
	srand((unsigned int)time(NULL));

	int rotateNum = rand() % 6 + 1;

	
	head->setBullet(true);
	while (rotateNum)
	{
		head = head->getNext();
		--rotateNum;
	}
	

}
Node* Link::getHead()
{
	return head;
}
void Link::goNext()
{
	head = head->getNext();
}
void Link::print()
{
	Node* movingNode = head;
	int maxNum = 6;
	while (movingNode && maxNum)
	{
		cout << "bullet : " << movingNode->getBullet() << "\n";
		movingNode = movingNode->getNext();
		--maxNum;
	}
	return;
}
int Link::getCount()
{
	return count;
}
void Link::setCount(int countIn)
{
	count = countIn;
}


//Node's method functions

Node::Node()
{
	next = nullptr;
	bullet = false;
}
Node::~Node()
{

}
Node* Node::getNext()
{
	return next;
}
void Node::setNext(Node* nextIn)
{
	next = nextIn;
}
bool Node::getBullet()
{
	return bullet;
}
void Node::setBullet(bool bulletIn)
{
	bullet = bulletIn;
}