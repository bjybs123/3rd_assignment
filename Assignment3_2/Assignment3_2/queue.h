
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

		queue->rear = currentNode;
		queue->size++;
		return;
	}

	void Dequeue(queue* queue, int data)
	{
		Node* deleteNode;
		if (data > queue->size)
		{
			data = queue->size;
		}
		while (data-- > 0)
		{
			//BST	BST(queue->front)
			deleteNode = queue->front;
			queue->front = queue->front->getNext();
			delete deleteNode;

		}

	}

	const void print(queue* theQueue)
	{
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