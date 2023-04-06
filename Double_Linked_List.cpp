#include<iostream>
using namespace std;

//Initialization Class 
class Node
{
private:
	int Data;
	Node* Prev;
	Node* Next;
public:
	Node(int);
	Node(int, Node*,Node*);
	int getValue();
	Node* getPrevious();
	Node* getNext();
	void setPrevious(Node*);
	void setNext(Node*);
};

class DoubleLinkedList
{
private:
	Node* Head;
	Node* Tail;
	int size;
public:
	DoubleLinkedList()
	{
		this->Head = NULL;
		this->Tail = NULL;
		size = 0;
	}
	void AddNode(int);
	void CreateList();
	void PrintList();
};

//Driver Code
int main()
{
	DoubleLinkedList list;
	list.CreateList();
	list.PrintList();
	return 0;
}
//Node Class Method Definition
Node::Node(int data)
{
	this->Data = data;
	this->Prev = NULL;
	this->Next = NULL;
}
Node::Node(int data, Node* prev, Node* next)
{
	// A->B
	this->Data = data;
	this->Prev = prev;
	this->Next = next;

	//A<-B
	next->setPrevious(this);
	prev->setNext(this);
}
int Node::getValue()
{
	return this->Data;
}
Node* Node::getPrevious()
{
	return this->Prev;
}
Node* Node::getNext()
{
	return this->Next;
}
void Node::setPrevious(Node* prev)
{
	this->Prev = prev;
	//prev->setNext(this);
}
void Node::setNext(Node* next)
{
	this->Next = next;
	//next->setPrevious(this);
}

//DoubleLL Class Method Definition
void DoubleLinkedList::AddNode(int data)
{
	// -4-  -4=5-
	Node* newNode = new Node(data);
	if (this->Head == NULL)
	{
		this->Head = newNode;
		this->Tail = this->Head;
		return;
	}
	else
	{
		this->Tail->setNext(newNode);
		newNode->setPrevious(this->Tail);
		this->Tail = newNode;
	}
}
void DoubleLinkedList::CreateList()
{
	int x;
	while (cin >> x)
	{
		if (x == 0)break;
		AddNode(x);
	}
}
void DoubleLinkedList::PrintList()
{
	Node* temp = Head;
	if (temp == NULL)
	{
		cout << "List Empty!" << endl;
		return;
	}
	for (Node* p = this->Head; p != NULL; p = p->getNext())
	{
		printf("%d -> ", p->getValue());
	}
	cout << endl;
	for (Node* p = this->Tail; p != NULL; p = p->getPrevious())
	{
		printf("%d <- ", p->getValue());
	}
	cout << endl;
}
