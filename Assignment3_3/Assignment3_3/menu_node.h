#pragma once
#include <iostream>

using namespace std;

int my_strcmp(char* str1, char* str2)			//대소문자 상관안하고 문자열의 크기를 반환하는 함수
{
	int i = 0;
	while (str2[i] != '\0' && str1[i] != '\0')
	{
		if (tolower(str1[i]) > tolower(str2[i]))		//모든 문자를 tolower함수를 이용해서 차를 반환한다. 
			return tolower(str1[i]) - tolower(str2[i]);
		else if (tolower(str1[i]) < tolower(str2[i]))
			return tolower(str1[i]) - tolower(str2[i]);
		++i;
	}
	if (strlen(str1) < strlen(str2))
	{
		return strlen(str1) - strlen(str2);				//만약에 문자열이 같은 경우에 한 문자열이 짧아서 while문이 끝나는 경우를 대비해서 짧은 문자열이 우선으로 되게 차를 반환한다.
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
	char* menu_name;		//메뉴의 이름을 저장하는 문자열
	int price;				//메뉴의 가격을 저장하는 변수
	menu_node* pPrev;		//그 전 노드를 가르치는 노드 포인터
	menu_node* pNext;		//그 다음 노드를 가르키는 노드 포인터.


public:
	menu_node();			//메뉴노드 생성자
	~menu_node();			//메뉴노드 소멸자
	char* getMenu();		//메뉴의 이름을 반환
	void setMenu(char*);	//메뉴의 이름을 저장
	int getPrice();			//메뉴의 가격을 반환
	void setPrice(int);		//메뉴의 가격을 저장
	menu_node* getPrev();	//현 노드의 previous노드를 반환
	void setPrev(menu_node*);	//previous노드를 저장
	menu_node* getNext();		//다음 노드 반환	
	void setNext(menu_node*);	//다음 노드 저장
	
};

class Link
{
private:
	menu_node *pHead;		//링크드리스트에서 처음 노드를 가르키는 노드 포인터
	int count;				//몇 개의 노드가 연결 되어있는지 세는 변수

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
	menu_node* currentNode = new menu_node();		//새로운 노드를 생성
	menu_node* tempNode = new menu_node();			//임시 노드 생성
	tempNode = pHead->getNext();					//임시 노드에 pHead가 가르키는 초기 노드를 저장.

	currentNode->setMenu(nameIn);					//새로운 노드에 메뉴의 이름과 가격을 저장.
	currentNode->setPrice(priceIn);

	if (pHead->getNext() == nullptr)				//임시노드가 가르키는 노드가 비어있으면 새로운노드를 저장
	{

		pHead->setNext(currentNode);
		currentNode->setPrev(pHead);
		count++;									//노드 개수 증가
	}
	else
	{
		while (tempNode != nullptr)
		{
			if (tempNode->getPrice() > priceIn)					//만약에 현재 노드의 가격이 새로 입력된 가격 보다 크다면
			{
				currentNode->setPrev(tempNode->getPrev());		//새로운 노드의 이전 노드를 임시 노드의 이전 노드를 저장
				tempNode->getPrev()->setNext(currentNode);		//임시노드 이전 노드의 다음 노드를 새로운 노드를 저장
				currentNode->setNext(tempNode);					//새로운 노드의 다음 노드를 임시 노드로 저장
				tempNode->setPrev(currentNode);					//임시노드의 이전 노드를 새로운 노드로 저장
				count++;
				break;
			}
			else if (tempNode->getPrice() < priceIn)			//만약에 현재 노드의 가격이 새로 입력된 가격 보다 작다면
			{
				if (tempNode->getNext() != nullptr)				// 다음 노드가 nullptr이면 그냥 다음 노드로 삽입
				{
					tempNode = tempNode->getNext();
				}	
				else
				{												//그렇지 않다면 임시노드의 다음 노드를 새로운 노드로 저장해주고 
					currentNode->setNext(tempNode->getNext());	//새로운 노드의 이전 노드를 임시노드로 다음 노드를 nullptr로 지정해준다.
					currentNode->setPrev(tempNode);
					tempNode->setNext(currentNode);
					count++;
					break;
				}
				
			}
			else if (tempNode->getPrice() == priceIn)			//만약 입력된 가격이 노드의 가격과 동일할 경우
			{
				if (strcmp(tempNode->getMenu(), nameIn) == 0)	//이름도 같을 경우는 무시해준다
					break;

				if (my_strcmp(tempNode->getMenu(), nameIn) > 0)	//가격이 동일할 경우는 이름순으로 만약에 임시노드의 이름이 더 크다면
				{
					currentNode->setPrev(tempNode->getPrev());	//임시노드를 뒤로 보내고 그 사이에 새로운 노드를 삽입한다.
					tempNode->getPrev()->setNext(currentNode);
					currentNode->setNext(tempNode);
					tempNode->setPrev(currentNode);
					count++;
					break;
				}
				else if (my_strcmp(tempNode->getMenu(), nameIn) < 0)	//가격이 동일할 경우 이름순으로 새로운 노드의 가격이 더 크다면
				{
					if (tempNode->getNext() != nullptr)					//다음 노드가 nullptr일 경우 그냥 삽입
					{
						tempNode = tempNode->getNext();
					}
					else
					{													//다은 노드가 존재한다면 다음 노드와 현재 노드에 새로운 노드를 삽입한다.
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
	tempNode = pHead->getNext();						//임시 노드를 만들어서 pHead가 가르키는 첫번째 노드를 저장해준다.
	while (tempNode != nullptr)							//만약에 현재 노드가 nullptr이 아닐 경우
	{
		cout << tempNode->getMenu();					//메뉴이름을 출력하고
		if (strlen(tempNode->getMenu()) < 8)
		{
			cout << "\t";								//tabspace를 고려해서 (tabspace를 크기 8으로 가정) 8보다 작을 경우는 tab을 하나 더 해준다
		}
		cout << "\t\t" << tempNode->getPrice() << "\n";	//메뉴의 가격을 출력해준다
		tempNode = tempNode->getNext();					//다음 노드를 저장해준다
	}
	
	delete tempNode;									//동적으로 생성된 메뉴노드 할당해제
}
void Link::search(char* searchName)
{
	menu_node* tempNode = new menu_node();				//모든 노드를 하나하나 검사할 노드 동적으로 생성
	tempNode = pHead->getNext();						//pHead의 첫번째 노드를 저장.

	while (tempNode != nullptr)							// 현재 노드가 nullptr이 아닐 경우
	{
		if (strcmp(tempNode->getMenu(), searchName) == 0)		//만약 현재 가르키는 노드와 입력 받은 이름과 일치하면
		{
			cout << "Price : " << tempNode->getPrice() << "\n";	//가격을 출력해주고 동적할당 된노드를 해데해주고 함수를 종료시킨다.
			delete tempNode;
			return;
		}
		tempNode = tempNode->getNext();
	}
	cout << "Not in menu\n";							//while문에서 함수종료가 이루어지지않았다면 문자열이 같은 노드가 
	delete tempNode;									//존재하지 않기때문에 존재하지 않다고 출력하고 함수를 종료한다.
	return;
}
void Link::delNode(char* delName)
{
	menu_node* tempNode = new menu_node();			//개별적으로 검사 할 임시 노드 생성
	tempNode = pHead->getNext();					// pHead의 첫번째 노드를 저장.

	while (tempNode != nullptr)						
	{
		if (strcmp(tempNode->getMenu(), delName) == 0)			//만약 입력된 문자열과 노드의 메뉴이릅과 일치하다면
		{
			menu_node* prevNode = new menu_node();				
			prevNode = tempNode->getPrev();						//그 전 노드를 새로운 노드에 저장하고
			tempNode = tempNode->getNext();						//임시 노드는 다음 노드를 가르키게 하고 그 사이를 지운다

			if (tempNode == nullptr)							// 다음 노드가 nullptr이라면
			{
				prevNode->setNext(nullptr);						//이전 노드의 다음 노드를 nullptr으로 저장하고 카운드를 감소 시킨다
				--count;
				return;
			}
			else
			{	
				tempNode->setPrev(prevNode);					//다은 노드가 존재한다면 다음 노드를 저장해주고 더음 노드의 이전 노드를 현재 노드로 저장해준다.
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