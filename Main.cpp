#include <iostream>
#include "SinglyLinkedList.h"
#include "CircularLinkedList.h"

using namespace std;

int main() {
	//SinglyLinkedList s1;
	//s1.Append(1);
	//s1.Append(1);
	//s1.Append(2);
	//s1.Append(3);
	//s1.Append(3);
	//s1.Append(4);
	//s1.Append(4);
	//s1.Display();
	//cout << s1.Length() << endl;
	//cout << s1.Min() << endl; 
	//cout << s1.Max() << endl;
	//s1.Removeduplicatesfromsorted();
	//s1.Display();
	//cout << s1.Length() << endl;
	//s1.Append(7);
	//s1.Display();
	//cout << s1.Length() << endl;
	//s1.Reverse();
	//s1.Display();

	CircularLinkedList c1;
	/*c1.InsertFirst(4);
	c1.InsertFirst(2);*/
	
	cout << "c1 " << c1.Length() << endl;
	c1.Display();
	CircularLinkedList c2;
	
	cout << "c2 " << c2.Length() << endl ;
	c2.Display();
	c1.concatenating2linkedlist(&c2);
	c1.Display();

	c1.Reverse();
	c1.InsertFirst(55);
	c1.InsertFirst(1);
	c1.InsertFirst(33);
	cout << "c1 " << c1.Length() << endl;
	c1.Display();
	c1.Delete(1);
	cout << "c1 " << c1.Length() << endl;
	c1.Display();

	return 0;
}