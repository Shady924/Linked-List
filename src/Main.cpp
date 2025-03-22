#include <iostream>
#include <cassert> 
#include "SinglyLinkedList.h"
#include "CircularLinkedList.h"
#include "DoublyLinkedList.h"
#include "CircularDoublyLinkedList.h"

class TestFramework {
public:
    static void RunAllTests() {
        TestSinglyLinkedList();
        TestDoublyLinkedList();
        TestCircularLinkedList();
        TestCircularDoublyLinkedList();
    }

private:
    static void TestSinglyLinkedList() {
        std::cout << "\n=== Testing Singly Linked List ===\n";
        SinglyLinkedList sll;

        // Empty list tests
        assert(sll.Isempty());
        assert(sll.Length() == 0);

        // Insertion tests
        sll.InsertFirst(30);
        sll.Append(50);
        sll.Insert(1, 40);
        sll.Display();  // Expected: 30 40 50

        // Statistical tests
        assert(sll.Sum() == 120);
        assert(sll.Max() == 50);
        assert(sll.Min() == 30);

        // Deletion tests
        sll.Delete(1);
        sll.Display();  // Expected: 40 50
    }

    static void TestDoublyLinkedList() {
        std::cout << "\n=== Testing Doubly Linked List ===\n";
        DoublyLinkedList dll;

        // Edge case: single element
        dll.InsertFirst(10);
        dll.Delete(1);
        assert(dll.Isempty());

        // Reverse test
        dll.Append(1);
        dll.Append(2);
        dll.Append(3);
        dll.Reverse();
        dll.Display();  // Expected: 3 2 1
    }

    static void TestCircularLinkedList() {
        std::cout << "\n=== Testing Circular Linked List ===\n";
        CircularLinkedList cll;

        // Circular integrity test
        cll.Append(10);
        cll.Append(20);
        Node* head = cll.Search(10);
        assert(head->next->next == head);

        // Concatenation test
        CircularLinkedList cll2;
        cll2.Append(30);
        cll.concatenating2linkedlist(&cll2);
        cll.Display();  // Expected: 10 20 30
        assert(cll.Length() == 3);
    }

    static void TestCircularDoublyLinkedList() {
        std::cout << "\n=== Testing Circular Doubly Linked List ===\n";
        CircularDoublyLinkedList cdll;

        // Bidirectional test
        cdll.Append(100);
        cdll.Append(200);
        Node* node = cdll.Search(200);
        assert(node->prev->data == 100);
        assert(node->next->data == 100);

        // Duplicate removal
        cdll.Append(200);
        cdll.Removeduplicatesfromsorted();
        cdll.Display();  // Expected: 100 200
        assert(cdll.Length() == 2);
    }
};

int main() {
    TestFramework::RunAllTests();
    std::cout << "\nAll tests passed successfully!\n";
    return 0;
}
