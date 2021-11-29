#include <stdio.h>
#include <iostream>
#include <stdlib.h>
// #include <conio.h>
using namespace std;

struct Node
{
    int data;
    struct Node *l, *r;
};

Node* insert(int data);
void check(struct Node* start);
bool check_mirror_img(struct Node* start1, struct Node* start2);


Node* insert(int data)
{
    Node* t = new Node;
    t->data = data;
    t->l = t->r = NULL;
    return (t);
}
 


void check(struct Node* start)
{
    bool a=check_mirror_img(start, start);
        if(a)
      cout<<"The tree is symmetric";
    else
      cout<<"The tree is not symmetric";
}


bool check_mirror_img(struct Node* start1, struct Node* start2)
{

    if (start1 == NULL && start2 == NULL)
        return true;

    if (start1 && start2 && start1->data == start2->data)
        return check_mirror_img(start1->l, start2->r)
               && check_mirror_img(start1->r, start2->l);

    return false;
}
 

 


int main()
{
    Node* start = insert(10);
    start->l = insert(50);
    start->r = insert(50);
    start->l->l = insert(80);
    start->l->r = insert(20);
    start->r->l = insert(20);
    start->r->r = insert(80);
    check(start);
return 0;
}


/*
            10
           /  \
          50   50
         / \   / \
        80 20 20 80

Output:
The tree is symmetric
*/