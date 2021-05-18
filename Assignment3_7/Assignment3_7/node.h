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
	void setPnext(node<T>* nextIn)
	{
		pNext = nextIn;
	}
	node<T>* getPnext()
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
	void print(student_node* nodeIn)
	{
		student_node* movingNode = nodeIn;
		cout << "StudentID";
		cout.width(30);
		cout << "Major";
		cout.width(40);
		cout << "Name\n";
		while (movingNode)
		{
			cout << movingNode->getID();
			cout.width(30);
			cout << movingNode->getMajor();
			cout.width(40);
			cout << movingNode->getName() << "\n";
			movingNode = movingNode->getAlphanext();
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
	~node()
	{
		//delete[] data;
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
	void insert(student_node* nodeIn)			//char*  --> major
	{
		student_node* prevNode = sNext;
		student_node* movingNode = sNext;
		if (sNext == nullptr)
		{
			sNext = nodeIn;
		}
		else
		{
			while (movingNode)
			{
				if (Compare(movingNode->getMajor(), nodeIn->getMajor()) == 0)
				{
					if (strcmp(movingNode->getID(), nodeIn->getID()) > 0)
					{
						if (prevNode == movingNode)
						{
							if (movingNode->getMajornext())
							{
								nodeIn->setMajornext(movingNode->getMajornext());	//완성 후 추가
							}
							movingNode->setMajornext(nodeIn);
							break;
						}
						else
						{
							prevNode->setMajornext(nodeIn);
							nodeIn->setMajornext(movingNode);
							break;
						}
					}
					else if (movingNode->getMajornext() == nullptr)
					{
						movingNode->setMajornext(nodeIn);
						break;
					}
				}
				prevNode = movingNode;
				movingNode = movingNode->getMajornext();
			}
		}
		
	}
	void print(student_node* nodeIn)
	{
		student_node* movingNode = nodeIn;
		cout << "StudentID";
		cout.width(30);
		cout << "Major";
		cout.width(40);
		cout << "Name\n";
		while (movingNode)
		{
			cout << movingNode->getID();
			cout.width(30);
			cout << movingNode->getMajor();
			cout.width(40);
			cout << movingNode->getName() << "\n";
			movingNode = movingNode->getMajornext();
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
	void insert(student_node* nodeIn)			//year
	{
		student_node* prevNode = sNext;
		student_node* movingNode = sNext;
		if (sNext == nullptr)
		{
			sNext = nodeIn;
		}
		else
		{
			while (movingNode)
			{
				if (Compare(movingNode->getYear(), nodeIn->getYear()) == 0)
				{
					if (strcmp(movingNode->getID(), nodeIn->getID()) > 0)
					{
						if (prevNode == movingNode)
						{
							if (movingNode->getYearnext())
							{
								nodeIn->setYearnext(movingNode->getYearnext());	//완성 후 추가
							}
							movingNode->setYearnext(nodeIn);
							break;
						}
						else
						{
							prevNode->setYearnext(nodeIn);
							nodeIn->setYearnext(movingNode);
							break;
						}
					}
					else if (movingNode->getYearnext() == nullptr)
					{
						movingNode->setYearnext(nodeIn);
						break;
					}
				}
				prevNode = movingNode;
				movingNode = movingNode->getYearnext();
			}
		}

	}
	void print(student_node* nodeIn)
	{
		student_node* movingNode = nodeIn;
		cout << "StudentID";
		cout.width(30);
		cout << "Major";
		cout.width(40);
		cout << "Name\n";
		while (movingNode)
		{
			cout << movingNode->getID();
			cout.width(30);
			cout << movingNode->getMajor();
			cout.width(40);
			cout << movingNode->getName() << "\n";
			movingNode = movingNode->getYearnext();
		}
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
	void insert(student_node* nodeIn)			//alpha
	{
		student_node* prevNode = sNext;
		student_node* movingNode = sNext;
		if (sNext == nullptr)
		{
			sNext = nodeIn;
		}
		else
		{
			while (movingNode)
			{
				if (Compare(toupper(movingNode->getName()[0]), toupper(nodeIn->getName()[0])) == 0)
				{
					if (strcmp(movingNode->getName(), nodeIn->getName()) > 0)
					{
						if (prevNode == movingNode)
						{
							if (movingNode->getAlphanext())
							{
								nodeIn->setAlphanext(movingNode->getAlphanext());
							}
							movingNode->setAlphanext(nodeIn);
							
							break;
						}
						else
						{
							prevNode->setAlphanext(nodeIn);
							nodeIn->setAlphanext(movingNode);
							break;
						}
					}
					else if (movingNode->getAlphanext() == nullptr)
					{
						movingNode->setAlphanext(nodeIn);
						break;
					}
				}
				prevNode = movingNode;
				movingNode = movingNode->getAlphanext();
			}
		}

	}
	void print(student_node* nodeIn)
	{
		student_node* movingNode = nodeIn;
		cout << "StudentID";
		cout.width(30);
		cout << "Major";
		cout.width(40);
		cout << "Name\n";
		while (movingNode)
		{
			cout << movingNode->getID();
			cout.width(30);
			cout << movingNode->getMajor();
			cout.width(40);
			cout << movingNode->getName() << "\n";
			movingNode = movingNode->getAlphanext();
		}
	}
};
