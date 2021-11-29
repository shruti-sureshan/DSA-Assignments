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
    Node *start;
    SinglyLinkedList() //constructor
    {
        start = NULL;
    }

    //function declaration
    bool palindrome(Node *start);
    void create();
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


//check for palindrome
bool SinglyLinkedList::palindrome(Node *start)
{

    Node *t1=start;
Node *t2=start;
Node *prev=NULL;
while(t2!=NULL && t2->next!=NULL){
        t2=t2->next->next;

    Node *temp=t1;
        t1=t1->next;

        temp->next=prev;
        prev=temp;

}


if(t2!=start){
    t1=t1->next;
}

while (prev != NULL && t1 != NULL) {
if (prev->data != t1->data) {
return false;
}
prev = prev->next;
t1 = t1->next;
}
return (prev == NULL && t1 == NULL);
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
        cout << "1.Create linked list\n2.Check Palindrome\nEnter your Choice: \n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            sl.create();
            break;
        case 2:
            if(sl.palindrome(sl.start))
            cout<<"palindrome\n";
            else
            cout<<"not palindrome\n";
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
1.Create linked list
2.Check Palindrome  
Enter your Choice:  
1
Enter Element: 1
Press 1 to enter more elements: 1
Enter Element: 2
Press 1 to enter more elements: 1
Enter Element: 3
Press 1 to enter more elements: 1
Enter Element: 2
Press 1 to enter more elements: 1
Enter Element: 1
Press 1 to enter more elements: 2
The elements of the linked list are:
1
2
3
2
1
Enter 1 to continue: 1
1.Create linked list
2.Check Palindrome
Enter your Choice:
2
palindrome
Enter 1 to continue: 2
*/