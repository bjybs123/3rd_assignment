#include <iostream>

#define Error100 cerr << "Error 100\n";
#define Error200 cerr << "Error 200\n";
#define Error300 cerr << "Error 300\n";
#define Error400 cerr << "Error 400\n";
#define Error500 cerr << "Error 500\n";
#define Error600 cerr << "Error 600\n";
#define Error700 cerr << "Error 700\n";

using namespace std;

bool Estate = false;

class Node
{
private:
	int data;							//노드  문자열 데이터를 저장할 공간
	Node* next;							//다음 노드를 저장할 노드
public:
	Node()			//생성자
	{
		data = 0;
		next = nullptr;					//다음 노드를 가르키는 포인터를 nullptr로 초기화
	}
	Node* getNext()
	{
		return next;
	}
	int getData()
	{
		return data;
	}
	void setNext(Node* curNode)
	{
		next = curNode;
	}
	void setData(int value)
	{
		data = value;
	}
};

class bstNode
{
private:
	int data;
	bstNode* pLeft;
	bstNode* pRight;

public:
	bstNode()
	{
		data = 0;
		pLeft = nullptr;
		pRight = nullptr;
	}
	bstNode(int dataIn)
	{
		pLeft = nullptr;
		pRight = nullptr;
		data = dataIn;
	}

	int getData()
	{
		return data;
	}
	bstNode* getLeft()
	{
		return pLeft;
	}
	bstNode* getRight()
	{
		return pRight;
	}

	void setData(int dataIn)
	{
		data = dataIn;
	}
	void setLeft(bstNode* pNode)
	{
		pLeft = pNode;
	}
	void setRight(bstNode* pNode)
	{
		pRight = pNode;
	}
};

class BST
{
private:
	bstNode* root;

public:
	BST()
	{
		root = nullptr;
	}

	bstNode* getRoot()
	{
		return root;
	}
	void setRoot(bstNode* pNode)
	{
		root = pNode;
	}
	void insert(int data)
	{
		bstNode* currentBst = new bstNode(data);

		if (root == nullptr)
		{
			cout << "root is now nullptr root = currentBst\n";
			root = currentBst;
		}
		else
		{
			cout << "root is not nullptr insert\n";
			_insert(root, currentBst);
		}
	}

	bstNode* _insert(bstNode* rootIn, bstNode* currentNode)
	{
		if (rootIn == nullptr)
		{
			return currentNode;
		}
		if (rootIn->getData() > currentNode->getData())
		{
			rootIn->setLeft(_insert(rootIn->getLeft(), currentNode));
		}
		else if (rootIn->getData() < currentNode->getData())
		{
			rootIn->setRight(_insert(rootIn->getRight(), currentNode));
		}
		return rootIn;
	}

	void Print_PRE(bstNode* pNode)
	{
		if (pNode)
		{
			cout << pNode->getData() << "\t";

			Print_PRE(pNode->getLeft());
			
			Print_PRE(pNode->getRight());
		}
	}

	void Print_IN(bstNode* pNode)
	{
		if (pNode)
		{
			Print_IN(pNode->getLeft());
			cout << pNode->getData() << "\t";
			Print_IN(pNode->getRight());
		}
	}
	void Print_POST(bstNode* pNode)
	{
		if (pNode)
		{
			Print_POST(pNode->getLeft());
			Print_POST(pNode->getRight());
			
			cout << pNode->getData() << "\t";
		}
	}

	bool search(bstNode* pNode, int data)
	{
		bstNode* bstLeftNode = new bstNode();
		bstNode* bstRightNode = new bstNode();
		bstLeftNode = pNode;
		bstRightNode = pNode;

		while (bstLeftNode != nullptr)
		{
			if (bstLeftNode->getData() == data)
				return true;
			bstLeftNode = bstLeftNode->getLeft();
		}

		while (bstRightNode != nullptr)
		{
			if (bstRightNode->getData() == data)
				return true;
			bstRightNode = bstRightNode->getRight();
		}
		return false;
	}

	
	
};

class queue
{
private:
	Node* front;
	Node* rear;
	int size;

public:
	queue()
	{
		front = nullptr;
		rear = nullptr;
		size = 0;
	}
	int getSize()
	{
		return size;
	}
	bool isEmpty(queue* checkQueue)
	{
		return checkQueue->size == 0 ? true : false;
	}
	bool isFull(queue* checkQueue)
	{
		return checkQueue->size >= 5 ? true : false;
	}

