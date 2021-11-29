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
    Node() //constructor
    {
        next = NULL;
    }
};

class SinglyLinkedList
{

public:
    Node *start, *tos;
    SinglyLinkedList() //constructor
    {
        start = NULL;
        tos = NULL;
    }

    //function declaration
    void reverseStack();
    void create();
    Node *reverseRec(Node *);
    void display();
};

void SinglyLinkedList::create()
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
        }

        cout << "Press 1 to enter more elements: ";
        cin >> choice;
    } while (choice == 1);
    //display();

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

void SinglyLinkedList::reverseStack()
{
    if (start == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        Node *t = start;
        Node *a;
        start=a;
        while (t != NULL)
        {
            a = t;
            t = t->next;
            a->next = tos;
            tos = a;
            start=a;
        }
    }
    display();
}


Node *SinglyLinkedList::reverseRec(Node *start)
{
    if (start == NULL || start->next == NULL)
        return start;
    Node *t = reverseRec(start->next);
    start->next->next = start;
    start->next = NULL;
    return t;
}

void SinglyLinkedList::display()
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


int main()
{
    //clrscr();
    int choice;
    SinglyLinkedList sl; //object

    do
    {
        cout << "1.Create\n2.Reverse using Stack\n3.Reverse using Recursion\nEnter your Choice: \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            sl.create();
            break;
        case 2:
            sl.reverseStack();
            break;
        case 3:
            sl.start = sl.reverseRec(sl.start);
            sl.display();
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
1.Create
2.Reverse using Stack    
3.Reverse using Recursion
Enter your Choice:       
1
Enter Element: 2
Press 1 to enter more elements: 1
Enter Element: 4
Press 1 to enter more elements: 1
Enter Element: 6
Press 1 to enter more elements: 1
Enter Element: 8
Press 1 to enter more elements: 2
The elements of the linked list are:
2
4
6
8
Enter 1 to continue: 1
1.Create
2.Reverse using Stack
3.Reverse using Recursion
Enter your Choice:
2
The elements of the linked list are:
8
6
4
2
Enter 1 to continue: 1
1.Create
2.Reverse using Stack
3.Reverse using Recursion
Enter your Choice:
3
The elements of the linked list are:
2
4
6
8
Enter 1 to continue: 3
*/