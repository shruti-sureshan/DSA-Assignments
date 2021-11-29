#include <stdio.h>
#include <iostream>
#include <stdlib.h>
// #include <conio.h>
using namespace std;

//Linked list implementation using classes and objects
class Node
{
	public:
		int data;
	Node *next;
	Node()      //constructor
	{
		next = NULL;
	}
};

class SinglyLinkedList
{
	Node *start;
	public:
		SinglyLinkedList()      //constructor
		{
			start = NULL;
		}

	//function declaration 
	void create();
	void display();
	void begin();
	void insertAfterGivendata();
	void insertAfterGivenpos();
	void search();
	void deletion();
};

//Creation of a linked list or Insert in the end
void SinglyLinkedList::create()
{
	int choice;
	do {
		Node *n = new Node();
		cout << "Enter Element: ";
		cin >> n->data;
		n->next = NULL;
		if (start == NULL)
			start = n;	//first element of the linked list
		else
		{
			//traverse till the end of the list
			Node *t = start;
			while (t->next)
				t = t->next;
			t->next = n;	//insert the element in the end
		}

		cout << "Press 1 to enter more elements: ";
		cin >> choice;
	} while (choice == 1);
	display();
}

//Display all the elements or traverse through the linked list
void SinglyLinkedList::display()
{
	if (start == NULL)
	{
		cout<<"List is empty" << endl;
	}
	else
	{
		Node *t = start;
		cout<<"The elements of the linked list are:\n";
		while (t != NULL)
		{
			cout << t->data << "\n";	//traversing and printing all elements
			t = t->next;
		}
	}
}

//insert element in the beginning of the linked list
void SinglyLinkedList::begin()
{
	Node *n = new Node();
	cout << "Enter Element to be inserted: ";
	cin >> n->data;
	if (start == NULL)
	{
		printf("LINKED LIST NOT CREATED");
		start = n;
	}
	else
	{
		n->next = start;
		start = n;
	}

	display();
}

//Insert after a given element
void SinglyLinkedList::insertAfterGivendata()
{
	int element;
	if (start == NULL)
		printf("LINKED LIST NOT CREATED");
	else
	{
		cout << "Enter the element after which you want to insert:\n";
		cin >> element;
		Node *t = start;
		while (t && t->data != element)
			t = t->next;
		if (t == NULL)
			cout << "Element not found\n";
		else
		{
			Node *n = new Node();
			cout << "Enter Element to be inserted: ";
			cin >> n->data;
			n->next = t->next;
			t->next = n;
		}
	}

	display();
}

//Insert after a given position or index
void SinglyLinkedList::insertAfterGivenpos()
{
	int pos, curr = 1;
	if (start == NULL)
		cout << "LINKED LIST NOT CREATED";
	else
	{
		cout << "Enter Position:\n";
		cin >> pos;
		Node *t = start;
		while (curr != pos)
		{
			t = t->next;
			curr++;
		}

		Node *n = new Node();
		cout << "Enter Element to be inserted: ";
		cin >> n->data;
		n->next = t->next;
		t->next = n;
	}

	display();
}

//Search for a given element
void SinglyLinkedList::search()
{
	int pos = 1, element;
	cout << "Enter element to be searched: ";
	cin >> element;
	Node *t = start;
	if (start == NULL)
		printf("LINKED LIST NOT CREATED");
	else
	{
		for (t = start; t != NULL; t = t->next)
		{
			if (t->data == element)
			{
				cout << "Element found at position " << pos << "\n";
				break;
			}

			pos++;
		}

		if (t == NULL)
			cout << "Element not found\n";
	}
}

