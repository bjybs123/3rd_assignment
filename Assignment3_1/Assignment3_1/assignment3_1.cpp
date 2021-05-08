#include <iostream>

using namespace std;
		
char* my_strcpy(char* destination, const char* source)		//���ڿ� ���� �Լ� ����
{
	while (*source != '\0')
	{
		*destination = *source;
		source++;
		destination++;
	}

	*destination = '\0';

	return destination;
}				
void* my_strcpy_low(char* destination, char* source)		//lowercase ���ڿ� ���� �Լ�
{
	while (*source != '\0')
	{
		*destination = tolower(*source);
		source++;
		destination++;
	}

	*destination = '\0';

	return destination;
}				

class Node
{
private:
	char* data;							//���  ���ڿ� �����͸� ������ ����
	Node* next;							//���� ��带 ������ ���
public:
	Node()			//������
	{
		data = new char[100];			//�����ڸ� ���� ���ڿ� �����͸� 100ũ��� �����Ҵ�
		next = nullptr;					//���� ��带 ����Ű�� �����͸� nullptr�� �ʱ�ȭ
	}
	~Node()			//�Ҹ���
	{
		delete[] data;//�����Ҵ� ���� data ���ڿ� ���� ����
	}
	void setData(char* wordIn)
	{
		my_strcpy(data, wordIn);
	}
	Node* getNext()
	{
		return next;
	}
	char* getData()
	{
		return data;
	}
	void setNext(Node* curNode)
	{
		next = curNode;
	}
};

class Link
{
private:
	int cntSize = 0;			//��� ��尡 ����Ǿ� �ִ��� ī���� �ϴ� ����
public:
	Node* head;				//�ص� ��� 
	void insert(char* insertStr);
	bool is_same(char* insertStr);
	const void print();
	~Link()
	{
		while (head)
		{
			Node* delNode = head;

			head = head->getNext();
			delete delNode;
		}

	}
};


bool Link::is_same(char* insertStr)
{
	Node* tempNode = head;

	char* lowerCase = new char[100];			//lowercase�� ��ȯ�� ���ڿ��� ����
	char* lowerCaseIserted = new char[100];		

	while (tempNode->getNext() != nullptr)			//tempNode�� ����� ó���� head�� ����Ű�� �� ���� �������� �̵��ϸ鼭 nullptr������ �˻�
	{
		my_strcpy_low(lowerCase, tempNode->getData());
		my_strcpy_low(lowerCaseIserted, insertStr);

		if (strcmp(lowerCase, lowerCaseIserted) == 0)
			return true;			//���ర�� ���ڿ��� �߰ߵǸ� true ��ȯ
		tempNode = tempNode->getNext();	//���� ���� ������
	}

	delete[] lowerCase;
	delete[] lowerCaseIserted;

	return false;
}	   //��ҹ��� ���� ���� �� �� ��� ���̸ӿ� �Էµ� ���ڿ��� �������� �ִ��� �Ǻ� �Լ�

void Link::insert(char* insertStr)
{
	Node* currentNode = new Node;
	currentNode->setData(insertStr);

	if (head == nullptr)			//ó�� ���� ���� �ʿ� ���� ��  
	{
		head = currentNode;
		++cntSize;
	}
	else						//ù ��尡 �ƴ϶��
	{
			//���� ��带 ���� �Ҵ�
		Node* tempNode = head;				//�ӽ� ��带 ����� head�� ����Ŵ
		while (tempNode->getNext() != nullptr)	//���� �ִ� ����� �����͸� �����ϱ����� ������ ���� ����
			tempNode = tempNode->getNext();



		if (tolower(tempNode->getData()[strlen(tempNode->getData()) - 1]) == tolower(*insertStr))		//���� ������ �������� ������ ���ڿ� �Էõ� ���ڿ� ù��° ���ڰ� ���ٸ�
		{
			if (is_same(insertStr))
				cout << "Already exist\n";		//���� chain�� ������ ���¿��� �̹� ������ ���ڿ��� �Է� �� ���� �ִٸ� exist���	
			else								//������ �Էµ� ���� ���� ���ڿ��̶�� ���� ��忡 ���ڿ��� �����Ϳ� �����ϰ� �Էµ� ����� ���� ����.
			{
				tempNode->setNext(currentNode);
				++cntSize;
			}
		}
		else						//������ �����͐l ������ ���ڿ� �Էµ� ���ڿ��� ù��° ���ڰ� �ٸ��ٸ� 
		{
			cout << "Not chained\n";
			return;
		}


	}


	return;
}

const void Link::print()
{
	int i = 0;
	Node* countNode = head;

	while (i < cntSize)				//�Էµ� ����� ���ڸ�ŭ chain ���
	{
		cout << countNode->getData() << "->";
		countNode = countNode->getNext();
		++i;
	}
	cout << '\n';
	return;
}


int main()
{
	Link node;
	char* insert = new char[100];		//���ڿ��� �Է¹޴� char *���� ũ�� 100���� �����Ҵ�

	

	while (true)
	{
		cout << "CMD(Word/exit) >> ";
		cin >> insert;
		if (strcmp(insert, "exit") == 0)
			break;

		node.insert(insert);
		node.print();
	}

	delete[] insert;


	return 0;
}