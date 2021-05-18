#pragma once

#include "node.h"



template<typename T>	
class Link		//integrated
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
	void insert_stu(student_node* newNode)
	{
		
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
	void insert_2D(student_node* nodeIn)
	{
		student_node* checkNode = nodeIn;
		while (checkNode)
		{
			insertNode(checkNode);
			checkNode = checkNode->getPnext();
		}

	}
	void insertNode(student_node* nodeIn)
	{
		

		if (lHead == nullptr)
		{
			node<T>* newNode = new node<T>(nodeIn->getMajor());
			lHead = newNode;
			lHead->insert(nodeIn);
		}
		else
		{
			node<T>* prevNode = lHead;
			node<T>* movingNode = lHead;
			while (movingNode)
			{

				if (Compare(movingNode->getData(), nodeIn->getMajor()) == 0)
				{
					movingNode->insert(nodeIn);
					break;
				}

				else if (Compare(movingNode->getData(), nodeIn->getMajor()) > 0)
				{
					if (movingNode == prevNode)
					{
						node<T>* newNode = new node<T>(nodeIn->getMajor());
						newNode->insert(nodeIn);
						lHead = newNode;
						newNode->setPnext(movingNode);

						break;
					}
					else
					{
						node<T>* newNode = new node<T>(nodeIn->getMajor());
						newNode->insert(nodeIn);
						prevNode->setPnext(newNode);
						newNode->setPnext(movingNode);

					}
					break;
				}
				if (movingNode->getPnext() == nullptr)
				{
					node<T>* newNode = new node<T>(nodeIn->getMajor());
					newNode->insert(nodeIn);
					movingNode->setPnext(newNode);
					break;
				}
				prevNode = movingNode;
				movingNode = movingNode->getPnext();
			}
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

	void deletAllNode()
	{
		student_node* moving1 = stuHead;
		while (moving1)
		{
			student_node* deleteNode = moving1;
			delete deleteNode;
			moving1 = moving1->getPnext();
		}

		node<T>* moving2 = lHead;
		while (moving2)
		{
			node* deleteNode = moving2;
			delete deleteNode;
			moving2 = moving2->getPnext();
		}
		return;
	}
};

template<>
class Link<char*>	//major
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
	void insert_stu(student_node* newNode)
	{
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
	void insert_2D(student_node* nodeIn)
	{
		student_node* checkNode = nodeIn;
		while (checkNode)
		{
			insertNode(checkNode);
			checkNode = checkNode->getPnext();
		}
		
	}
	void insertNode(student_node* nodeIn)
	{
		

		if (lHead == nullptr)
		{
			node<char*>* newNode = new node<char*>(nodeIn->getMajor());
			lHead = newNode;
			lHead->insert(nodeIn);
		}
		else
		{
			node<char*>* prevNode = lHead;
			node<char*>* movingNode = lHead;
			while (movingNode)
			{
				
				if (Compare(movingNode->getData(), nodeIn->getMajor()) == 0)
				{
					movingNode->insert(nodeIn);
					break;
				}

				else if (Compare(movingNode->getData(), nodeIn->getMajor()) > 0)
				{
					if (movingNode == prevNode)
					{
						node<char*>* newNode = new node<char*>(nodeIn->getMajor());
						newNode->insert(nodeIn);
						lHead = newNode;
						newNode->setPnext(movingNode);
						
						break;
					}
					else
					{
						node<char*>* newNode = new node<char*>(nodeIn->getMajor());
						newNode->insert(nodeIn);
						prevNode->setPnext(newNode);
						newNode->setPnext(movingNode);
						
					}
					break;
				}
				if (movingNode->getPnext() == nullptr)
				{
					node<char*>* newNode = new node<char*>(nodeIn->getMajor());
					newNode->insert(nodeIn);
					movingNode->setPnext(newNode);
					break;
				}
				prevNode = movingNode;
				movingNode = movingNode->getPnext();
			}
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
	void print2D()
	{
		node<char*>* movingNode = lHead;
		cout << "============================================================================\n";
		while (movingNode)
		{
			cout << movingNode->getData() << "\n";
			movingNode->print(movingNode->getSnext());
			movingNode = movingNode->getPnext();
			cout << "\n";
		}
		cout << "============================================================================\n";

	}

	void deleteNode()
	{
		node<char*>* moving2 = lHead;
		node<char*>* deleteNode;
		while (moving2 != nullptr)
		{
			deleteNode = moving2;
			moving2 = moving2->getPnext();
			delete[] deleteNode->getData();
			delete deleteNode;
		}
		lHead = nullptr;
		return;
	}
};

template<>
class Link<int>		//year
{
private:
	student_node* stuHead;
	node<int>* lHead;

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
	node<int>* getlHead()
	{
		return lHead;
	}
	void setlHead(node<int>* headIn)
	{
		lHead = headIn;
	}
	void insert_stu(student_node* newNode)
	{
		
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
	void insert_2D(student_node* nodeIn)
	{
		student_node* checkNode = nodeIn;
		while (checkNode)
		{
			insertNode(checkNode);
			checkNode = checkNode->getPnext();
		}

	}
	void insertNode(student_node* nodeIn)
	{
		char* dataIn = nodeIn->getID();
		int year;
		char* tempyear = new char[5];
		int i = 0;
		while (dataIn[i] != '\0')
		{
			if (i <= 3)
			{
				tempyear[i] = dataIn[i];
			}
			if (i == 4)
				break;
			++i;
		}
		tempyear[i] = '\0';
		year = atoi(tempyear);
		delete[] tempyear;

		

		if (lHead == nullptr)
		{
			node<int>* newNode = new node<int>(year);
			lHead = newNode;
			lHead->insert(nodeIn);
		}
		else
		{
			node<int>* prevNode = lHead;
			node<int>* movingNode = lHead;
			while (movingNode)
			{

				if (Compare(movingNode->getData(), nodeIn->getYear()) == 0)
				{
					movingNode->insert(nodeIn);
					break;
				}

				else if (Compare(movingNode->getData(), nodeIn->getYear()) > 0)
				{
					if (movingNode == prevNode)
					{
						node<int>* newNode = new node<int>(year);
						newNode->insert(nodeIn);
						lHead = newNode;
						newNode->setPnext(movingNode);

						break;
					}
					else
					{
						node<int>* newNode = new node<int>(year);
						newNode->insert(nodeIn);
						prevNode->setPnext(newNode);
						newNode->setPnext(movingNode);

					}
					break;
				}
				if (movingNode->getPnext() == nullptr)
				{
					node<int>* newNode = new node<int>(year);
					newNode->insert(nodeIn);
					movingNode->setPnext(newNode);
					break;
				}
				prevNode = movingNode;
				movingNode = movingNode->getPnext();
			}
		}
	}
	void print()
	{
		cout << "============================================================================\n"; 
		cout << "StudentID";
		cout.width(30);
		cout <<  "Major";
		cout.width(40);
		cout <<  "Name\n";

		student_node* movingNode = stuHead;
		while (movingNode)
		{
			
			cout <<  movingNode->getID();
			cout.width(30);
			cout <<  movingNode->getMajor();
			cout.width(40);
			cout <<  movingNode->getName() << "\n";
			movingNode = movingNode->getPnext();
		}

		cout << "============================================================================\n";
	}
	void print2D()
	{
		node<int>* movingNode = lHead;
		cout << "============================================================================\n";
		
		cout << "Name\n";
		while (movingNode)
		{
			cout << movingNode->getData() << "\n";
			movingNode->print(movingNode->getSnext());
			movingNode = movingNode->getPnext();
			cout << "\n";
		}
		cout << "============================================================================\n";
	}
	void deletestuNode()
	{
		student_node* movingNode = stuHead;
		student_node* deleteNode;
		while (movingNode != nullptr)
		{
			deleteNode = movingNode;
			movingNode = movingNode->getPnext();
			delete deleteNode;
		}
	}

	void deleteNode()
	{
		node<int>* moving2 = lHead;
		//node<int>* deleteNode;
		while (moving2)
		{
			lHead = lHead->getPnext();
			delete moving2;
			moving2 = lHead;
		}
		lHead = nullptr;
		return;
	}
};

template<>
class Link<char>		//alpha
{
private:
	student_node* stuHead;
	node<char>* lHead;

public:
	Link()
	{
		stuHead = nullptr;
		lHead = nullptr;
	}
	~Link()
	{
		
	}
	void setstuHead(student_node* headIn)
	{
		stuHead = headIn;
	}
	student_node* getstuHead()
	{
		return stuHead;
	}
	node<char>* getlHead()
	{
		return lHead;
	}
	void setlHead(node<char>* headIn)
	{
		lHead = headIn;
	}
	void insert_stu(student_node* newNode)
	{

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
	void insert_2D(student_node* nodeIn)
	{
		student_node* checkNode = nodeIn;
		while (checkNode)
		{
			insertNode(checkNode);
			checkNode = checkNode->getPnext();
		}

	}
	void insertNode(student_node* nodeIn)
	{
		

		if (lHead == nullptr)
		{
			node<char>* newNode = new node<char>(toupper(nodeIn->getName()[0]));
			lHead = newNode;
			lHead->insert(nodeIn);
		}
		else
		{
			node<char>* prevNode = lHead;
			node<char>* movingNode = lHead;
			while (movingNode)
			{

				if (Compare(movingNode->getData(), nodeIn->getName()[0]) == 0)
				{
					movingNode->insert(nodeIn);
					break;
				}

				else if (Compare(movingNode->getData(), nodeIn->getName()[0]) > 0)
				{
					if (movingNode == prevNode)
					{
						node<char>* newNode = new node<char>(toupper(nodeIn->getName()[0]));
						newNode->insert(nodeIn);
						lHead = newNode;
						newNode->setPnext(movingNode);
						break;
					}
					else
					{
						node<char>* newNode = new node<char>(toupper(nodeIn->getName()[0]));
						newNode->insert(nodeIn);
						prevNode->setPnext(newNode);
						newNode->setPnext(movingNode);

					}
					break;
				}
				if (movingNode->getPnext() == nullptr)
				{
					node<char>* newNode = new node<char>(toupper(nodeIn->getName()[0]));
					newNode->insert(nodeIn);
					movingNode->setPnext(newNode);
					break;
				}
				prevNode = movingNode;
				movingNode = movingNode->getPnext();
			}
		}
	}
	void print()
	{
		student_node* movingNode = stuHead;
		while (movingNode)
		{

			cout << "id : " << movingNode->getID() << "\t" << "major : " << movingNode->getMajor() << "\t" << "name : " << movingNode->getName() << "\n";
			movingNode = movingNode->getAlphanext();
		}
	}
	void print2D()
	{
		node<char>* movingNode = lHead;
		cout << "============================================================================\n";
		while (movingNode)
		{
			cout << movingNode->getData() << "\n";
			movingNode->print(movingNode->getSnext());
			movingNode = movingNode->getPnext();
			cout << "\n";
		}
		cout << "============================================================================\n";
	}
	void deleteNode()
	{
		node<char>* moving2 = lHead;
		node<char>* deleteNode;
		while (moving2 != nullptr)
		{
			deleteNode = moving2;
			moving2 = moving2->getPnext();
			delete deleteNode;
		}

		return;
	}
};
