#pragma once
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <crtdbg.h>

#define SUITS 4
#define FACES 13

using namespace std;

void cardCat(char* card, const char* suit, const char* face)
{
    int i, j, k;
    j = k = i = 0;

    while (suit[i] != '\0')
    {
        card[i] = suit[i];
        ++i;
    }
    while (face[j] != '\0')
    {
        card[i] = face[j];
        ++j;
        ++i;
    }
    card[i] = '\0';
}

class Node
{
private:
	Node* next;
    char* card;

public:
    Node();
    ~Node();
    Node* getNext();
    void setNext(Node*);
    char* getCard();
    void setCard(const char*, const char*);
    void setCard(char*);
};

class Link
{
private:
    Node* pHead;
    int count;

public:
    Link();
    Node* getHead();

    void setHead(Node*);
    int getCount();
    void insert(const char*, const char*);
    void insert(char* nameIn);
    void delNode(char*);
    void print()
    {
        Node* tempNode = new Node();
        tempNode = pHead;

        while (tempNode != nullptr)
        {
            cout << "--> " << tempNode->getCard() << "\n";
            tempNode = tempNode->getNext();
        }
    }
    void initial();
    void place_discard(Link* discardIn, Link* dealerIn);
    void shuffle(Link* dealerIn);
    void pick(Link*);
};

//Link's method functions
Link::Link()
{
    pHead = nullptr;
    count = 0;
}
int Link::getCount()
{
    return count;
}
void Link::initial()
{
    int i, j;
    const char* suit[SUITS] = { "H", "D", "C", "S" };
    const char* face[FACES] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
    
    for (i = 0; i < SUITS; ++i)
        for (j = 0; j < FACES; ++j)
            insert(suit[i], face[j]);

}
void Link::insert(const char* suit, const char* face)
{
    Node* currentNode = new Node();
    Node* tempNode;
    currentNode->setCard(suit, face);

    if (pHead == nullptr)
    {
        pHead = currentNode;
        ++count;
    }
    else
    {
        tempNode = pHead;
        while (tempNode != nullptr)
        {
            if (tempNode->getNext() == nullptr)
            {
                tempNode->setNext(currentNode);
                ++count;
                break;
            }
            else
                tempNode = tempNode->getNext();
        }

    }
}
void Link::insert(char* nameIn)
{
    Node* currentNode = new Node();
    Node* tempNode;
    currentNode->setCard(nameIn);

    if (pHead == nullptr)
    {
        pHead = currentNode;
        ++count;
    }
    else
    {
        tempNode = pHead;
        while (tempNode != nullptr)
        {
            if (tempNode->getNext() == nullptr)
            {
                tempNode->setNext(currentNode);
                ++count;
                break;
            }
            else
                tempNode = tempNode->getNext();
        }

    }
}
void Link::delNode(char* cardIn)
{
    Node* prevNode = nullptr;
    Node* currNode = pHead;
    while (currNode && (strcmp(currNode->getCard(), cardIn) != 0))
    {
        prevNode = currNode;
        currNode = currNode->getNext();
    }
    if (currNode)
    {
        if (prevNode)
        {
            prevNode->setNext(currNode->getNext());
            delete currNode;
            --count;
        }
        else
        {
            pHead = currNode->getNext();
            delete currNode;
            --count;
        }
    }
    
}
Node* Link::getHead()
{
    return pHead;
}
void Link::setHead(Node* pNode)
{
    pHead = pNode;
}
void Link::place_discard(Link* discardIn, Link* dealerIn)
{

    Node* prevNode = nullptr;
    Node* curNode = nullptr;
    Node* tempHead = pHead;
    Node* deleteNode;
    if (discardIn == nullptr)
    {
        cout << "discard is empty\n";
    }
    else
    {
        while (discardIn->getHead() != nullptr)
        {
            Node* newNode = new Node();
            newNode->setCard(discardIn->getHead()->getCard());

            deleteNode = discardIn->getHead();

            if (prevNode == nullptr)
            {
                pHead = newNode;
                curNode = newNode;
                ++count;
            }
            else
            {
                curNode->setNext(newNode);
                curNode = curNode->getNext();
                ++count;
            }
            //frontInsert(discardIn->getHead()->getCard());
            prevNode = discardIn->getHead();
            discardIn->getHead()->setNext(discardIn->getHead()->getNext());             //다음 노드 이동
            discardIn->delNode(deleteNode->getCard());
        }
        curNode->setNext(tempHead);
    }

    srand((unsigned int)time(NULL));

    int Num = rand() % count; //널 문자 전까지 
    Num = 10;
    Node* movingNode = pHead;
    while (movingNode && (Num > 0))
    {
        if (movingNode->getNext() != nullptr)
        {
            movingNode = movingNode->getNext();
            --Num;
        }
    }

    while (movingNode)
    {
        if (movingNode->getNext() != nullptr)
        {
            Node* deleteNode = movingNode;
            dealerIn->insert(movingNode->getCard());
            movingNode = movingNode->getNext();
            delNode(deleteNode->getCard());
            
        }
        else if (movingNode->getNext() == nullptr)
        {
            Node* deleteNode = movingNode;
            dealerIn->insert(movingNode->getCard());
            delNode(deleteNode->getCard());
            break;
        }
    }

    
}
void Link::shuffle(Link* dealerIn)
{
    int Num;
    Node* movingNode;
    Node* prevNode = nullptr;
    Node* curNode = nullptr;
    Node* tempHead = pHead;
    Node* deleteNode;
    Num = rand() % dealerIn->count;
    cout << "Moving !!! : " << Num << "\n";
    movingNode = pHead;
    while (dealerIn->getHead() != nullptr && (Num > 0))
    {
        Node* newNode = new Node();
        newNode->setCard(dealerIn->getHead()->getCard());

        deleteNode = dealerIn->getHead();

        if (prevNode == nullptr)
        {
            pHead = newNode;
            curNode = newNode;
            ++count;
            --Num;
        }
        else
        {
            curNode->setNext(newNode);
            curNode = curNode->getNext();
            ++count;
            --Num;
        }
        //frontInsert(discardIn->getHead()->getCard());
        prevNode = dealerIn->getHead();
        dealerIn->getHead()->setNext(dealerIn->getHead()->getNext());             //다음 노드 이동
        dealerIn->delNode(deleteNode->getCard());
    }
    curNode->setNext(tempHead);
}
void Link::pick(Link*)
{

}


//Node's method functions
Node::Node()
{
    next = nullptr;
    card = new char[4];
    
}
Node::~Node()
{
    delete[] card;
}
char* Node::getCard()
{
    return card;
}
void Node::setCard(const char* suit, const char* face)
{
    cardCat(card, suit, face);
}
Node* Node::getNext()
{
    return next;
}
void Node::setNext(Node* pNode)
{
    next = pNode;
}
void Node::setCard(char* nameIn)
{
    int i = 0;
    while (nameIn[i] != '\0')
    {
        card[i] = nameIn[i];
        ++i;
    }
    card[i] = '\0';
}