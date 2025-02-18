#include "CircularLinkedList.h"
#include <iostream>
using namespace std;

CircularLinkedList::CircularLinkedList() : head(nullptr) , size(0) {}

bool CircularLinkedList::Isempty() const {
	return (head == NULL);
}


int CircularLinkedList::Length() const {
	return this->size;
}

void CircularLinkedList::InsertFirst(int newvalue) {
	Node* newnode = new Node();
	newnode->data = newvalue;
	this->size++; 
	if (Isempty()) {
		head = newnode;
		newnode->next = head;
	}
	else {
		Node* q = head;
		do {
			q = q->next;
		} while (q->next != head);
		q->next = newnode;
		newnode->next = head;
		head = newnode;
	}

}

void CircularLinkedList::Insert(int index, int newvalue) {
	if (index >= 0 && index <= this->size) {
		if (index == 0) { 
			InsertFirst(newvalue);
			return;
		}
		this->size++;
		Node* temp = head;
		int pos = 0;
		do{
			pos++;
			temp = temp->next;
		} while (temp != head && pos < index -1 );
		if (temp) {
			Node* newnode = new Node();
			newnode->data = newvalue;
			newnode->next = temp->next;
			temp->next = newnode;
		}
	}
	else {
		cout << "valid index\n";
	}
}

void CircularLinkedList::Append(int newvalue) {
	if (Isempty()) {
		InsertFirst(newvalue);
	}
	else {
		this->size++;
		Node* temp = head;
		do{
			temp = temp->next;
		} while (temp->next != head);
		Node* newnode = new Node();
		newnode->data = newvalue;
		newnode->next = head;
		temp->next = newnode;
	}
}

	int CircularLinkedList::Delete(int index) {
		int x = -1;
		if (index > 0 && index <= this->size) {
			this->size--; 
			Node* p = head;
			Node* q = NULL;
			if (index == 1) {
				while (p->next != head) {
					p = p->next;
				}
				x = head->data;
				if (p == head) {
					delete head;
					head = NULL;
				}
				else {
					p->next = head->next;
					delete head;
					head = p->next;
				}
			}
			else {
				for (int i = 0; i < index - 2; i++) {
					p = p->next;
				}
				q = p->next;
				x = q->data;
				p->next = q->next;
				delete q;
			}

			return x;
		}
		else {
			return x;
		}
	}


void CircularLinkedList::Display() const {
	if (Isempty()) return;
	
		Node* p = head;
		do {
			cout << p->data << " ";
			p = p->next;
		} while (p != head);
		cout << endl;
	
}

int CircularLinkedList::Sum() const {
	if (Isempty()) return 0;

	int sum = 0;
	Node* p = head;
	do {
		sum+= p->data;
		p = p->next;
	} while (p != head);
	return sum;
}


int CircularLinkedList::Max() const {
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

int CircularLinkedList::Min() const {
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

Node* CircularLinkedList::Search(int key) const {
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

bool CircularLinkedList::issorted() const {
	if (head == NULL || head->next == head) return true;

	Node* p = head;
	do{
		if (p->data > p->next->data) {  
			return false;  
		}
		p = p->next;
	} while (p->next != head);

	return true; 
}

void CircularLinkedList::Removeduplicatesfromsorted() {
	if (head == NULL || head->next == head) return;

	Node* p = head; 
	Node* q = head->next;
	while (q != head){
		if (p->data != q->data ) {
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

void CircularLinkedList::Reverse() {
	if (head == NULL || head->next == head) return; 

	Node* current = NULL; 
	Node* next = head; 
	Node* prev = NULL;
	do {
		prev = current;
		current = next;
		next = next->next; 
		current->next = prev;
	} while (next != head);
	next->next = current;
	head = current; 
}

void CircularLinkedList::concatenating2linkedlist(CircularLinkedList* l2) {
	Node* p = head;
	Node* q = l2->head;
	if (head == NULL) {
		head = q; 
		return; 
	}
	if (head->next == head) {
		head->next = q; 
		while (q->next != l2->head)
		{
			q = q->next;
		}
		q->next = head;
		return;
	}
	if (l2->head == NULL) {
		return;
	}
	if (l2->head->next == l2->head) {
		while (p->next != head)
		{	
			p = p->next;
		}
		p->next = q;
		q->next = head;
		return;
	}
	while (p->next != head)
	{
		p = p->next;
	}
	p->next = q; 
	while (q->next != l2->head)
	{
		q = q->next;
	}
	q->next = head;

}