//Delete element from a linked list
void SinglyLinkedList::deletion()
{
	int element;
	if (start == NULL)
		cout << "LINKED LIST NOT CREATED";
	else
	{
		cout << "Enter element to be deleted:\n";
		cin >> element;
		Node *t = start;
		Node * prev;
		while (t && t->data != element)
		{
			prev = t;
			t = t->next;
		}

		if (t == NULL)
		{
			cout << "Element Not Found\n";
		}
		else
		{
			if (start == t)
			{
				start = start->next;
				free(t);
			}
			else
			{
				prev->next = t->next;
				free(t);
			}
		}
	}

	display();
}

int main()
{
	//clrscr();
	int choice;
	SinglyLinkedList sl;	//object

	do {
		cout << "1.Create a Linked List or Insert in the end\n2.Display/Traverse\n3.Insert In the Beginning\n4.Insert after a given element\n5.Insert after a given Position\n6.Search an element\n7.Delete an element\nEnter your Choice: \n";
		cin >> choice;
		switch (choice)
		{
			case 1:
				sl.create();
				break;

			case 2:
				sl.display();
				break;
			case 3:
				sl.begin();
				break;
			case 4:
				sl.insertAfterGivendata();
				break;
			case 5:
				sl.insertAfterGivenpos();
				break;
			case 6:
				sl.search();
				break;
			case 7:
				sl.deletion();
				break;
		}

		cout << "Enter 1 to continue: ";
		cin >> choice;
	} while (choice == 1);
	//printf("Press any key to exit");
	//getch();
	return 0;
}


/*
Output:
1.Create a Linked List or Insert in the end
2.Display/Traverse
3.Insert In the Beginning
4.Insert after a given element
5.Insert after a given Position
6.Search an element
7.Delete an element
Enter your Choice: 
1
Enter Element: 11
Press 1 to enter more elements: 1
Enter Element: 22
Press 1 to enter more elements: 1
Enter Element: 33
Press 1 to enter more elements: 1
Enter Element: 44
Press 1 to enter more elements: 2
The elements of the linked list are:
11
22
33
44
Enter 1 to continue: 1
1.Create a Linked List or Insert in the end
2.Display/Traverse
3.Insert In the Beginning
4.Insert after a given element
5.Insert after a given Position
6.Search an element
7.Delete an element
Enter your Choice:
2
The elements of the linked list are:
11
22
33
44
Enter 1 to continue: 1
1.Create a Linked List or Insert in the end
2.Display/Traverse
3.Insert In the Beginning
4.Insert after a given element
5.Insert after a given Position
6.Search an element
7.Delete an element
Enter your Choice:
3
Enter Element to be inserted: 7
The elements of the linked list are:
7
11
22
33
44
Enter 1 to continue: 1
1.Create a Linked List or Insert in the end
2.Display/Traverse
3.Insert In the Beginning
4.Insert after a given element
5.Insert after a given Position
6.Search an element
7.Delete an element
Enter your Choice:
4
Enter the element after which you want to insert:
22
Enter Element to be inserted: 80
The elements of the linked list are:
7
11
22
80
33
44
Enter 1 to continue: 1
1.Create a Linked List or Insert in the end
2.Display/Traverse
3.Insert In the Beginning
4.Insert after a given element
5.Insert after a given Position
6.Search an element
7.Delete an element
Enter your Choice:
5
Enter Position:
3
Enter Element to be inserted: 6
The elements of the linked list are:
7
11
22
6
80
33
44
Enter 1 to continue: 1
1.Create a Linked List or Insert in the end
2.Display/Traverse
3.Insert In the Beginning
4.Insert after a given element
5.Insert after a given Position
6.Search an element
7.Delete an element
Enter your Choice:
6
Enter element to be searched: 80
Element found at position 5
Enter 1 to continue: 1
1.Create a Linked List or Insert in the end
2.Display/Traverse
3.Insert In the Beginning
4.Insert after a given element
5.Insert after a given Position
6.Search an element
7.Delete an element
Enter your Choice:
7
Enter element to be deleted:
6
The elements of the linked list are:
7
11
22
80
33
44
Enter 1 to continue: 2

*/