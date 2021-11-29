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
    Node *start1, *start2;

public:
    SinglyLinkedList() //constructor
    {
        start1 = NULL;
        start2 = NULL;
    }

    //function declaration
    void create();
    void display();
    void merge();
};

//Creation of a linked list or Insert in the end
void SinglyLinkedList::create()
{
    int choice;
    do
    {
        Node *n = new Node();
        cout << "Enter Element for 1st list: ";
        cin >> n->data;
        n->next = NULL;
        if (start1 == NULL)
            start1 = n; //first element of the linked list
        else
        {
            //traverse till the end of the list
            Node *t = start1;
            while (t->next)
                t = t->next;
            t->next = n; //insert the element in the end
        }

        cout << "Press 1 to enter more elements: ";
        cin >> choice;
    } while (choice == 1);

    do
    {
        Node *m = new Node();
        cout << "Enter Element for 2nd list: ";
        cin >> m->data;
        m->next = NULL;
        if (start2 == NULL)
            start2 = m; //first element of the linked list
        else
        {
            //traverse till the end of the list
            Node *t = start2;
            while (t->next)
                t = t->next;
            t->next = m; //insert the element in the end
        }

        cout << "Press 1 to enter more elements: ";
        cin >> choice;
    } while (choice == 1);

    //display
    Node *t = start1;
    cout << "The elements of the 1st linked list are:\n";
    while (t != NULL)
    {
        cout << t->data << "\n"; //traversing and printing all elements
        t = t->next;
    }

    t = start2;
    cout << "The elements of the 1st linked list are:\n";
    while (t != NULL)
    {
        cout << t->data << "\n"; //traversing and printing all elements
        t = t->next;
    }
}

void SinglyLinkedList::merge()
{
    Node *t1 = start1;
    Node *t2 = start2;
    Node *x = new Node();
    Node *t3 = x;

    while (t1 != NULL && t2 != NULL)
    {
        if (t1->data < t2->data)
        {
            t3->next = t1;
            t1 = t1->next;
        }
        else
        {
            t3->next = t2;
            t2 = t2->next;
        }
        t3 = t3->next;
    }

    while (t1 != NULL)
    {
        t3->next = t1;
        t1 = t1->next;
        t3 = t3->next;
    }

    while (t2 != NULL)
    {
        t3->next = t2;
        t2 = t2->next;
        t3 = t3->next;
    }

    //display
    Node *t = start1;
    cout << "The elements of the linked list are:\n";
    while (t != NULL)
    {
        cout << t->data << "\n"; //traversing and printing all elements
        t = t->next;
    }
}

int main()
{
    //clrscr();
    int choice;
    SinglyLinkedList sl; //object

    do
    {
        cout << "1.Create a Linked List\n2.Merge\nEnter your Choice: \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            sl.create();
            break;
        case 2:
            sl.merge();
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
1.Create a Linked List
2.Merge
Enter your Choice:    
1
Enter Element for 1st list: 1
Press 1 to enter more elements: 1
Enter Element for 1st list: 3
Press 1 to enter more elements: 1
Enter Element for 1st list: 5
Press 1 to enter more elements: 2
Enter Element for 2nd list: 2
Press 1 to enter more elements: 1
Enter Element for 2nd list: 4
Press 1 to enter more elements: 1
Enter Element for 2nd list: 6
Press 1 to enter more elements: 2
The elements of the 1st linked list are:
1
3
5
The elements of the 1st linked list are:
2
4
6
Enter 1 to continue: 1
1.Create a Linked List
2.Merge
Enter your Choice:
2
The elements of the linked list are:
1
2
3
4
5
6
Enter 1 to continue: 2
*/
