#include <iostream>

#include "CircularDoublyLinkedList.h"

using namespace std;

CircularDoublyLinkedList::CircularDoublyLinkedList() : head(nullptr), size(0) {}

CircularDoublyLinkedList::~CircularDoublyLinkedList() {
	if (head == nullptr) return;

	Node* tail = head->prev; 
	tail->next = nullptr;
	head->prev = nullptr; 

	Node* p = head; 
	while (p != nullptr) {
		Node* next = p->next; 
		delete p;
		p = next; 
	}
	head = nullptr; 
}


bool CircularDoublyLinkedList::Isempty() const {
	return (head == nullptr);
}

void CircularDoublyLinkedList::InsertFirst(int newvalue) {
	Node* p = new Node();
	this->size++;
	p->data = newvalue; 
	if (Isempty()) {
		p->next = p;
		p->prev = p; 
		head = p; 
	}
	else {
		Node* q = head->prev;
		p->next = head; 
		p->prev = q;	
		q->next = p; 
		head->prev = p; 
		head = p; 
	}
}

void CircularDoublyLinkedList::Insert(int index, int newvalue) {
	if (index >= 0 && index <= this->size) {
		if (index == 0) {
			InsertFirst(newvalue);
			return;
		}
		else {
			Node* p = head; 
			Node* newnode = new Node();
			newnode->data = newvalue; 
			this->size++;
			for (int i = 0; i < index-1 ; i++) p = p->next;
			newnode->prev = p; 
			newnode->next = p->next;
			p->next->prev = newnode; 
			p->next = newnode; 
		}
	}
}

void CircularDoublyLinkedList::Append(int newvalue) {
	if (Isempty()){
		InsertFirst(newvalue);
		return; 
	}
	this->size++;
	Node* p = head->prev; 
	Node* newnode = new Node();
	newnode->data = newvalue; 
	newnode->next = p->next;
	newnode->prev = p; 
	p->next->prev = newnode;
	p->next = newnode;
}

int CircularDoublyLinkedList::Delete(int index) {
	int x = -1;
	if (Isempty() || head == nullptr) {
		return x;
	}

	if (index < 1 || index > this->size) {
		return x; 
	}

		Node* p = head;
		if (index == 1) {
			x = head->data; 
			if (this->size == 1) {
				delete head;
				head = nullptr;
			}
			else {
				p = head->prev;
				p->next = head->next;
				head->next->prev = p;
				delete head;
				head = p->next;
			}
		}
		else {
			for (int i = 1; i < index; i++)p = p->next;
			p->prev->next = p->next;
			p->next->prev = p->prev;
			x = p->data;
			delete p; 
		}
	
	this->size--;
	return x; 
}



void CircularDoublyLinkedList::Display() const {
	if (Isempty()) return;
	
	Node* p = head; 
	do {
		cout << p->data << " "; 
		p = p->next;
	} while (p != head);
	cout << endl; 
}

int CircularDoublyLinkedList::Length() const {
	return this->size; 
}

int CircularDoublyLinkedList::Sum() const {
	if (Isempty()) return 0; 
	int sum = 0;
	Node* p = head; 
	do {
		sum += p->data; 
		p = p->next; 
	}while (p != head);

	return sum; 
}

int CircularDoublyLinkedList::Max() const {
	if (Isempty()) return INT32_MIN;

	int max = INT32_MIN;
	Node* p = head;
	do {
		if (p->data > max)
			max = p->data;
		p = p->next;
	} while (p != head);

	return max;
}

int CircularDoublyLinkedList::Min() const {
	if (Isempty()) return INT32_MAX;

	int min = INT32_MAX;
	Node* p = head;
	do {
		if (p->data < min)
			min = p->data;
		p = p->next;
	} while (p != head);

	return min;
}

Node* CircularDoublyLinkedList::Search(int key) const {
	if (Isempty()) return NULL;

	Node* p = head;
	do {
		if (p->data == key) {
			return p;
		}
		p = p->next;
	} while (p != head);

	return NULL;
}

bool CircularDoublyLinkedList::issorted() const {
	if (Isempty() || head->next == head) return 1; 
	int x = head->data; 
	Node* p = head->next; 
	do {
		if (x > p->data) return 0; 
		x = p->data; 
		p = p->next;
	} while (p != head);
	return 1; 
}

void CircularDoublyLinkedList::concatenating2linkedlist(CircularDoublyLinkedList* l2) {
	if (l2->Isempty()){
		return;
	}

	if (Isempty()) {
		head = l2->head;
		this->size = l2->size;
		l2->size = 0;
		l2->head = nullptr;
		return; 
	}

	Node* last1 = head->prev;
	Node* last2 = l2->head->prev;

	last1->next = l2->head;
	l2->head->prev = last1;
	last2->next = head;
	head->prev = last2; 
	
	this->size += l2->size; 
	l2->size = 0;
	l2->head = nullptr;

}

void CircularDoublyLinkedList::Removeduplicatesfromsorted() {
	if (head == nullptr || head->next == head)return;

	Node* p = head;
	do{
		Node* q = p->next;
		bool duplicateFound = false;

		while (q != head && p->data == q->data) {
			p->next = q->next;
			q->next->prev = p;
			this->size--;
			delete q;
			q = p->next;
			duplicateFound = true;
		}
		if (!duplicateFound) {
			p = p->next;
		}	
	}while (p != head);
}

void CircularDoublyLinkedList::Reverse() {
	if (head == nullptr || head->next == head)return; 

	Node* p = head; 
	Node* t = p->next;

	do{
		p->next = p->prev;
		p->prev = t;
		p = t;
		t = p->next;
	
	}while (p != head);

	head = p->next; 
}



int CircularDoublyLinkedList::MidleLinkedList() {
	if (Isempty())
		return -1; 
	Node* p,* q;
	p = q = head; 
	do {
		q = q->next;
		if (q != head)q = q->next; 
		if (q != head)p = p->next;
	} while (q != head);

	return p->data;
}
