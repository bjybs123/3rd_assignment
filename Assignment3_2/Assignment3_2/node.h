#pragma once
class Node
{
private:
	int data;							//���  ���ڿ� �����͸� ������ ����
	Node* next;							//���� ��带 ������ ���
public:
	Node()			//������
	{
		data = 0;
		next = nullptr;					//���� ��带 ����Ű�� �����͸� nullptr�� �ʱ�ȭ
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