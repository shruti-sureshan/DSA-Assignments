#include<stdio.h>
#include<stdlib.h>
#include <iostream>
//#include<conio.h>
using namespace std;

struct node
{
	int data;
	struct node *l;
	struct node *r;	
};

void DFS(node *root)
{
	if(root)
	{
		cout<<root->data<<"\n";
		DFS(root->l);
		DFS(root->r);
	}
}



node *queue[100];
int front = -1;
int rear = 0;


node *data[100];
int tos=-1;


void push(node *root){
			tos = tos + 1;
			data[tos] = root;

}

node* pop(){
		node *x = data[tos];
		//cout << "Deleted element is " << x << "\n";
		tos = tos - 1;
		return x;
}

void enqueue(node *root)
{	
	queue[rear] = root;
	rear++;		
}

node* dequeue()
{
	front++;
	node *c = queue[front];
	return c;
}

void DFS_stack(node *root)
{
	node *q;
	cout<<"\n";
	push(root);
	while(tos!=-1)
	{
		q = pop();		
		if(q->r!=NULL)	push(q->r);
		if(q->l!=NULL)	push(q->l);		
		cout<<q->data<<"\n";
	
	
	}	
}


void BFS(node *root)
{
	node *q;
	cout<<"\n";
	enqueue(root);
	while(rear-1!=front)
	{
		q = dequeue();		
		cout<<q->data<<"\n";
		if(q->l)
			enqueue(q->l);
		if(q->r)
			enqueue(q->r);		
	
	
	}
	
	
	
}

int main()
{
	int n , i;
	struct node *p , *q , *root;
	cout<<"Enter the number of Nodes in the tree: ";
	scanf("%d",&n);	
	cout<<"Enter the Node data:\n";
	for(i=0;i<n;i++)
	{
		p = (struct node*)malloc(sizeof(struct node));
		scanf("%d",&p->data);
		p->l = NULL;
		p->r = NULL;
		if(i == 0)
		{
			root = p; 
		}
		else
		{	
			q = root;   // for traversing the tree
			while(1)
			{				
				if(p->data > q->data)
				{
					if(q->r == NULL)
						{					
						q->r = p;
						break;
						}
					else
						q = q->r;
				}
				else
				{
					if(q->l == NULL)
						{						
						q->l = p;
						break;
						}
					else
						q = q->l;										
				}				
			}
			
		}
		
	}


	cout<<"\nDFS using Recursion:\n";
	DFS(root);

	cout<<"\nDFS using stack:";
	DFS_stack(root);

	cout<<"\nBFS:";
	BFS(root);	

return 0;
}

/*Output:
Enter the number of Nodes in the tree: 5
Enter the Node data:
10
50
5
2
7

DFS using Recursion:
10
5
2
7
50

DFS using stack:
10
5
2
7
50

BFS:
10
5
50
2
7
*/

