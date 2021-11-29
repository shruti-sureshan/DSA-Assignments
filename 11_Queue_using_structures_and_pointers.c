#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>
#define N 20

//Queue implementation using structures and pointers
struct Queue
{
	int f, r;
	int data[N];
};
typedef struct Queue Q;

//Insertion
void Enqueue(Q *q)
{
	int element, choice;
	do
	{
		printf("Enter element: ");
		scanf("%d", &element);
		if (q->r == N - 1)
			printf("Queue is full");
		else
		{
			q->r = q->r + 1;
			q->data[q->r] = element; //insertion occurs at the rear
			if (q->f == -1)			 //inserting 1st item
				q->f = q->f + 1;
		}

		printf("Press 1 to enter more elements: ");
		scanf("%d", &choice);
	} while (choice == 1);
}

//Deletion
void Dequeue(Q *q)
{
	int x;
	if (q->f == -1)
		printf("Queue is empty");
	else
	{
		x = q->data[q->f]; //deletion occurs at the front
		printf("Deleted element is %d\n", x);
		if (q->f == q->r) //there is only one element in queue
		{
			q->f = -1;
			q->r = -1;
		}

		q->f = q->f + 1;
	}
}

//Display or Traversing
void DisplayElement(Q *q)
{
	if (q->f == -1)
		printf("Queue is empty");
	else
	{
		printf("Elements of the queue are:\n");
		for (int i = q->f; i <= q->r; i++) //traverse throughout the array from front to rear end
		{
			printf("%d\n", q->data[i]);
		}
	}
}

//Search
void SearchElement(Q *q)
{
	int x;
	int flag = 0;
	printf("Enter element to be searched: ");
	scanf("%d", &x);
	if (q->f == -1)
		printf("Queue is empty");
	else
	{
		for (int i = q->f; i <= q->r; i++) //traverse throughout the array from front to rear end
		{
			if (q->data[i] == x) //compare each element
			{
				flag = 1;
				printf("Element found at %d\n", i + 1);
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
			Enqueue(&q);
			break;
		case 2:
			Dequeue(&q);
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
Enter element: 10
Press 1 to enter more elements: 1
Enter element: 20
Press 1 to enter more elements: 1
Enter element: 30
Press 1 to enter more elements: 1
Enter element: 40
Press 1 to enter more elements: 2
press 1 to continue
1
1.Insert
2.Delete
3.Display
4.Search
enter your choice
3
Elements of the queue are:
10
20
30
40
press 1 to continue
1
1.Insert
2.Delete
3.Display
4.Search
enter your choice
2
Deleted element is 10
press 1 to continue
1
1.Insert
2.Delete
3.Display
4.Search
enter your choice
4
Enter element to be searched: 30
Element found at 3
press 1 to continue
2

*/