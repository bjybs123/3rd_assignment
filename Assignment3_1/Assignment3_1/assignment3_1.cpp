#include <iostream>

using namespace std;
		
char* my_strcpy(char* destination, const char* source)		//문자열 복사 함수 구현
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
void* my_strcpy_low(char* destination, char* source)		//lowercase 문자열 복사 함수
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
	char* data;							//노드  문자열 데이터를 저장할 공간
	Node* next;							//다음 노드를 저장할 노드
public:
	Node()			//생성자
	{
		data = new char[100];			//생성자를 통해 문자열 데이터를 100크기로 동적할당
		next = nullptr;					//다음 노드를 가르키는 포인터를 nullptr로 초기화
	}
	~Node()			//소멸자
	{
		delete[] data;//동적할당 받은 data 문자열 동적 해제
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
	int cntSize = 0;			//몇개의 노드가 연결되어 있는지 카운팅 하는 변수
public:
	Node* head;				//해드 노드 
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

	char* lowerCase = new char[100];			//lowercase로 변환된 문자열을 저장
	char* lowerCaseIserted = new char[100];		

	while (tempNode->getNext() != nullptr)			//tempNode를 노드의 처음인 head를 가르키고 그 다음 노드들으로 이동하면서 nullptr전까지 검사
	{
		my_strcpy_low(lowerCase, tempNode->getData());
		my_strcpy_low(lowerCaseIserted, insertStr);

		if (strcmp(lowerCase, lowerCaseIserted) == 0)
			return true;			//만약같은 문자열이 발견되면 true 반환
		tempNode = tempNode->getNext();	//다음 노드로 포인팅
	}

	delete[] lowerCase;
	delete[] lowerCaseIserted;

	return false;
}	   //대소문자 구분 없이 그 전 노드 데이머와 입력된 문자열이 같은것이 있는지 판별 함수

void Link::insert(char* insertStr)
{
	Node* currentNode = new Node;
	currentNode->setData(insertStr);

	if (head == nullptr)			//처음 노드는 비교할 필요 없이 발  
	{
		head = currentNode;
		++cntSize;
	}
	else						//첫 노드가 아니라면
	{
			//현재 노드를 새로 할당
		Node* tempNode = head;				//임시 노드를 만들어 head를 가르킴
		while (tempNode->getNext() != nullptr)	//끝에 있는 노드의 데이터를 접근하기위해 마지막 노드로 접근
			tempNode = tempNode->getNext();



		if (tolower(tempNode->getData()[strlen(tempNode->getData()) - 1]) == tolower(*insertStr))		//만약 마지막 데이터의 마지막 문자와 입련된 문자열 첫번째 문자가 같다면
		{
			if (is_same(insertStr))
				cout << "Already exist\n";		//만약 chain이 가능한 상태에서 이미 동일한 문자열이 입력 된 적이 있다면 exist출력	
			else								//그전에 입력된 적이 없는 문자열이라면 현재 노드에 문자열을 데이터에 복사하고 입력된 노드의 수를 증가.
			{
				tempNode->setNext(currentNode);
				++cntSize;
			}
		}
		else						//마지막 데이터릐 마지만 문자와 입력된 문자열의 첫번째 문자가 다르다면 
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

	while (i < cntSize)				//입력된 노드의 숫자만큼 chain 출력
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
	char* insert = new char[100];		//문자열을 입력받는 char *변수 크기 100으로 동적할당

	

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