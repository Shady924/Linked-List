#include <iostream>
#include "DoublyLinkedList.h"
using namespace std; 


DoublyLinkedList::DoublyLinkedList() : head(nullptr), size(0) {}

DoublyLinkedList::~DoublyLinkedList() {
	if (head == nullptr) return; 
	Node* p = head; 
	while (p != nullptr) {
		Node* next = p->next;
		delete p; 
		p = next; 
	}
	head = nullptr; 
}

bool DoublyLinkedList::Isempty() const {
	return (head == NULL);
}

void DoublyLinkedList::InsertFirst(int newvalue) {
	this->size++; 
	Node* t = new Node();
	t->data = newvalue; 
	t->prev = NULL; 
	t->next = head; 
	if (!Isempty()) {
		head->prev = t; 
	}
	head = t; 
}


void DoublyLinkedList::Insert(int index, int newvalue){
	if (index >= 0 && index <= this->size) {
		this->size++; 
		if (index == 0) {
			InsertFirst(newvalue);
		}
		else {
			Node* p = head;
			Node* t = new Node();
			for (int i = 0; i < index -1 && p; i++) {
				p = p->next;
			}
			t->data = newvalue;
			t->prev = p;
			t->next = p->next; 
			if (p->next)
				p->next->prev = t; 
			p->next = t;
		}
	}
	else {
		cout << "Invalid index\n";
	}
}



void DoublyLinkedList::Append(int newvalue){
	if (Isempty()) {
		InsertFirst(newvalue);
	}
	else {
		Node* p = head;
		Node* t = new Node();
		while (p->next != NULL) {
			p = p->next; 
		}
		t->data = newvalue; 
		t->next = NULL; 
		t->prev = p; 
		p->next = t;		
		this->size++;
	}
}

int DoublyLinkedList::Delete(int index) {
	int x = -1; 
	if (!Isempty()) {
		if (index > 0 && index <= this->size) {
			this->size--;
			Node * p = head;
			if (index == 1) {
				head = head->next;
				x = p->data; 
				delete p;
				if(head)
					head->prev = NULL;
				return x; 
			}
			else {
				//Node* Previous, *Next; // p->prev = Previous , p->next = Next    from p  
				for (int i = 0; i < index ; i++) {
					p = p->next;
				}
				p->prev->next = p->next;
				if(p->next)
					p->next->prev = p->prev;
				x = p->data;
				delete p; 
				return x; 
			}
		}
		else {
			cout << "Invalid index\n";
			return x; 
		}
	}
	else {
		cout << "The list is empty\n"; 
		return x; 
	}
}


void DoublyLinkedList::Display() const {
	if (!Isempty()) {
		Node* p = head;
		for (int i = 0; i < size; i++) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	else {
		cout << "List is empty.\n";
	}
}

int DoublyLinkedList::Length() const {
	return this->size;
}


int DoublyLinkedList::Sum() const{
	int sum = 0;
	Node* temp = head;
	while (temp != NULL) {
		sum += temp->data;
		temp = temp->next;
	}
	return sum;
}

int DoublyLinkedList::Max() const{
	Node* temp = head;
	int Max = INT32_MIN;
	while (temp != NULL) {
		if (temp->data > Max)
			Max = temp->data;
		temp = temp->next;
	}
	return Max;
}

int DoublyLinkedList::Min() const{
	Node* temp = head;
	int Min = INT32_MAX;
	while (temp != NULL) {
		if (temp->data < Min)
			Min = temp->data;
		temp = temp->next;
	}
	return Min;
}

Node* DoublyLinkedList::Search(int key) const{
if (Isempty()) return NULL;

Node* temp = head;

while (temp != NULL) {
	if (temp->data == key)
		return temp;
	temp = temp->next;
}
return NULL;
}

bool DoublyLinkedList::issorted() const{
	if (head == NULL || head->next == NULL) {
		return true;
	}
	Node* p = head;
	int x = head->data;
	while (p != NULL) {
		if (x > p->data) {
			return false;
		}
		x = p->data;
		p = p->next;
	}
	return true;
}

void DoublyLinkedList::Removeduplicatesfromsorted(){
	if (head == NULL) return;
	Node* p = head;
	Node* q = p->next;
	while (q != NULL) {
		if (p->data != q->data) {
			p = q;
			q = q->next;
		}
		else {
			p->next = q->next;
			this->size--;
			delete q;
			q = p->next;
		}
	}
}

void DoublyLinkedList::Reverse() {
	if (head != NULL && head->next != NULL) {
		Node* p = head;
		Node* t = NULL;
		while (p != NULL) {
			t = p->next;	
			p->next = p->prev;
			p->prev = t;
			p = p->prev;
			if(p != NULL && p->next == NULL)
				head = p; 
		}
	}
	else {
		return;
	}
}

void DoublyLinkedList::concatenating2linkedlist(DoublyLinkedList* l2) {
	Node* p = head;
	if (l2 == NULL || l2->head == NULL) {
		return;
	}
	if (head == NULL) {
		head = l2->head;
		this->size = l2->size;
		l2->size = 0;
		l2->head = nullptr;
		return;
	}
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = l2->head;
	l2->head->prev = p;
	this->size += l2->size;
	l2->size = 0;
	l2->head = nullptr;
}

int DoublyLinkedList::MidleLinkedList() {
	if (Isempty()) {
		return -1;
	}
	Node* p, * q;
	p = q = head;
	while (q != NULL) {
		q = q->next;
		if (q != NULL) q = q->next;
		if (q != NULL) p = p->next;
	}
	return p->data;
}