#include <stdio.h>
#include <iostream>
#include <stdlib.h>
// #include <conio.h>
using namespace std;

//Circular Linked list implementation using classes and objects
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

class CircularLinkedList
{
	Node *start;
	public:
		CircularLinkedList()      //constructor
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
void CircularLinkedList::create()
{
	int choice;
	do {
		Node *n = new Node();
		cout << "Enter Element: ";
		cin >> n->data;
		n->next = NULL;
		if (start == NULL){
            n->next=n;  
			start = n;	
        }
		else
		{
			//traverse till the end of the list
			Node *t = start;
            while(t->next!=start)    
				t = t->next;
			t->next = n;      //insert the element in the end
            n->next=start;
		}

		cout << "Press 1 to enter more elements: ";
		cin >> choice;
	} while (choice == 1);
	display();
}

//Display all the elements or traverse through the linked list
void CircularLinkedList::display()
{
	if (start == NULL)
	{
		cout<<"List is empty" << endl;
	}
	else
	{
		Node *t = start;
		cout<<"The elements of the linked list are:\n";
	while (t->next!=start)
	{
		cout<< t->data<<"\n";    //traversing and printing all elements
		t = t->next;
	}
    printf("%d\n", t->data);
	}
}

//insert element in the beginning of the linked list
void CircularLinkedList::begin()
{
	Node *n = new Node();
	cout << "Enter Element to be inserted: ";
	cin >> n->data;
	if (start == NULL)
	{
		n->next=n;
		start = n;
	}
	else
	{
			Node *t = start;
			while(t->next!=start)    
				t = t->next;
			t->next = n;      
            n->next=start;
            start=n;
	}

	display();
}

//Insert after a given element
void CircularLinkedList::insertAfterGivendata()
{
	int element;
		Node *n = new Node();
	if (start == NULL){
        n->next=n;
        start=n;
    }
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
void CircularLinkedList::insertAfterGivenpos()
{
	int pos, curr = 1;
		Node *n = new Node();
	if (start == NULL){
        n->next=n;
        start=n;
    }
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
void CircularLinkedList::search()
{
	int pos = 1, element, flag=0;
	cout << "Enter element to be searched: ";
	cin >> element;
	Node *t = start;
	if (start == NULL)
		cout<<"LINKED LIST NOT CREATED";
	else{
        struct Node *t;
  t = start;
	do
	{
		if (t->data == element)
			{
                flag=1;
				cout<<"Element found at position "<< pos<<"\n";
				break;
			}   
            pos++;
		t = t->next;
	}while(t!=start);
	
    if (t == NULL)
			cout<<"Element not found\n";
    }
}

//Delete element from a linked list
void CircularLinkedList::deletion()
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
        do
		{
			prev = t;
			t = t->next;
		}	while (t!=start && t->data != element);

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
	CircularLinkedList sl;	//object

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


/*Output:
1.Create a Linked List or Insert in the end
2.Display/Traverse
3.Insert In the Beginning
4.Insert after a given element
5.Insert after a given Position
6.Search an element
7.Delete an element
Enter your Choice: 
1
Enter Element: 2
Press 1 to enter more elements: 1
Enter Element: 3
Press 1 to enter more elements: 1
Enter Element: 4
Press 1 to enter more elements: 1
Enter Element: 5
Press 1 to enter more elements: 1
Enter Element: 6
Press 1 to enter more elements: 2
The elements of the linked list are:
2
3
4
5
6
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
2
3
4
5
6
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
Enter Element to be inserted: 1
The elements of the linked list are:
1
2
3
4
5
6
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
3
Enter Element to be inserted: 10
The elements of the linked list are:
1
2
3
10
4
5
6
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
Enter Element to be inserted: 20
The elements of the linked list are:
1
2
3
20
10
4
5
6
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
Enter element to be searched: 20
Element found at position 4
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
20
The elements of the linked list are:
1
2
3
10
4
5
6
Enter 1 to continue: 2
*/