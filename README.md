# Linked List Data Structures in C++


# 📌 Overview

- This project implements a Singly Linked List in C++ with various operations such as insertion, deletion, and more. It is designed with object-oriented programming (OOP) principles.

# ✨ Features

- Insert elements at the beginning, middle, or end

- Delete elements by index

- Display the list

- Find the maximum and minimum values

- Check if the list is sorted

- Remove duplicates from a sorted list

- Reverse the list 

- Concatenate two linked lists

- **Object-Oriented Design**: Each data structure is encapsulated in a class.  
- **Error Handling**: Edge cases (e.g., empty lists, invalid indices) are handled.  
- **Tested with Assertions**: Includes test cases for validation. 

# 🚀 Usage

Example usage of the linked list:

```cpp
#include "SinglyLinkedList.h"
#include "CirculerLinkedList.h"
#include <iostream>
using namespace std;

int main() {
    SinglyLinkedList S_list;
    S_list.InsertFirst(10);
    S_list.Append(20);
    S_list.Insert(1, 15);
    S_list.Display(); // Output: 10 15 20
    
    cout << "Max: " << S_list.Max() << endl; // Output: 20
    cout << "Min: " << S_list.Min() << endl; // Output: 10
    
    S_list.Reverse();
    S_list.Display(); // Output: 20 15 10
    

    CircularLinkedList C_list;
    C_list.Append(10);
    C_list.Append(20);
    C_list.InsertFirst(5);
    C_list.Display(); // Output: 5 10 20
    
    C_list.Delete(2);
    C_list.Display(); // Output: 5 20
    
    cout << "Length: " << C_list.Length() << endl;
    cout << "Max: " << C_list.Max() << endl;
    cout << "Min: " << C_list.Min() << endl;

    return 0;
}
```

# 🏗 Future Improvements

Implement doubly linked list.

Add unit tests using Google Test (GTest).

# ⭐ If you like this project, don't forget to star it on GitHub!