	void Enqueue(queue* queue, int data)
	{
		Estate = false;
		Node* currentNode = new Node();
		currentNode->setData(data);
		if (isEmpty(queue))
		{
			queue->front = currentNode;
			queue->rear = currentNode;
		}
		else
		{
			if (!isFull(queue))
			{
				queue->rear->setNext(currentNode);
			}
			else
			{
				Estate = true;
				Error300;
			}
		}

		
		if (Estate == false)
		{
			queue->rear = currentNode;
			queue->size++;
		}
		return;
	}

	int Dequeue(queue* queue, int data)
	{

		int theData;
		Node* deleteNode;
		deleteNode = queue->front;
		theData = deleteNode->getData();
		queue->front = queue->front->getNext();
		delete deleteNode;
		queue->size--;

		return theData;
	}

	const void print(queue* theQueue)
	{
		if (theQueue->size == 0)
		{
			Error500;
			return;
		}
		Node* printNode = theQueue->rear;
		printNode = theQueue->front;
		while (printNode != nullptr)
		{
			cout << printNode->getData() << "\t";
			printNode = printNode->getNext();
		}

		cout << '\n';
	}

};

bool getNum(int* data)
{
	bool OPstate = false;

	int op = 1;
	char* dataStr = new char[100];
	int i = 0;
	char c;
	Estate = false;
	while (cin.get(c) && c != '\n')
	{
		if (c == '-')
		{
			OPstate = true;
			op = -1;
		}
		else if (c != ' ' && c != '\t')
		{
			if (isalpha(c))
			{
				while (cin.get() != '\n');
				Estate = true;
				Error200;
				break;
			}
			else if (c >= 48 && c <= 57)
			{
				dataStr[i++] = c;
			}
		}
		else if(c == ' '  || c == '\t')
		{
			if (OPstate == true)
				op = 1;
		}
	}
	if (i == 0 && Estate == false)
	{
		delete[] dataStr;
		Error200;
		return false;
	}
	else if (i != 0 && Estate == false)
	{
		dataStr[i] = '\0';
		*data = atoi(dataStr);
		*data *= op;
	}
	delete[] dataStr;
	return true;
}

void getOrder(char* order)
{
	char c;
	int i = 0;

	while (cin.get(c) && c != '\n')
	{
		if (isalpha(c))
		{
			order[i] = c;
			++i;
		}
		order[i] = '\0';
	}

	return;
}

int main()
{
	queue Q;
	BST tree;
	int data;

	char* order = new char[100];
	char* command = new char[100];

	while (true)
	{
		cout << "CMD>> ";
		cin >> command;

		if (strcmp(command, "Enqueue") == 0)
		{
			if (getNum(&data))
			{
				if (Estate == false)
					Q.Enqueue(&Q, data);
			}
			else
				continue;
		}
		else if (strcmp(command, "Dequeue") == 0)
		{


			if (getNum(&data))
			{
				if (data > Q.getSize())
					data = Q.getSize();
			}
			else
				continue;

			if (Q.isEmpty(&Q))
			{
				Error400;
				continue;
			}

			while (data--)
			{
				bstNode* currentBst = new bstNode();
				int	insertData = Q.Dequeue(&Q, data);
				tree.insert(insertData);
			}

		}
		else if (strcmp(command, "Print_Queue") == 0)
		{
			Q.print(&Q);
		}
		else if (strcmp(command, "PRINT") == 0)
		{
			if (tree.getRoot() == nullptr)
			{
				char c;
				Error700;
				while (cin.get(c) && c != '\n');
				continue;
			}
			getOrder(order);
			if (strcmp(order, "IN") == 0)
			{
				tree.Print_IN(tree.getRoot());
			}
			else if (strcmp(order, "PRE") == 0)
			{
				tree.Print_PRE(tree.getRoot());
			}
			else if (strcmp(order, "POST") == 0)
			{
				tree.Print_POST(tree.getRoot());
			}
			else
			{
				Error200;
				continue;
			}
			cout << "\n";
		}
		else if (strcmp(command, "SEARCH") == 0)
		{
			if (getNum(&data))
			{
				if (tree.search(tree.getRoot(), data))
					cout << data << " is exists\n";
				else
				{
					Error600;
					continue;
				}
			}
		}
		else if (strcmp(command, "exit") == 0)
		{
			break;
		}
		else
		{
			while (cin.get() != '\n');
			Error100;
			continue;
		}
	}
	delete[] command;
	delete[] order;
	return 0;
	
}