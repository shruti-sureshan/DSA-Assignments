#include <stdio.h>
#include <stdlib.h>
// #include <conio.h>

//BST implementation using structures and pointers
struct node
{
	int data;
	struct node *l;
	struct node *r;
} *root = NULL;

struct node *insert();
void preorder(struct node *);
void inorder(struct node *);
void postorder(struct node *);
struct node *search(struct node *t);
struct node *deleteEle(struct node *root, int m);
struct node *getsuccessor(struct node *curr);
int main()
{
	int choice, m;
	struct node *s;
	//clrscr();
	do
	{
		printf("\n 1. Insert Element");
		printf("\n 2. Preorder Traversal");
		printf("\n 3. Inorder Traversal");
		printf("\n 4. Postorder Traversal");
		printf("\n 5. Delete an element");
		printf("\n 6. Search an element");
		printf("\n Enter your option : ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			root = insert();
			break;
		case 2:
			printf("\n The elements of the tree are : \n");
			preorder(root);
			break;
		case 3:
			printf("\n The elements of the tree are : \n");
			inorder(root);
			break;
		case 4:
			printf("\n The elements of the tree are : \n");
			postorder(root);
			break;
		case 5:
			printf("enter the element to be deleted\n");
			scanf("%d", &m);
			deleteEle(root, m);
			break;
		case 6:
			s = search(root);
			if (s == NULL)
				printf("element not found\n");
			else
				printf("element found\n");

			break;
		}

		printf("\npress 1 to continue\n");
		scanf("%d", &choice);
	} while (choice == 1);
	//getch();
	return 0;
}

//create tree and insert elements
struct node *insert()
{
	int x, found, choice;
	struct node *n, *t, *parent;
	do
	{
		printf("Enter Element\n");
		scanf("%d", &x);

		n = (struct node *)malloc(sizeof(struct node));
		n->data = x;
		n->l = n->r = NULL;
		if (root == NULL)
		{
			root = n;
		}
		else
		{
			found = 0;
			t = parent = root;
			while (t && found == 0)
			{
				parent = t;
				if (t->data == x)
				{
					found = 1;
				}
				else if (x < t->data)
				{
					t = t->l;
				}
				else
				{
					t = t->r;
				}
			}

			if (found == 1)
			{
				printf("Duplicate not allowed\n");
			}
			else
			{
				if (x < parent->data)
				{
					parent->l = n;
				}
				else
				{
					parent->r = n;
				}
			}
		}

		printf("Press 1 to enter more elements: ");
		scanf("%d", &choice);
	} while (choice == 1);
	return (root);
}

//preorder traversal
void preorder(struct node *t)
{
	if (t)
	{
		printf("%d\t", t->data);
		preorder(t->l);
		preorder(t->r);
	}
}

//inorder traversal
void inorder(struct node *t)
{
	if (t)
	{
		inorder(t->l);
		printf("%d\t", t->data);
		inorder(t->r);
	}
}

//postorder traversal
void postorder(struct node *t)
{
	if (t)
	{
		postorder(t->l);
		postorder(t->r);
		printf("%d\t", t->data);
	}
}

struct node *deleteEle(struct node *root, int x)
{
	if (root == NULL)
		return root;
	if (root->data > x)
		root->l = deleteEle(root->l, x);
	else if (root->data < x)
		root->r = deleteEle(root->r, x);
	else
	{
		if (root->l == NULL)
		{
			struct node *t = root->r;
			free(root);
			return t;
		}
		else if (root->r == NULL)
		{
			struct node *t = root->l;
			free(root);
			return t;
		}
		struct node *succ = getsuccessor(root->r);
		root->data = succ->data;
		root->r = deleteEle(root->r, succ->data);
	}
	return root;
}

struct node *getsuccessor(struct node *curr)
{
	curr = curr->r;
	while (curr && curr->l != NULL)
		curr = curr->l;
	return curr;
}

//search element
struct node *search(struct node *t)
{
	int b;
	printf("enter element to be searched\n");
	scanf("%d", &b);
	while (t && t->data != b)
	{
		if (b < t->data)
			t = t->l;
		else
			t = t->r;
	}

	return t;
}

/*Output:
 1. Insert Element
 2. Preorder Traversal 
 3. Inorder Traversal  
 4. Postorder Traversal
 5. Delete an element  
 6. Search an element  
 Enter your option : 1 
Enter Element
2
Press 1 to enter more elements: 1
Enter Element
1
Press 1 to enter more elements: 1
Enter Element
4
Press 1 to enter more elements: 1
Enter Element
3
Press 1 to enter more elements: 1
Enter Element
5
Press 1 to enter more elements: 2

press 1 to continue
1

 1. Insert Element
 2. Preorder Traversal
 3. Inorder Traversal
 4. Postorder Traversal
 5. Delete an element
 6. Search an element
 Enter your option : 2

 The elements of the tree are :
2       1       4       3       5
press 1 to continue
1

 1. Insert Element
 2. Preorder Traversal
 3. Inorder Traversal
 4. Postorder Traversal
 5. Delete an element
 6. Search an element
 Enter your option : 3

 The elements of the tree are :
1       2       3       4       5
press 1 to continue
1

 1. Insert Element
 2. Preorder Traversal
 3. Inorder Traversal
 4. Postorder Traversal
 5. Delete an element
 6. Search an element
 Enter your option : 4

 The elements of the tree are :
1       3       5       4       2
press 1 to continue
1

 1. Insert Element
 2. Preorder Traversal
 3. Inorder Traversal
 4. Postorder Traversal
 5. Delete an element
 6. Search an element
 Enter your option : 5
enter the element to be deleted
3

press 1 to continue
1

 1. Insert Element
 2. Preorder Traversal
 3. Inorder Traversal
 4. Postorder Traversal
 5. Delete an element
 6. Search an element
 Enter your option : 4

 The elements of the tree are :
1       5       4       2
press 1 to continue
1

 1. Insert Element
 2. Preorder Traversal
 3. Inorder Traversal
 4. Postorder Traversal
 5. Delete an element
 6. Search an element
 Enter your option : 6
enter element to be searched
5
element found

press 1 to continue
2*/