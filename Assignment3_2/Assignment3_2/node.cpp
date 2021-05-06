

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