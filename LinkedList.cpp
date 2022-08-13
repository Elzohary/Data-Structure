#include<iostream>
using namespace std;


class Node
{
public:
	// Attributes:
	int value;
	Node* next;

	// Constructors:
	Node()
	{
		value = 0;
		next = nullptr;
	}

	Node(int value, Node* next)
	{
		this->value = value;
		this->next = next;
	}
};


class LinkedList
{
	// Attribute:
	Node* head;

public:
	// Constructor:
	LinkedList()
	{
		head = nullptr;
	}

	// Methods
	void addToFirst(int value)
	{
		Node* n = new Node();
		n->value = value;
		n->next = head;

		head = n;
	}

	void removeFromFirst()
	{
		if (head = nullptr) return;		// In case if the LinkedList is already empty.

		head = head->next;
	}

	void addToLast(int value)
	{
		if (head == nullptr)	// In case if the LikedList is Empty.
		{
			addToFirst(value);
			return;
		}

		Node* n = new Node();
		n->value = value;
		n->next = nullptr;

		// Finding the last node @ the LinkedList to make its pointer point to the new node.
		Node* p = head;
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = n;
	}

	void removeFromLast()
	{
		if (head == nullptr) return; // In case if the LikedList is Empty.

		if (head->next == nullptr)	// In case if the LinkedList contains only one node.
		{
			delete head;
			head = nullptr;
			return;
		}

		Node* p = head;
		Node* parent = head;

		while (p->next != nullptr)
		{
			parent = p;
			p = p->next;
		}
		delete p;
		parent->next = nullptr;
	}

	void print()
	{
		Node* p = head;
		while (p != nullptr)
		{
			cout << p->value << endl;
			p = p->next;
		}
		cout << "\n============\n";
	}
};




int main()
{
	LinkedList myList;

	myList.addToFirst(10);
	myList.addToFirst(20);
	myList.addToFirst(30);
	myList.addToFirst(40);

	myList.removeFromLast();

	myList.print();
}