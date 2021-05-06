#pragma once
#include <iostream>

using namespace std;

int my_strcmp(char* str1, char* str2)			//��ҹ��� ������ϰ� ���ڿ��� ũ�⸦ ��ȯ�ϴ� �Լ�
{
	int i = 0;
	while (str2[i] != '\0' && str1[i] != '\0')
	{
		if (tolower(str1[i]) > tolower(str2[i]))		//��� ���ڸ� tolower�Լ��� �̿��ؼ� ���� ��ȯ�Ѵ�. 
			return tolower(str1[i]) - tolower(str2[i]);
		else if (tolower(str1[i]) < tolower(str2[i]))
			return tolower(str1[i]) - tolower(str2[i]);
		++i;
	}
	if (strlen(str1) < strlen(str2))
	{
		return strlen(str1) - strlen(str2);				//���࿡ ���ڿ��� ���� ��쿡 �� ���ڿ��� ª�Ƽ� while���� ������ ��츦 ����ؼ� ª�� ���ڿ��� �켱���� �ǰ� ���� ��ȯ�Ѵ�.
	}
	else if (strlen(str1) > strlen(str2))
	{
		return strlen(str1) - strlen(str2);
	}
	else
		return 0;
}

class menu_node
{
private:
	char* menu_name;		//�޴��� �̸��� �����ϴ� ���ڿ�
	int price;				//�޴��� ������ �����ϴ� ����
	menu_node* pPrev;		//�� �� ��带 ����ġ�� ��� ������
	menu_node* pNext;		//�� ���� ��带 ����Ű�� ��� ������.


public:
	menu_node();			//�޴���� ������
	~menu_node();			//�޴���� �Ҹ���
	char* getMenu();		//�޴��� �̸��� ��ȯ
	void setMenu(char*);	//�޴��� �̸��� ����
	int getPrice();			//�޴��� ������ ��ȯ
	void setPrice(int);		//�޴��� ������ ����
	menu_node* getPrev();	//�� ����� previous��带 ��ȯ
	void setPrev(menu_node*);	//previous��带 ����
	menu_node* getNext();		//���� ��� ��ȯ	
	void setNext(menu_node*);	//���� ��� ����
	
};

class Link
{
private:
	menu_node *pHead;		//��ũ�帮��Ʈ���� ó�� ��带 ����Ű�� ��� ������
	int count;				//�� ���� ��尡 ���� �Ǿ��ִ��� ���� ����

public:
	Link();
	~Link();
	void print();
	void insert(char*, int);
	void search(char*);
	void delNode(char*);
	int getCount();
};


//menu_node's method functions
menu_node::menu_node()
{
	menu_name = new char[100];
	price = 0;
	pNext = nullptr;
	pPrev = nullptr;
}
menu_node::~menu_node()
{
	delete[] menu_name;
}
char* menu_node::getMenu()
{
	return menu_name;
}
void menu_node::setMenu(char* menuIn)
{
	int i = 0;

	while (menuIn[i] != '\0')
	{
		menu_name[i] = menuIn[i];
		++i;
	}
	menu_name[i] = '\0';

	return;
}
int menu_node::getPrice()
{
	return price;
}
void menu_node::setPrice(int priceIn)
{
	price = priceIn;
}
menu_node* menu_node::getPrev()
{
	return pPrev;
}
void menu_node::setPrev(menu_node* nodeIn)
{
	pPrev = nodeIn;
}
menu_node* menu_node::getNext()
{
	return pNext;
}
void menu_node::setNext(menu_node* nodeIn)
{
	pNext = nodeIn;
}


