#pragma once

#include "Node.h"


class SinglyLinkedList {
private:
    Node* head;
    int size; 
public:
    SinglyLinkedList();
    ~SinglyLinkedList();
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
    void concatenating2linkedlist(SinglyLinkedList* l2);
    int MidleLinkedList();
    void Merging2linkedlist(SinglyLinkedList* l2);
};


