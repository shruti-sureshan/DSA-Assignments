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
    Node *start;

public:
    SinglyLinkedList() //constructor
    {
        start = NULL;
    }

    //function declaration
    void create();
    void display();
    void deletion();
};

//Creation of a linked list or Insert in the end
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
    display();
}

//Display all the elements or traverse through the linked list
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

//Delete element from a linked list without reference to parent node
void SinglyLinkedList::deletion()
{
    int element;
    if (start == NULL)
        cout << "LINKED LIST NOT CREATED";
    else
    {
        cout << "Enter element to be deleted:\n";
        cin >> element;
        Node *x = start;
        while (x && x->data != element)
        {
            x = x->next;
        }

        //copy data from the next node to the node to be deleted and then delete the next node
        Node *t = x->next;
        x->data = t->data;
        x->next = t->next;
        free(t); 
    }

    display();
}

int main()
{
    //clrscr();
    int choice;
    SinglyLinkedList sl; //object

    do
    {
        cout << "1.Create a Linked List \n2.Display\n3.Delete an element\nEnter your Choice: \n";
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
1.Create a Linked List 
2.Display
3.Delete an element    
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
Enter Element: 5
Press 1 to enter more elements: 2
The elements of the linked list are:
1
2
3
4
5
Enter 1 to continue: 1
1.Create a Linked List 
2.Display
3.Delete an element
Enter your Choice:
3
Enter element to be deleted:
3
The elements of the linked list are:
1
2
4
5
Enter 1 to continue: 2
*/