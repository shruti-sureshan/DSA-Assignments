#include <stdio.h>
#include <iostream>
#include <stdlib.h>
// #include <conio.h>
using namespace std;
#define N 20

//Stack implementation using classes and objects
class Stack
{
	int data[N], tos;

public:
	Stack() //Constructor
	{
		tos = -1; //top of the stack
	}

	//function declaration
	void pushElement();
	void popElement();
	void peekElement();
	void displayElement();
	void searchElement();
};

// Push the elements on the top of the stack
void Stack::pushElement()
{
	int element, choice;
	do
	{

		cout << "Enter Element to be inserted: ";
		cin >> element;
		if (tos == N - 1) //overflow condition
			cout << "Stack is full\n";
		else
		{
			tos = tos + 1;
			data[tos] = element;
		}
		cout << "Press 1 to enter more elements: ";
		cin >> choice;
	} while (choice == 1);
	displayElement();
}

//Pop element from top of the stack
void Stack::popElement()
{
	int x;
	if (tos == -1)
	{
		cout << "stack is empty\n"; //underflow
	}
	else
	{
		x = data[tos];
		cout << "Deleted element is " << x << "\n";
		tos = tos - 1;
	}

	displayElement();
}

//Read top element from the stack
void Stack::peekElement()
{
	if (tos == -1)
	{
		cout << "stack is empty\n"; //underflow
	}
	else
	{
		cout << "The topmost element is " << data[tos] << "\n";
	}
}

//Display elements
void Stack::displayElement()
{
	if (tos == -1)
	{
		cout << "stack is empty\n"; //underflow
	}
	else
	{
		cout << "The elements in the stack are:\n";
		for (int i = tos; i >= 0; i--)
		{
			cout << data[i] << "\n";
		}
	}
}

//search
//Display elements
void Stack::searchElement()
{
	int x;
	int flag = 0;
	if (tos == -1)
	{
		cout << "stack is empty\n"; //underflow
	}
	else
	{
		cout << "Enter the element to be search: "
			 << "\n";
		cin >> x;
		for (int i = tos; i >= 0; i--)
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

int main()
{
	//clrscr();
	int choice;
	Stack s; //object

	do
	{
		cout << "1.push\n2.pop\n3.peek\n4.display\n5.search\n";
		cout << "enter your choice\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			s.pushElement();
			break;
		case 2:
			s.popElement();
			break;
		case 3:
			s.peekElement();
			break;
		case 4:
			s.displayElement();
			break;
		case 5:
			s.searchElement();
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
1.push
2.pop
3.peek
4.display        
5.search
enter your choice
1
Enter Element to be inserted: 20
Press 1 to enter more elements: 1
Enter Element to be inserted: 30
Press 1 to enter more elements: 1
Enter Element to be inserted: 40
Press 1 to enter more elements: 1
Enter Element to be inserted: 50
Press 1 to enter more elements: 2
The elements in the stack are:
50
40
30
20
Enter 1 to continue: 1
1.push
2.pop
3.peek
4.display
5.search
enter your choice
2
Deleted element is 50
The elements in the stack are:
40
30
20
Enter 1 to continue: 1
1.push
2.pop
3.peek
4.display
5.search
enter your choice
3
The topmost element is 40
Enter 1 to continue: 1
1.push
2.pop
3.peek
4.display
5.search
enter your choice
4
The elements in the stack are:
40
30
20
Enter 1 to continue: 1
1.push
2.pop
3.peek
4.display
5.search
enter your choice
5
Enter the element to be search: 
30
Element found at 2
Enter 1 to continue: 2

*/