#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>
#define N 3

struct CQueue
{
	int f, r;
	int data[N];
};
typedef struct CQueue Q;

//Insertion
void insert(Q *q)
{
	int element, choice;
	do
	{
		printf("Enter element: ");
		scanf("%d", &element);
		if (q->f == (q->r + 1) % N)
		{
			printf("QUEUE IS FULL\n");
		}
		else
		{
			if (q->f == -1 && q->r == -1)
			{
				q->f = q->r = 0;
			}
			else
			{
				q->r = (q->r + 1) % N;
			}

			q->data[q->r] = element;
		}

		printf("Press 1 to enter more elements: ");
		scanf("%d", &choice);
	} while (choice == 1);
}

//Deletion
void del(Q *q)
{
	if (q->f == -1 && q->r == -1)
	{
		printf("QUEUE IS EMPTY\n");
	}
	else
	{
		if (q->f == q->r)
		{
			printf("deleting %d\n", q->data[q->f]);
			q->f = q->r = -1;
		}
		else
		{
			printf("deleting %d\n", q->data[q->f]);
			q->f = (q->f + 1) % N;
		}
	}
}

//Display or Traversing
void DisplayElement(Q *q)
{
	int i;
	if (q->f == -1 && q->r == -1)
	{
		printf("QUEUE IS EMPTY\n");
	}
	else
	{
		i = q->f;
		printf("The elements are: \n");
		while (i != q->r)
		{
			printf("%d\n", q->data[i]);
			i = (i + 1) % N;
		}
		printf("%d\n", q->data[i]);
	}
}

//Search
void SearchElement(Q *q)
{
	int i;
	int x;
	int flag = 0;
	printf("Enter element to be searched: ");
	scanf("%d", &x);
	if (q->f == -1 && q->r == -1)
	{
		printf("QUEUE IS EMPTY\n");
	}
	else
	{
		for (int i = q->f; i <= q->r; i++)
		{
			if (q->data[i] == x)
			{
				flag = 1;
				printf("Element found at %d\n", i);
				break;
			}
		}
		if (flag == 0)
			printf("Element not found\n");
	}
}

int main()
{
	// clrscr();
	int ch, choice;
	Q q;
	q.f = -1;
	q.r = -1;
	int element;
	do
	{
		printf("1.Insert\n2.Delete\n3.Display\n4.Search\n");
		printf("enter your choice\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			insert(&q);
			break;
		case 2:
			del(&q);
			break;
		case 3:
			DisplayElement(&q);
			break;
		case 4:
			SearchElement(&q);
			break;
		}

		printf("press 1 to continue\n");
		scanf("%d", &choice);
	} while (choice == 1);
	//getch();
	return 0;
}

/*
Output:
1.Insert 
2.Delete 
3.Display
4.Search 
enter your choice
1
Enter element: 33
Press 1 to enter more elements: 1
Enter element: 66
Press 1 to enter more elements: 1
Enter element: 22
Press 1 to enter more elements: 1
Enter element: 11
QUEUE IS FULL
Press 1 to enter more elements: 2
press 1 to continue
1
1.Insert
2.Delete
3.Display
4.Search
enter your choice
3
The elements are: 
33
66
22
press 1 to continue
1
1.Insert
2.Delete
3.Display
4.Search
enter your choice
2
deleting 33
press 1 to continue
1
1.Insert
2.Delete
3.Display
4.Search
enter your choice
3
The elements are: 
66
22
press 1 to continue
1
1.Insert
2.Delete
3.Display
4.Search
enter your choice
4
Enter element to be searched: 22
Element found at 2
press 1 to continue
2

*/