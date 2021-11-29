#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>

void display();
void create();
void begin();
void insertAfterGivendata();
void insertAfterGivenpos();
void search();
void deletion();


//Circular Linked list implementation using structure and pointers
struct Node
{
	int data;
	struct Node *next;
}*start = NULL;

//Creation of a linked list or Insert in the end
void create()
{
	int choice;
	struct Node *n = NULL;
  struct Node *t;
	do {
		n = (struct Node *)malloc(sizeof(struct Node));   //dynamic memory allocation
		printf("Enter Element:\n");
		scanf("%d", &n->data);
		n->next = NULL;
		if (start == NULL){
			n->next=n;  
            start=n;
            }    
		else
		{
      //traverse till the end of the list
			t = start;
			while(t->next!=start)    
				t = t->next;
			t->next = n;      //insert the element in the end
            n->next=start;
		}

		printf("Press 1 to enter more elements: ");
		scanf("%d", &choice);
	} while (choice == 1);
	display();
}

//Display all the elements or traverse through the linked list
void display()
{
	struct Node *t;
  t = start;
  printf("The elements of the linked list are:\n");
	while (t->next!=start)
	{
		printf("%d\n", t->data);    //traversing and printing all elements
		t = t->next;
	}
    printf("%d\n", t->data);
}

//insert element in the beginning of the linked list
void begin()
{
	struct Node *n,*t;
	n = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter Data to be inserted:");
	scanf("%d", &n->data);
	if (start == NULL)
	{
		n->next=n;
        start=n;
	}
	else
	{
			t = start;
			while(t->next!=start)    
				t = t->next;
			t->next = n;      
            n->next=start;
            start=n;
	}

	display();
}

//Insert after a given element
void insertAfterGivendata()
{
	struct Node *t, *n;
	int element;
	if (start == NULL){
		n->next=n;
        start=n;
    }
	else
	{
    printf("Enter the element after which you want to insert:\n");
		scanf("%d", &element);
		t = start;
		while (t && t->data != element)
			t = t->next;
		if (t == NULL)
			printf("Element not found\n");
		else
		{
			n = (struct Node *)malloc(sizeof(struct Node));
			printf("Enter the element:\n");

			scanf("%d", &n->data);
			n->next = t->next;
			t->next = n;
		}
	}

	display();
}

//Insert after a given position or index
void insertAfterGivenpos()
{
	struct Node *t, *n;
	int pos, curr = 1;
	if (start == NULL){
		n->next=n;
        start=n;
    }
	else
	{
		printf("Enter Position:\n");
		scanf("%d", &pos);
		t = start;
		while (curr != pos)
		{
			t = t->next;
			curr++;
		}

		n = (struct Node *)malloc(sizeof(struct Node));
		printf("Enter the element to be inserted:\n");
		scanf("%d", &n->data);
		n->next = t->next;
		t->next = n;
	}

	display();
}

//Search for a given element
void search()
{
	struct Node *t;
	int pos = 1, element, flag=0;
	printf("Enter element to be searched:");
	scanf("%d", &element);
	if (start == NULL)
		printf("Circular Linked list not created");
	else{
        struct Node *t;
  t = start;
	do
	{
		if (t->data == element)
			{
                flag=1;
				printf("Element found at position %d\n", pos);
				break;
			}   
            pos++;
		t = t->next;
	}while(t!=start);
	
    if (t == NULL)
			printf("Element not found\n");
    }
}

//Delete element from a linked list
void deletion()
{
	struct Node *t, *prev;
	int element;
	if (start == NULL)
		printf("Circular LINKED LIST NOT CREATED");
	else
	{
		printf("Enter element to be deleted:\n");
		scanf("%d", &element);
		t = start;
        do
		{
			prev = t;
			t = t->next;
		}	while (t!=start && t->data != element);

		if (t == NULL)
		{
			printf("Element Not Found\n");
		}
		else
		{
			if (start == t)
			{
				start = start->next;
				free(t);
			}
			else
			{
				prev->next = t->next;
				free(t);
			}
		}
	}

	display();
}

int main()
{
	//clrscr();
  int choice;
	do {
		printf("1.Create a Linked List or Insert in the end\n2.Display/Traverse\n3.Insert In the Beginning\n4.Insert after a given element\n5.Insert after a given Position\n6.Search an element\n7.Delete an element\nEnter your Choice: \n");

		scanf("%d", &choice);
		switch (choice)
		{
			case 1:
				create();
				break;
			case 2:
				display();
				break;
			case 3:
				begin();
				break;
			case 4:
				insertAfterGivendata();
				break;
			case 5:
				insertAfterGivenpos();
				break;
			case 6:
				search();
				break;
			case 7:
				deletion();
				break;
		}

		printf("Enter 1 to continue: ");
		scanf("%d", &choice);
	} while (choice == 1);
  //printf("Press any key to exit");
	//getch();
  return 0;
}



/*Output:
1.Create a Linked List or Insert in the end
2.Display/Traverse
3.Insert In the Beginning
4.Insert after a given element
5.Insert after a given Position
6.Search an element
7.Delete an element
Enter your Choice: 
1
Enter Element: 2
Press 1 to enter more elements: 1
Enter Element: 3
Press 1 to enter more elements: 1
Enter Element: 4
Press 1 to enter more elements: 1
Enter Element: 5
Press 1 to enter more elements: 1
Enter Element: 6
Press 1 to enter more elements: 2
The elements of the linked list are:
2
3
4
5
6
Enter 1 to continue: 1
1.Create a Linked List or Insert in the end
2.Display/Traverse
3.Insert In the Beginning
4.Insert after a given element
5.Insert after a given Position
6.Search an element
7.Delete an element
Enter your Choice:
2
The elements of the linked list are:
2
3
4
5
6
Enter 1 to continue: 1
1.Create a Linked List or Insert in the end
2.Display/Traverse
3.Insert In the Beginning
4.Insert after a given element
5.Insert after a given Position
6.Search an element
7.Delete an element
Enter your Choice:
3
Enter Element to be inserted: 1
The elements of the linked list are:
1
2
3
4
5
6
Enter 1 to continue: 1
1.Create a Linked List or Insert in the end
2.Display/Traverse
3.Insert In the Beginning
4.Insert after a given element
5.Insert after a given Position
6.Search an element
7.Delete an element
Enter your Choice:
4
Enter the element after which you want to insert:
3
Enter Element to be inserted: 10
The elements of the linked list are:
1
2
3
10
4
5
6
Enter 1 to continue: 1
1.Create a Linked List or Insert in the end
2.Display/Traverse
3.Insert In the Beginning
4.Insert after a given element
5.Insert after a given Position
6.Search an element
7.Delete an element
Enter your Choice:
5
Enter Position:
3
Enter Element to be inserted: 20
The elements of the linked list are:
1
2
3
20
10
4
5
6
Enter 1 to continue: 1
1.Create a Linked List or Insert in the end
2.Display/Traverse
3.Insert In the Beginning
4.Insert after a given element
5.Insert after a given Position
6.Search an element
7.Delete an element
Enter your Choice:
6
Enter element to be searched: 20
Element found at position 4
Enter 1 to continue: 1
1.Create a Linked List or Insert in the end
2.Display/Traverse
3.Insert In the Beginning
4.Insert after a given element
5.Insert after a given Position
6.Search an element
7.Delete an element
Enter your Choice:
7
Enter element to be deleted:
20
The elements of the linked list are:
1
2
3
10
4
5
6
Enter 1 to continue: 2
*/