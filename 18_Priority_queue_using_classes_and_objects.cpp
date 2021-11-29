#include <stdio.h>
#include <iostream>
#include <stdlib.h>
// #include <conio.h>
using namespace std;

//priority queue implementation using classes and objects
class Node
{
public:
	int data, priority;
	Node *next;
	Node() //constructor
	{
		next = NULL;
	}
};

class PQueue
{
	Node *start;

public:
	PQueue() //constructor
	{
		start = NULL;
	}

	//function declaration

	void insert();
	void deleteEle();
	void display();
	void search();
};

int main()
{
	int choice;
	//clrscr();
	PQueue pq;
	do
	{
		cout << "\n 1. Insert\n 2. Delete\n 3. Display\n 4. Search";
		cout << "\n Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			pq.insert();
			break;
		case 2:
			pq.deleteEle();
			break;
		case 3:
			pq.display();
			break;
		case 4:
			pq.search();
			break;
		}

		cout << "\nEnter 1 to continue: ";
		cin >> choice;
	} while (choice == 1);
}

void PQueue::insert()
{
	int x, pri, choice;
	Node *t;
	Node *n = new Node();
	cout << "\n Enter the value and its priority : ";
	cin >> x >> pri;
	n->data = x;
	n->priority = pri;
	if (start == NULL || pri < start->priority)
	{
		n->next = start;
		start = n;
	}
	else
	{
		t = start;
		while (t->next != NULL && t->next->priority <= pri)
			t = t->next;
		n->next = t->next;
		t->next = n;
	}
}

void PQueue::deleteEle()
{
	Node *t;
	if (start == NULL)
	{
		cout << "\n UNDERFLOW";
		return;
	}
	else
	{
		t = start;
		cout << "\n Deleted item is: " << t->data;
		start = start->next;
		free(t);
	}
	//return start;
}

void PQueue::display()
{
	Node *t;
	t = start;
	if (start == NULL)
		cout << "\nQUEUE IS EMPTY";
	else
	{
		cout << "\n PRIORITY QUEUE IS : ";
		while (t != NULL)
		{
			cout << "\t" << t->data << "[priority=" << t->priority << "]";
			t = t->next;
		}
	}
}

void PQueue::search()
{
	Node *t;
	int element, flag = 0;
	t = start;
	cout << "enter element to be searched:\n";
	cin >> element;
	if (start == NULL)
		cout << "\nQUEUE IS EMPTY";
	else
	{
		while (t != NULL)
		{
			if (t->data == element)
			{
				cout << "element found";
				flag = 1;
				break;
			}
			t = t->next;
		}
	}

	if (flag == 0)
		cout << "element not found";
}

/*OUTPUT:
 1. Insert
 2. Delete
 3. Display
 4. Search
 Enter your choice : 1

 Enter the value and its priority : 2 3

Enter 1 to continue: 1

 1. Insert
 2. Delete
 3. Display
 4. Search
 Enter your choice : 1

 Enter the value and its priority : 4 1

Enter 1 to continue: 1

 1. Insert
 2. Delete
 3. Display
 4. Search
 Enter your choice : 1

 Enter the value and its priority : 5 2

Enter 1 to continue: 1

 1. Insert
 2. Delete
 3. Display
 4. Search
 Enter your choice : 3

 PRIORITY QUEUE IS :    4[priority=1]   5[priority=2]   2[priority=3]
Enter 1 to continue: 1

 1. Insert
 2. Delete
 3. Display
 4. Search
 Enter your choice : 4
enter element to be searched:
5
element found
Enter 1 to continue: 1

 1. Insert
 2. Delete
 3. Display
 4. Search
 Enter your choice : 2

 Deleted item is: 4
Enter 1 to continue: 1

 1. Insert
 2. Delete
 3. Display
 4. Search
 Enter your choice : 3

 PRIORITY QUEUE IS :    5[priority=2]   2[priority=3]
Enter 1 to continue: 2
*/