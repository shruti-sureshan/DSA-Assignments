#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>
#define N 20

//stack implementation using structures and pointers
struct Stack
{
	int tos; //top of the stack
	int data[N];
};
typedef struct Stack S;

void pushElement(S *s)
{
	int element, choice;
	do
	{
		printf("Enter element: ");
		scanf("%d", &element);
		if (s->tos == N - 1)
			printf("Stack is full"); //overflow
		else
		{
			s->tos = s->tos + 1;
			s->data[s->tos] = element;
		}

		printf("Press 1 to enter more elements: ");
		scanf("%d", &choice);
	} while (choice == 1);
}

void popElement(S *s)
{
	int x;
	if (s->tos == -1)
		printf("Stack is empty"); //underflow
	else
	{
		x = s->data[s->tos];
		printf("Deleted element is %d\n", x);
		;
		s->tos = s->tos - 1;
	}
}

void peekElement(S *s)
{
	int x;
	if (s->tos == -1)
		printf("Stack is empty"); //underflow
	else
	{
		x = s->data[s->tos];
		printf("Topmost element is %d\n", x);
	}
}

void displayElement(S *s)
{
	if (s->tos == -1)
		printf("Stack is empty"); //underflow
	else
	{
		printf("The elements in the stack are: \n");
		for (int i = s->tos; i >= 0; i--)
			printf("%d\n", s->data[i]);
	}
}

//search
void searchElement(S *s)
{
	int x;
	int flag = 0;
	printf("Enter element to be searched: ");
	scanf("%d", &x);
	if (s->tos == -1)
		printf("Stack is empty"); //underflow
	else
	{
		for (int i = s->tos; i >= 0; i--)
		{
			if (s->data[i] == x) //compare each element
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
	S s;
	s.tos = -1;
	int element;
	do
	{
		printf("1.Push\n2.Pop\n3.Peek\n4.Display\n5.Search\n");
		printf("enter your choice\n");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			pushElement(&s);
			break;
		case 2:
			popElement(&s);
			break;
		case 3:
			peekElement(&s);
			break;
		case 4:
			displayElement(&s);
			break;
		case 5:
			searchElement(&s);
			break;
		}

		printf("press 1 to continue\n");
		scanf("%d", &choice);
	} while (choice == 1);
	//getch();
	return 0;
}

/*Output:
1.Push   
2.Pop    
3.Peek   
4.Display
5.Search 
enter your choice
1
Enter element: 10
Press 1 to enter more elements: 1
Enter element: 20
Press 1 to enter more elements: 1
Enter element: 30
Press 1 to enter more elements: 1
Enter element: 40
Press 1 to enter more elements: 1
Enter element: 50
Press 1 to enter more elements: 2
press 1 to continue
1
1.Push
2.Pop
3.Peek
4.Display
5.Search
enter your choice
2
Deleted element is 50
press 1 to continue
1
1.Push
2.Pop
3.Peek
4.Display
5.Search
enter your choice
3
Topmost element is 40
press 1 to continue
1
1.Push
2.Pop
3.Peek
4.Display
5.Search
enter your choice
4
The elements in the stack are: 
40
30
20
10
press 1 to continue
1
1.Push
2.Pop
3.Peek
4.Display
5.Search
enter your choice
5
Enter element to be searched: 30
Element found at 2
press 1 to continue
2

*/