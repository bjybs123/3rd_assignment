#pragma once

#include "node.h"


//template<typename T, template<typename L> class NODE>

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
			//linkIn->insertStuNode(checkNode); 
			checkNode = checkNode->getPnext();
		}
	}
	void insertNode(student_node* nodeIn)
	{
		node<char*>* newNode = new node<char*>(nodeIn->getMajor());
		//
		if (lHead == nullptr)
		{

			lHead = newNode;
			//insertStuNode(nodeIn);             여기서도 compare이 진행이 되어야함
		}
		else
		{
			node<char*>* prevNode = lHead;
			node<char*>* movingNode = lHead;
			while (movingNode)
			{
				if (strcmp(movingNode->getData(), nodeIn->getMajor()) == 0)
				{
					cout << "same...\n";
					break;
					//insertStuNode(nodeIn);             여기서도 compare이 진행이 되어야함
				}

				else if (strcmp(movingNode->getData(), nodeIn->getMajor()) > 0)
				{
					if (movingNode == prevNode)
					{
						lHead = newNode;
						newNode->setPnext(movingNode);
					}
					else
					{
						prevNode->setPnext(newNode);
						newNode->setPnext(movingNode);
					}

					break;
				}
				if (movingNode->getPnext() == nullptr)
				{
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

		node<int>* newNode = new node<int>(year);
		//
		if (lHead == nullptr)
		{

			lHead = newNode;
			//insertStuNode(nodeIn);             여기서도 compare이 진행이 되어야함
		}
		else
		{
			node<int>* prevNode = lHead;
			node<int>* movingNode = lHead;
			while (movingNode)
			{
				if (movingNode->getData() == year)
				{
					cout << "same...\n";
					break;
					//movingNode->insertStuNode(nodeIn);             여기서도 compare이 진행이 되어야함
				}
				
				else if (Compare(movingNode->getData(), year) > 0)
				{
					if (movingNode == prevNode)
					{
						lHead = newNode;
						newNode->setPnext(movingNode);
					}
					else
					{
						prevNode->setPnext(newNode);
						newNode->setPnext(movingNode);
					}
					
					break;
				}
				if (movingNode->getPnext() == nullptr)
				{
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
};

template<>
class Link<char>		//year
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
			//linkIn->insertStuNode(checkNode); 
			checkNode = checkNode->getPnext();
		}
	}
	void insertNode(student_node* nodeIn)
	{
		char C = toupper(nodeIn->getName()[0]);

		node<char>* newNode = new node<char>(C);
		//
		if (lHead == nullptr)
		{

			lHead = newNode;
			//insertStuNode(nodeIn);             여기서도 compare이 진행이 되어야함
		}
		else
		{
			node<char>* prevNode = lHead;
			node<char>* movingNode = lHead;
			while (movingNode)
			{
				if (movingNode->getData() == C)
				{
					cout << "same...\n";
					break;
					//insertStuNode(nodeIn);             여기서도 compare이 진행이 되어야함
				}

				else if (Compare(movingNode->getData(), C) > 0)
				{
					if (movingNode == prevNode)
					{
						lHead = newNode;
						newNode->setPnext(movingNode);
					}
					else
					{
						prevNode->setPnext(newNode);
						newNode->setPnext(movingNode);
					}

					break;
				}
				if (movingNode->getPnext() == nullptr)
				{
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
};
