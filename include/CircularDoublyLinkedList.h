#pragma once

#include "Node.h"

class CircularDoublyLinkedList {
private:
    Node* head;
    int size;
public:
    CircularDoublyLinkedList();
    ~CircularDoublyLinkedList();
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
    void concatenating2linkedlist(CircularDoublyLinkedList* l2);
    int MidleLinkedList();

};