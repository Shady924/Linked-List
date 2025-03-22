#pragma once

#include "Node.h"

class DoublyLinkedList {
private: 
	Node* head; 
	int size; 
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	bool Isempty() const;
	void InsertFirst(int newvalue);
	void Insert(int index, int newvalue);
	void Append(int newvalue);
	int Delete(int index);
	void Display() const;
	int Length() const;
	int Sum() const;
	int Max() const;
	int Min() const;
	Node* Search(int key) const;
	bool issorted() const;
	void Removeduplicatesfromsorted();
	void Reverse();
	void concatenating2linkedlist(DoublyLinkedList* l2);
	int MidleLinkedList();

};