//Link's method functions
Link::Link()
{
	pHead = new menu_node();
	count = 0;
}
Link::~Link()
{
	delete pHead;
}
int Link::getCount()
{
	return count;
}
void Link::insert(char* nameIn, int priceIn)
{
	menu_node* currentNode = new menu_node();		//���ο� ��带 ����
	menu_node* tempNode = new menu_node();			//�ӽ� ��� ����
	tempNode = pHead->getNext();					//�ӽ� ��忡 pHead�� ����Ű�� �ʱ� ��带 ����.

	currentNode->setMenu(nameIn);					//���ο� ��忡 �޴��� �̸��� ������ ����.
	currentNode->setPrice(priceIn);

	if (pHead->getNext() == nullptr)				//�ӽó�尡 ����Ű�� ��尡 ��������� ���ο��带 ����
	{

		pHead->setNext(currentNode);
		currentNode->setPrev(pHead);
		count++;									//��� ���� ����
	}
	else
	{
		while (tempNode != nullptr)
		{
			if (tempNode->getPrice() > priceIn)					//���࿡ ���� ����� ������ ���� �Էµ� ���� ���� ũ�ٸ�
			{
				currentNode->setPrev(tempNode->getPrev());		//���ο� ����� ���� ��带 �ӽ� ����� ���� ��带 ����
				tempNode->getPrev()->setNext(currentNode);		//�ӽó�� ���� ����� ���� ��带 ���ο� ��带 ����
				currentNode->setNext(tempNode);					//���ο� ����� ���� ��带 �ӽ� ���� ����
				tempNode->setPrev(currentNode);					//�ӽó���� ���� ��带 ���ο� ���� ����
				count++;
				break;
			}
			else if (tempNode->getPrice() < priceIn)			//���࿡ ���� ����� ������ ���� �Էµ� ���� ���� �۴ٸ�
			{
				if (tempNode->getNext() != nullptr)				// ���� ��尡 nullptr�̸� �׳� ���� ���� ����
				{
					tempNode = tempNode->getNext();
				}	
				else
				{												//�׷��� �ʴٸ� �ӽó���� ���� ��带 ���ο� ���� �������ְ� 
					currentNode->setNext(tempNode->getNext());	//���ο� ����� ���� ��带 �ӽó��� ���� ��带 nullptr�� �������ش�.
					currentNode->setPrev(tempNode);
					tempNode->setNext(currentNode);
					count++;
					break;
				}
				
			}
			else if (tempNode->getPrice() == priceIn)			//���� �Էµ� ������ ����� ���ݰ� ������ ���
			{
				if (strcmp(tempNode->getMenu(), nameIn) == 0)	//�̸��� ���� ���� �������ش�
					break;

				if (my_strcmp(tempNode->getMenu(), nameIn) > 0)	//������ ������ ���� �̸������� ���࿡ �ӽó���� �̸��� �� ũ�ٸ�
				{
					currentNode->setPrev(tempNode->getPrev());	//�ӽó�带 �ڷ� ������ �� ���̿� ���ο� ��带 �����Ѵ�.
					tempNode->getPrev()->setNext(currentNode);
					currentNode->setNext(tempNode);
					tempNode->setPrev(currentNode);
					count++;
					break;
				}
				else if (my_strcmp(tempNode->getMenu(), nameIn) < 0)	//������ ������ ��� �̸������� ���ο� ����� ������ �� ũ�ٸ�
				{
					if (tempNode->getNext() != nullptr)					//���� ��尡 nullptr�� ��� �׳� ����
					{
						tempNode = tempNode->getNext();
					}
					else
					{													//���� ��尡 �����Ѵٸ� ���� ���� ���� ��忡 ���ο� ��带 �����Ѵ�.
						currentNode->setNext(tempNode->getNext());
						currentNode->setPrev(tempNode);
						tempNode->setNext(currentNode);
						count++;
						break;
					}
					
				}
			}
		}
		
	}
	
}
void Link::print()
{
	menu_node* tempNode = new menu_node();
	tempNode = pHead->getNext();						//�ӽ� ��带 ���� pHead�� ����Ű�� ù��° ��带 �������ش�.
	while (tempNode != nullptr)							//���࿡ ���� ��尡 nullptr�� �ƴ� ���
	{
		cout << tempNode->getMenu();					//�޴��̸��� ����ϰ�
		if (strlen(tempNode->getMenu()) < 8)
		{
			cout << "\t";								//tabspace�� ����ؼ� (tabspace�� ũ�� 8���� ����) 8���� ���� ���� tab�� �ϳ� �� ���ش�
		}
		cout << "\t\t" << tempNode->getPrice() << "\n";	//�޴��� ������ ������ش�
		tempNode = tempNode->getNext();					//���� ��带 �������ش�
	}
	
	delete tempNode;									//�������� ������ �޴���� �Ҵ�����
}
void Link::search(char* searchName)
{
	menu_node* tempNode = new menu_node();				//��� ��带 �ϳ��ϳ� �˻��� ��� �������� ����
	tempNode = pHead->getNext();						//pHead�� ù��° ��带 ����.

	while (tempNode != nullptr)							// ���� ��尡 nullptr�� �ƴ� ���
	{
		if (strcmp(tempNode->getMenu(), searchName) == 0)		//���� ���� ����Ű�� ���� �Է� ���� �̸��� ��ġ�ϸ�
		{
			cout << "Price : " << tempNode->getPrice() << "\n";	//������ ������ְ� �����Ҵ� �ȳ�带 �ص����ְ� �Լ��� �����Ų��.
			delete tempNode;
			return;
		}
		tempNode = tempNode->getNext();
	}
	cout << "Not in menu\n";							//while������ �Լ����ᰡ �̷�������ʾҴٸ� ���ڿ��� ���� ��尡 
	delete tempNode;									//�������� �ʱ⶧���� �������� �ʴٰ� ����ϰ� �Լ��� �����Ѵ�.
	return;
}
void Link::delNode(char* delName)
{
	menu_node* tempNode = new menu_node();			//���������� �˻� �� �ӽ� ��� ����
	tempNode = pHead->getNext();					// pHead�� ù��° ��带 ����.

	while (tempNode != nullptr)						
	{
		if (strcmp(tempNode->getMenu(), delName) == 0)			//���� �Էµ� ���ڿ��� ����� �޴��̸��� ��ġ�ϴٸ�
		{
			menu_node* prevNode = new menu_node();				
			prevNode = tempNode->getPrev();						//�� �� ��带 ���ο� ��忡 �����ϰ�
			tempNode = tempNode->getNext();						//�ӽ� ���� ���� ��带 ����Ű�� �ϰ� �� ���̸� �����

			if (tempNode == nullptr)							// ���� ��尡 nullptr�̶��
			{
				prevNode->setNext(nullptr);						//���� ����� ���� ��带 nullptr���� �����ϰ� ī��带 ���� ��Ų��
				--count;
				return;
			}
			else
			{	
				tempNode->setPrev(prevNode);					//���� ��尡 �����Ѵٸ� ���� ��带 �������ְ� ���� ����� ���� ��带 ���� ���� �������ش�.
				prevNode->setNext(tempNode);
				--count;
				return;
			}
		}
		tempNode = tempNode->getNext();
	}
	cout << "menu_node : Not in menu\n";							
	return;
}