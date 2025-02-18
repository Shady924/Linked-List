#include "SinglyLinkedList.h"
#include <iostream>
using namespace std;



SinglyLinkedList::SinglyLinkedList() : head(nullptr) , size(0) {}

bool SinglyLinkedList::Isempty() const {
	return (head == NULL);
}

void  SinglyLinkedList::InsertFirst(int newvalue) {
	Node* newnode = new Node();
	newnode->data = newvalue;
	this->size++;
	if (Isempty()) {
		newnode->next = NULL;
		head = newnode;
	}
	else {
		newnode->next = head;
		head = newnode;
	}

}

void SinglyLinkedList::Insert(int index, int newvalue) {
	if (index >= 0 && index <= this->size) {
		if (index == 0) {
			InsertFirst(newvalue);
			return ;
		}
		this->size++;
		Node* temp = head;
		int pos = 0;
		while (temp != NULL && pos < index - 1) {
			pos++;
			temp = temp->next;
		}
		if (temp) {
			Node* newnode = new Node();
			newnode->data = newvalue;
			newnode->next = temp->next;
			temp->next = newnode;
		}
	}
	else {
		cout << "Invalid index\n";
	}

}

void SinglyLinkedList::Append(int newvalue) {
	if (Isempty()) {
		InsertFirst(newvalue);
	}
	else {
		this->size++;
		Node* temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		Node* newnode = new Node();
		newnode->data = newvalue;
		newnode->next = NULL;
		temp->next = newnode;
	}
}


int SinglyLinkedList::Delete(int index) {
	int x = -1;
	if (Isempty()) {
		return x;
	}

	if (index > 0 && index <= this->size) {
		this->size--; 
		Node* delptr = head;
		Node* temp = NULL;
		if (index == 1) {
			x = head->data;
			head = head->next;
			delete delptr;
		}
		else {
			int pos = 1;
			while (delptr != NULL && pos < index) {
				pos++;
				temp = delptr;
				delptr = delptr->next;
			}
			if (delptr != NULL) {
				x = delptr->data;
				temp->next = delptr->next;
				delete delptr;
			}
		}
		return x;
	}
	else {
		return x;
	}
}



void SinglyLinkedList::Display() const {
	Node* temp = head;

	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int SinglyLinkedList::Length() const {
	return this->size;
}

int SinglyLinkedList::Sum() const {
	int sum = 0;
	Node* temp = head;
	while (temp != NULL) {
		sum += temp->data;
		temp = temp->next;
	}
	return sum;
}

int SinglyLinkedList::Max()const {
	Node* temp = head;
	int Max = INT32_MIN;
	while (temp != NULL) {
		if (temp->data > Max)
			Max = temp->data;
		temp = temp->next;
	}
	return Max;
}

int SinglyLinkedList::Min()const {
	Node* temp = head;
	int Min = INT32_MAX;
	while (temp != NULL) {
		if (temp->data < Min)
			Min = temp->data;
		temp = temp->next;
	}
	return Min;
}

Node* SinglyLinkedList::Search(int key) const {
	if (Isempty()) return NULL;

	Node* temp = head;

	while (temp != NULL) {
		if (temp->data == key)
			return temp;
		temp = temp->next;
	}
	return NULL;
}

bool SinglyLinkedList::issorted() const {
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

void SinglyLinkedList::Removeduplicatesfromsorted() {
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

void SinglyLinkedList::Reverse() {
	int* arr = new int[this->size];
	int i = 0;
	Node* p = head;

	while (p) {
		arr[i++] = p->data;
		p = p->next;
	}
	i--;
	p = head;
	while (p) {
		p->data = arr[i--];
		p = p->next;
	}
	delete[] arr;
}

void SinglyLinkedList::concatenating2linkedlist(SinglyLinkedList* l2) {
	Node* p = head;
	Node* temp = l2->head;
	if (l2 == NULL || l2->head == NULL) {
		return;
	}
	if (head == NULL) {
		head = temp;
		temp = NULL;
		return;
	}
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = temp;
	delete temp;
}

void SinglyLinkedList::Merging2linkedlist(SinglyLinkedList* l2) {
	if (l2 == NULL || l2->head == NULL)
		return;

	if (head == NULL) {
		head = l2->head;
		l2->head = NULL;
		return;
	}

	Node* p = head;
	Node* q = l2->head;
	Node* third;
	Node* last;

	if (p->data <= q->data) {
		third = last = p;
		p = p->next;
	}
	else {
		third = last = q;
		q = q->next;
	}
	head = third;
	while (p != NULL && q != NULL) {
		if (p->data <= q->data) {
			last->next = p;
			last = p;
			p = p->next;
		}
		else {
			last->next = q;
			last = q;
			q = q->next;
		}
	}
	if (p != NULL) {
		last->next = p;
	}
	else {
		last->next = q;
	}

	l2->head = NULL;
}

