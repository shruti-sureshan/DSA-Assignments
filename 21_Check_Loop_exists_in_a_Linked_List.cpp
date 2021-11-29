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
    void loop();
};

//Creation of a linked list
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

//Check loop
void SinglyLinkedList::loop()
{
      Node *t1=start;
      Node *t2=start; 
      int flag=0;
   while(t1 && t2 && t2->next)   
{  
    t1=t1->next;        //move one node at a time
  t2=t2->next->next;    //move 2 nodes at a time
if(t2->data==t1->data)  
{  
   cout<<"loop exists at "<< t2->data <<"\n";  
   flag=1;
}  
}  
if(flag==0)
    cout<<"loop does not exists\n";
}



int main()
{
	//clrscr();
	int choice;
	SinglyLinkedList sl;	//object

	do {
		cout << "1.Create a Linked List\n2.Display\n3.Check Loop\nEnter your Choice: \n";
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
				sl.loop();
				break;
		}

		cout << "Enter 1 to continue: ";
		cin >> choice;
	} while (choice == 1);
	//printf("Press any key to exit");
	//getch();
	return 0;
}


/*OUTPUT:
1.Create a Linked List
2.Display
3.Check Loop
Enter your Choice:    
1
Enter Element: 1
Press 1 to enter more elements: 1
Enter Element: 2
Press 1 to enter more elements: 1
Enter Element: 3
Press 1 to enter more elements: 1
Enter Element: 4
Press 1 to enter more elements: 1
Enter Element: 2
Press 1 to enter more elements: 1
Enter Element: 3
Press 1 to enter more elements: 1
Enter Element: 4
Press 1 to enter more elements: 2
The elements of the linked list are:
1
2
3
4
2
3
4
Enter 1 to continue: 1
1.Create a Linked List
2.Display
3.Check Loop
Enter your Choice:
3
loop exists at 4
Enter 1 to continue: 2
*/
