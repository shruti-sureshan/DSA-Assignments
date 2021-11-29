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
    Node *start, *start1, *start2;
    SinglyLinkedList() //constructor
    {
        start = NULL;
        start1 = NULL;
        start2 = NULL;
    }

    //function declaration
    int length(Node *start);
    int mergepoint(Node *start1, Node *start2);
    int mergemore(int l, Node *start1, Node *start2);
};

int SinglyLinkedList::mergepoint(Node *start1, Node *start2)
{
    int l1 = length(start1);
    int l2 = length(start2);
    int l;

    if (l1 > l2)
    {
        l = l1 - l2;
        return mergemore(l, start1, start2);
    }
    else
    {
        l = l2 - l1;
        return mergemore(l, start2, start1);
    }
}

int SinglyLinkedList::mergemore(int l, Node *start1, Node *start2)
{
    Node *t1 = start1;
    Node *t2 = start2;
    int i;
    for (i = 0; i < l; i++)
    {
        if (t1 == NULL)
        {
            return -1;
        }
        t1 = t1->next;
    }

    //seraching for the merge point
    while (t1 != NULL && t2 != NULL)
    {
        if (t1 == t2)
            return t1->data;

        t1 = t1->next;
        t2 = t2->next;
    }
    return -1;
}

int SinglyLinkedList::length(Node *start)
{
    Node *t = start;
    int c = 0;
    while (t != NULL)
    {
        c++; //counting the no of nodes
        t = t->next;
    }
    return c;
}

int main()
{
    //clrscr();
    Node *n;
    Node *t1 = new Node();
    Node *t2 = new Node();
    SinglyLinkedList sl; //object

    // the two lists are: 11->22->33->44->55   and 1->44->55

    t1->data = 1;

    t2->data = 11;

    n = new Node();
    n->data = 22;
    t2->next = n;

    n = new Node();
    n->data = 33;
    t2->next->next = n;

    n = new Node();
    n->data = 44;
    t1->next = n;
    t2->next->next->next = n;

    n = new Node();
    n->data = 55;
    t1->next->next = n;

    t1->next->next->next = NULL;

    cout << "Merging point of both linked lists is " << sl.mergepoint(t1, t2);

    //getch();
    return 0;
}



/*Output:
Merging point of both linked lists is 44
*/