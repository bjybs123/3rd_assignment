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
	bst_node* delNode(bst_node* pNode, char* nameIn);
};



//bst_node's method functions
bst_node::bst_node()
{
	pNode = new menu_node();
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
}
int BST::getCount()
{
	return count;
}
void BST::insert(char* nameIn, int priceIn)
{
	bst_node* currentBst = new bst_node();
	bst_node* tempBst = new bst_node();
	currentBst->getNode()->setMenu(nameIn);
	currentBst->getNode()->setPrice(priceIn);

	if (root == nullptr)
	{
		++count;
		root = currentBst;
	}
	else
	{
		_insert(root, currentBst);
		
	}
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
bst_node* BST::delNode(bst_node* pNode, char* nameIn)
{
	int cmpNum = my_strcmp(pNode->getNode()->getMenu(), nameIn);
	if (cmpNum == 0)
	{
		if (pNode->getLeft() == nullptr && pNode->getRight() == nullptr)
		{
			pNode->setNode(nullptr);

		}
		else if (pNode->getLeft() != nullptr && pNode->getRight() == nullptr)
		{
			pNode->setNode(pNode->getLeft()->getNode());
			pNode->setLeft(nullptr);
		}
		else if (pNode->getLeft() == nullptr && pNode->getRight() != nullptr)
		{
			pNode->setNode(pNode->getRight()->getNode());
			pNode->setRight(nullptr);
		}
		else
		{
			pNode->setNode(pNode->getRight()->getNode());
			pNode->setRight(nullptr);
		}
		--count;
	}
	else if (cmpNum > 0)
	{
		if(pNode->getLeft())
			delNode(pNode->getLeft(), nameIn);
		else
		{
			cout << "BST : Not in menu\n";
			return nullptr;
		}
	}
	else if (cmpNum < 0)
	{
		if(pNode->getRight())
			delNode(pNode->getRight(), nameIn);
		else
		{
			cout << "BST : Not in menu\n";
			return nullptr;
		}
	}

	return pNode;
}