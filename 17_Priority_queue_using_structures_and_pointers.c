#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>

//function declaration
void insert();
void delete ();
void display();
void search();

//priority queue implementation using structures and pointers
struct node
{
    int data;
    int priority;
    struct node *next;
} *start = NULL;

int main()
{
    int choice;
    //clrscr();
    do
    {
        printf("\n 1. Insert\n 2. Delete\n 3. Display\n 4. Search");
        printf("\n Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            search();
            break;
        }

        printf("\nEnter 1 to continue: ");
        scanf("%d", &choice);
    } while (choice == 1);
}

void insert()
{
    int x, pri, choice;
    struct node *n, *t;
    n = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter the value and its priority : ");
    scanf("%d %d", &x, &pri);
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

void delete ()
{
    struct node *t;
    if (start == NULL)
    {
        printf("\n UNDERFLOW");
        return;
    }
    else
    {
        t = start;
        printf("\n Deleted item is: %d", t->data);
        start = start->next;
        free(t);
    }
    //return start;
}

void display()
{
    struct node *t;
    t = start;
    if (start == NULL)
        printf("\nQUEUE IS EMPTY");
    else
    {
        printf("\n PRIORITY QUEUE IS : ");
        while (t != NULL)
        {
            printf("\t%d[priority=%d]", t->data, t->priority);
            t = t->next;
        }
    }
}

void search()
{
    struct node *t;
    t = start;
    int element, flag = 0;
    printf("enter the element to be searched\n");
    scanf("%d", &element);

    if (start == NULL)
        printf("\nQUEUE IS EMPTY");
    else
    {
        while (t != NULL)
        {
            if (t->data == element)
            {
                printf("element found");
                flag = 1;
                break;
            }
            t = t->next;
        }
    }

    if (flag == 0)
        printf("element not found");
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