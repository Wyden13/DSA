#include<iostream>
using namespace std;
class Node
{
private:
	int Data;
	Node* Next;
public:
	Node(int data)
	{
		this->Data = data;
		this->Next = NULL;
	}
	Node(int data,Node*next)
	{
		this->Data = data;
		this->Next = next;
	}
	int getValue();
	Node* getNext();
	void setNext(Node*);
};

class LinkedList
{
private:
	Node* Head;
	Node* Tail;
	int size;
public:
	LinkedList()
	{
		this->Head = NULL;
		this->Tail = NULL;
		size = 0;
	}
	void AddHead(int);
	void AddTail(int);
	void CreateList();
	void InsertNode(int,Node*,Node*);
	void PrintList();
	Node* FindNode(int);
};

//Driver CODE
int main()
{
	LinkedList list;
	list.CreateList();
	list.PrintList();
	int pos; cin >> pos;
	Node* p = new Node(5);
	Node* q = list.FindNode(pos);
	list.InsertNode(pos, q, p);
	list.PrintList();
	return 0;
}

// Function Definition

//Node Class Method Definition
int Node::getValue()
{
	return this->Data;
}
Node* Node::getNext()
{
	return this->Next;
}
void Node::setNext(Node*next)
{
	this->Next = next;
}

//LinkedList Class Method Definition
void LinkedList::AddHead(int data)
{
	Node* newNode = new Node(data);
	if (Head == NULL)
	{
		this->Head = newNode;
		this->Tail = this->Head;
		return;
	}
	else
	{
		*newNode = Node(data, Head);
		this->Head = newNode;
	}
}
void LinkedList::AddTail(int data)
{
	Node* newNode = new Node(data);
	if (Head == NULL)
	{
		this->Head = newNode;
		this->Tail = this->Head;
		return;
	}
	else
	{
		this->Tail->setNext(newNode);
		this->Tail = newNode;
	}
}
Node* LinkedList::FindNode(int pos)
{
	int count = 0;
	for (Node* p = this->Head; p != NULL; p = p->getNext())
	{
		count++;
		if (pos == count) return p;
	}
}
void LinkedList::InsertNode(int x,Node*Q,Node*p)
{
	// 1 2 3 _ 6 7 <- 5 x=4 3
	//newNode->Next=Next[3];
	//Next[3] = newNode;

	if (Q != NULL)
	{
		p->setNext(Q->getNext());
		Q->setNext(p);
		if (this->Tail == Q)
			this->Tail = p;
	}
	else
	{
		AddHead(p->getValue());
	}
}
void LinkedList::CreateList()
{
	int x;
	while (cin >> x)
	{
		if (x == -1)break;
		AddTail(x);
	}
}
void LinkedList::PrintList()
{
	Node* temp = Head;
	if (temp == NULL)
	{
		cout << "List empty!" << endl;
		return;
	}
	for (Node* p = Head; p != NULL; p = p->getNext())
	{
		size++;
		printf("%d -> ", p->getValue());
	}
	cout << endl;

	//printf("\nlength of the list: %d", size);
}
