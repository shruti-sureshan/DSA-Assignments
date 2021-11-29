#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>

void display();
void insert_right();
void insert_left();
void search();
void delete_right();
void delete_left();

//Deque implementation using structure and pointers
struct Node
{
	int data;
	struct Node *next;
	struct Node *prev;
} *start = NULL;

//Creation of a linked list or Insert in the end
void insert_right()
{
	int choice;
	struct Node *n = NULL;
	struct Node *t;
	do
	{
		n = (struct Node *)malloc(sizeof(struct Node)); //dynamic memory allocation
		printf("Enter Element:\n");
		scanf("%d", &n->data);
		n->next = NULL;
		if (start == NULL)
			start = n; //first element of the linked list
		else
		{
			//traverse till the end of the list
			t = start;
			while (t->next)
				t = t->next;
			t->next = n; //insert the element in the end
			n->prev = t;
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
	while (t)
	{
		printf("%d\n", t->data); //traversing and printing all elements
		t = t->next;
	}
}

//insert element in the beginning of the linked list
void insert_left()
{
	struct Node *n;
	n = (struct Node *)malloc(sizeof(struct Node));
	printf("Enter Data to be inserted:");
	scanf("%d", &n->data);
	if (start == NULL)
	{
		printf("LINKED LIST NOT CREATED");
		start = n;
	}
	else
	{
		n->next = start;
		start->prev = n;
		start = n;
	}

	display();
}

//Search for a given element
void search()
{
	struct Node *t;
	int pos = 1, element;
	printf("Enter element to be searched:");
	scanf("%d", &element);
	if (start == NULL)
		printf("LINKED LIST NOT CREATED");
	else
	{
		for (t = start; t != NULL; t = t->next)
		{
			if (t->data == element)
			{
				printf("Element found at position %d\n", pos);
				break;
			}

			pos++;
		}

		if (t == NULL)
			printf("Element not found\n");
	}
}

//Delete element from a linked list
void delete_right()
{
	struct Node *t, *prev, *x;
	t = start;
	if (start == NULL)
		printf("LINKED LIST NOT CREATED");
	else
	{
		while (t)
		{
			prev = t;
			t = t->next;
		}
		printf("Deleting %d\n", prev->data);
		prev->prev->next = NULL;
		free(prev);
	}

	display();
}

void delete_left()
{
	struct Node *t, *prev, *x;
	t = start;
	if (start == NULL)
		printf("LINKED LIST NOT CREATED");
	else
	{
		x = start;
		printf("Deleting %d\n", x->data);
		start = start->next;
		start->prev = NULL;
		free(x);
	}

	display();
}

int main()
{
	//clrscr();
	int choice;
	do
	{
		printf("1.Insert Right\n2.Insert Left\n3.Delete Right\n4.Delete Left\n5.Display\n6.Search an element\nEnter your Choice: \n");

		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			insert_right();
			break;
		case 2:
			insert_left();
			break;
		case 3:
			delete_right();
			break;
		case 4:
			delete_left();
			break;
		case 5:
			display();
			break;
		case 6:
			search();
			break;
		}

		printf("Enter 1 to continue: ");
		scanf("%d", &choice);
	} while (choice == 1);
	//printf("Press any key to exit");
	//getch();
	return 0;
}

/*OUTPUT:
1.Insert Right     
2.Insert Left      
3.Delete Right     
4.Delete Left      
5.Display
6.Search an element
Enter your Choice: 
1
Enter Element:
2
Press 1 to enter more elements: 1
Enter Element:
3
Press 1 to enter more elements: 1
Enter Element:
5
Press 1 to enter more elements: 1
Enter Element:
6
Press 1 to enter more elements: 1
Enter Element:
7
Press 1 to enter more elements: 2
The elements of the linked list are:
2
3
5
6
7
Enter 1 to continue: 1
1.Insert Right
2.Insert Left
3.Delete Right
4.Delete Left
5.Display
6.Search an element
Enter your Choice:
2
Enter Data to be inserted:1
The elements of the linked list are:
1
2
3
5
6
7
Enter 1 to continue: 1
1.Insert Right
2.Insert Left
3.Delete Right
4.Delete Left
5.Display
6.Search an element
Enter your Choice:
3
Deleting 7
The elements of the linked list are:
1
2
3
5
6
Enter 1 to continue: 1
1.Insert Right
2.Insert Left
3.Delete Right
4.Delete Left
5.Display
6.Search an element
Enter your Choice:
4
Deleting 1
The elements of the linked list are:
2
3
5
6
Enter 1 to continue: 1
1.Insert Right
2.Insert Left
3.Delete Right
4.Delete Left
5.Display
6.Search an element
Enter your Choice:
5
The elements of the linked list are:
2
3
5
6
Enter 1 to continue: 1
1.Insert Right
2.Insert Left
3.Delete Right
4.Delete Left
5.Display
6.Search an element
Enter your Choice:
6
Enter element to be searched:3
Element found at position 2
Enter 1 to continue: 2
*/