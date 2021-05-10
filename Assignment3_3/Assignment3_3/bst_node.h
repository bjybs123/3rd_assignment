#pragma once
#include "menu_node.h"


class bst_node
{
private:
	menu_node* pNode;
	bst_node* pLeft;
	bst_node* pRight;

public:
	bst_node();
	~bst_node();
	void setNode(menu_node*);
	menu_node* getNode();
	void setLeft(bst_node*);
	bst_node* getLeft();
	void setRight(bst_node*);
	bst_node* getRight();


};
class BST
{
private:
	bst_node* root;
	int count;
public:
	BST();
	~BST();
	bst_node* getRoot()
	{
		return root;
	}
	int getCount();
	void insert(char* nameIn, int priceIn);
	bst_node* _insert(bst_node* rootIn, bst_node* currentNode);
	void Print_IN(bst_node* pNode);
	void delNode(char* nameIn);
	void removeTree(bst_node*);
};



//bst_node's method functions
bst_node::bst_node()
{
	pNode = nullptr;
	pLeft = nullptr;
	pRight = nullptr;
}
bst_node::~bst_node()
{
	delete pNode;
}
void bst_node::setNode(menu_node* nodeIn)
{
	pNode = nodeIn;
}
menu_node* bst_node::getNode()
{
	return pNode;
}
void bst_node::setLeft(bst_node* nodeIn)
{
	pLeft = nodeIn;
}
bst_node* bst_node::getLeft()
{
	return pLeft;
}
void bst_node::setRight(bst_node* nodeIn)
{
	pRight = nodeIn;
}
bst_node* bst_node::getRight()
{
	return pRight;
}


//BST's method functions
BST::BST()
{
	root = nullptr;
	count = 0;
}
BST::~BST()
{
	removeTree(root);
	root = nullptr;

	_CrtDumpMemoryLeaks();
}

void BST::removeTree(bst_node* pNode)
{
	if (pNode)
	{
		removeTree(pNode->getLeft());

		removeTree(pNode->getRight());

		delete pNode;
	}

}

int BST::getCount()
{
	return count;
}
void BST::insert(char* nameIn, int priceIn)
{
	bst_node* currentBst = new bst_node();
	menu_node* newMenu = new menu_node();
	newMenu->setMenu(nameIn);
	newMenu->setPrice(priceIn);
	currentBst->setNode(newMenu);

	if (root == nullptr)
	{
		++count;
		root = currentBst;
	}
	else
	{
		_insert(root, currentBst);
	}
	return;
}
bst_node* BST::_insert(bst_node* rootIn, bst_node* currentNode)
{

	if (rootIn == nullptr)
	{
		++count;
		return currentNode;
	}
	if (my_strcmp(rootIn->getNode()->getMenu(), currentNode->getNode()->getMenu()) > 0)
	{
		rootIn->setLeft(_insert(rootIn->getLeft(), currentNode));
	}
	else if (my_strcmp(rootIn->getNode()->getMenu(), currentNode->getNode()->getMenu()) < 0)
	{
		rootIn->setRight(_insert(rootIn->getRight(), currentNode));
	}
	else if (my_strcmp(rootIn->getNode()->getMenu(), currentNode->getNode()->getMenu()) == 0)
	{
		return rootIn;
	}

	return rootIn;
}
void BST::Print_IN(bst_node* pNode)
{
	if (pNode)
	{
		Print_IN(pNode->getLeft());
		
		cout << pNode->getNode()->getMenu();

		if (strlen(pNode->getNode()->getMenu()) < 8)
		{
			cout << "\t";
		}

		cout << "\t\t" << pNode->getNode()->getPrice() << "\n";


		Print_IN(pNode->getRight());
	}
}
void BST::delNode(char* nameIn)
{
	bst_node* movingNode = root;
	bst_node* prev = nullptr;
	while (movingNode)
	{
		if (prev == nullptr)
		{
			if (my_strcmp(movingNode->getNode()->getMenu(), nameIn) == 0)
			{
				if (movingNode->getLeft() == nullptr && movingNode->getRight() == nullptr)
				{
					movingNode->setNode(nullptr);
					return;
				}
				else if (movingNode->getLeft() != nullptr && movingNode->getRight() == nullptr)
				{
					root = movingNode->getLeft();
					delete movingNode;
					return;
				}
				else if (movingNode->getLeft() == nullptr && movingNode->getRight() != nullptr)
				{
					root = movingNode->getRight();
					delete movingNode;
					return;
				}
				else if (movingNode->getLeft() != nullptr && movingNode->getRight() != nullptr)
				{
					root = movingNode->getRight();
					movingNode->getRight()->setLeft(movingNode->getLeft());
					delete movingNode;
					return;
				}
			}
			else if (my_strcmp(movingNode->getNode()->getMenu(), nameIn) > 0)
			{
				prev = movingNode;
				movingNode = movingNode->getLeft();
			}
			else if (my_strcmp(movingNode->getNode()->getMenu(), nameIn) < 0)
			{
				prev = movingNode;
				movingNode = movingNode->getRight();
			}
			else
			{
				cout << "no exist\n";
			}
		}
		else
		{
			if (my_strcmp(movingNode->getNode()->getMenu(), nameIn) == 0)
			{
				if (movingNode->getLeft() == nullptr && movingNode->getRight() == nullptr)
				{
					if (prev->getLeft() == movingNode)
					{
						prev->setLeft(nullptr);
					}
					else if (prev->getRight() == movingNode)
					{
						prev->setRight(nullptr);
					}
					delete movingNode;
					return;
				}
				else if (movingNode->getLeft() != nullptr && movingNode->getRight() == nullptr)
				{
					prev->setLeft(movingNode->getRight());
					movingNode->getRight()->setLeft(movingNode->getLeft());
					delete movingNode;
					return;
				}
				else if (movingNode->getLeft() == nullptr && movingNode->getRight() != nullptr)
				{
					prev->setRight(movingNode->getLeft());
					movingNode->getLeft()->setRight(movingNode->getRight());
					delete movingNode;
					return;
				}
				else if (movingNode->getLeft() != nullptr && movingNode->getRight() != nullptr)
				{
					prev->setLeft(movingNode->getRight());
					movingNode->getRight()->setLeft(movingNode->getLeft());
					delete movingNode;
					return;
				}
			}
			else if (my_strcmp(movingNode->getNode()->getMenu(), nameIn) > 0)
			{
				prev = movingNode;
				movingNode = movingNode->getLeft();
			}
			else if (my_strcmp(movingNode->getNode()->getMenu(), nameIn) < 0)
			{
				prev = movingNode;
				movingNode = movingNode->getRight();
			}
			else
			{
				cout << "no exist\n";
			}
		}
	}
}