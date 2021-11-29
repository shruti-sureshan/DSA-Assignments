#include <stdio.h>
#include <iostream>
#include <stdlib.h>
// #include <conio.h>
#define N 10
using namespace std;

//Queue implementation using classes and objects

class Queue
{
	int f, r;
	int data[N];

public:
	Queue() //constructor
	{
		f = -1;
		r = -1;
	}

	//function declaration
	void Enqueue();
	void Dequeue();
	void SearchElement();
	void displayElement();
};

//Insertion
void Queue::Enqueue()
{
	int element, choice;
	do
	{
		cout << "Enter Element:\n";
		cin >> element;
		if (r == N - 1) //overflow condition
			cout << "Queue is full\n";
		if (f == -1 && r == -1) //check if the queue is empty
			f = r = 0;
		else
			r = r + 1;
		data[r] = element;
		cout << "Press 1 to enter more elements: ";
		cin >> choice;
	} while (choice == 1);
}

void Queue::Dequeue()
{
	int x;
	if (f > -1 && f > r)
		cout << "Queue is empty\n"; //underflow
	else
	{
		x = data[f];
		f = f + 1;
		cout << "Element deleted is " << x << "\n";
	}
}

void Queue::SearchElement()
{
	int x;
	int flag = 0;
	cout << "Enter element to be searched: ";
	cin >> x;
	if (f == -1)
		cout << "Queue is empty";
	else
	{
		cout << "Elements of the queue are:\n";
		for (int i = f; i <= r; i++) //traverse throughout the array from front to rear end
		{
			if (data[i] == x) //compare each element
			{
				flag = 1;
				cout << "Element found at " << (i + 1) << "\n";
				break;
			}
		}

		if (flag == 0)
			cout << "Element not found\n";
	}
}

void Queue::displayElement()
{
	if (f == -1)
		cout << "Queue is empty";
	else
	{
		cout << "Elements of the queue are:\n";
		for (int i = f; i <= r; i++) //traverse throughout the array from front to rear end
		{
			cout << data[i] << "\n";
		}
	}
}

int main()
{
	//clrscr();
	int choice;
	Queue q; //object

	do
	{
		cout << "1.Insert\n2.Delete\n3.Display/Traverse\n4.Search\n";
		cout << "enter your choice\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			q.Enqueue();
			break;
		case 2:
			q.Dequeue();
			break;
		case 3:
			q.displayElement();
			break;
		case 4:
			q.SearchElement();
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
1.Insert
2.Delete
3.Display/Traverse        
4.Search
enter your choice
1
Enter Element:
20
Press 1 to enter more elements: 1 
Enter Element:
30
Press 1 to enter more elements: 1
Enter Element:
40
Press 1 to enter more elements: 1
Enter Element:
50
Press 1 to enter more elements: 2
Enter 1 to continue: 1
1.Insert
2.Delete
3.Display/Traverse
4.Search
enter your choice
3
Elements of the queue are:
20
30
40
50
Enter 1 to continue: 1
1.Insert
2.Delete
3.Display/Traverse
4.Search
enter your choice
2
Element deleted is 20
Enter 1 to continue: 1
1.Insert
2.Delete
3.Display/Traverse
4.Search
enter your choice
4
Enter element to be searched: 40
Elements of the queue are:
Element found at 3
Enter 1 to continue: 2


*/