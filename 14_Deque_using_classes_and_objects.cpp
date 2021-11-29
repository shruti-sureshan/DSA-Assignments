#include <stdio.h>
#include <iostream>
#include <stdlib.h>
// #include <conio.h>
using namespace std;

//Deque implementation using classes and objects
class Node
{
public:
	int data;
	Node *next;
	Node *prev;
	Node() //constructor
	{
		next = NULL;
		prev = NULL;
	}
};

class Deque
{
	Node *start;

public:
	Deque() //constructor
	{
		start = NULL;
	}

	//function declaration
	void display();
	void insert_right();
	void insert_left();
	void search();
	void delete_right();
	void delete_left();
};

//Creation of a linked list or Insert in the end
void Deque::insert_right()
{
	int choice;
	do
	{
		Node *n = new Node();
		cout << "Enter Element: ";
		cin >> n->data;
		n->next = NULL;
		if (start == NULL)
			start = n; //first element of the linked list
		else
		{
			//traverse till the end of the list
			Node *t = start;
			while (t->next)
				t = t->next;
			t->next = n; //insert the element in the end
			n->prev = t;
		}

		cout << "Press 1 to enter more elements: ";
		cin >> choice;
	} while (choice == 1);
	display();
}

void Deque::insert_left()
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
		start->prev = n;
		start = n;
	}

	display();
}

void Deque::delete_right()
{
	Node *t, *prev, *x;
	t = start;
	if (start == NULL)
		cout << "LINKED LIST NOT CREATED";
	else
	{
		while (t)
		{
			prev = t;
			t = t->next;
		}
		cout << "Deleting " << prev->data << "\n";
		prev->prev->next = NULL;
		free(prev);
	}

	display();
}

void Deque::delete_left()
{
	Node *t, *prev, *x;
	t = start;
	if (start == NULL)
		cout << "LINKED LIST NOT CREATED";
	else
	{
		x = start;
		cout << "Deleting " << x->data << "\n";
		start = start->next;
		start->prev = NULL;
		free(x);
	}

	display();
}

//Display all the elements or traverse through the linked list
void Deque::display()
{
	if (start == NULL)
	{
		cout << "List is empty" << endl;
	}
	else
	{
		Node *t = start;
		cout << "The elements of the linked list are:\n";
		while (t != NULL)
		{
			cout << t->data << "\n"; //traversing and printing all elements
			t = t->next;
		}
	}
}

//Search for a given element
void Deque::search()
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

int main()
{
	//clrscr();
	int choice;
	Deque q;
	do
	{
		printf("1.Insert Right\n2.Insert Left\n3.Delete Right\n4.Delete Left\n5.Display\n6.Search an element\nEnter your Choice: \n");

		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			q.insert_right();
			break;
		case 2:
			q.insert_left();
			break;
		case 3:
			q.delete_right();
			break;
		case 4:
			q.delete_left();
			break;
		case 5:
			q.display();
			break;
		case 6:
			q.search();
			break;
		}

		printf("Enter 1 to continue: ");
		scanf("%d", &choice);
	} while (choice == 1);
	//printf("Press any key to exit");
	//getch();
	return 0;
}

/*OUTPUT:
1.Insert Right     
2.Insert Left      
3.Delete Right     
4.Delete Left      
5.Display
6.Search an element
Enter your Choice: 
1
Enter Element:
2
Press 1 to enter more elements: 1
Enter Element:
3
Press 1 to enter more elements: 1
Enter Element:
5
Press 1 to enter more elements: 1
Enter Element:
6
Press 1 to enter more elements: 1
Enter Element:
7
Press 1 to enter more elements: 2
The elements of the linked list are:
2
3
5
6
7
Enter 1 to continue: 1
1.Insert Right
2.Insert Left
3.Delete Right
4.Delete Left
5.Display
6.Search an element
Enter your Choice:
2
Enter Data to be inserted:1
The elements of the linked list are:
1
2
3
5
6
7
Enter 1 to continue: 1
1.Insert Right
2.Insert Left
3.Delete Right
4.Delete Left
5.Display
6.Search an element
Enter your Choice:
3
Deleting 7
The elements of the linked list are:
1
2
3
5
6
Enter 1 to continue: 1
1.Insert Right
2.Insert Left
3.Delete Right
4.Delete Left
5.Display
6.Search an element
Enter your Choice:
4
Deleting 1
The elements of the linked list are:
2
3
5
6
Enter 1 to continue: 1
1.Insert Right
2.Insert Left
3.Delete Right
4.Delete Left
5.Display
6.Search an element
Enter your Choice:
5
The elements of the linked list are:
2
3
5
6
Enter 1 to continue: 1
1.Insert Right
2.Insert Left
3.Delete Right
4.Delete Left
5.Display
6.Search an element
Enter your Choice:
6
Enter element to be searched:3
Element found at position 2
Enter 1 to continue: 2
*/
