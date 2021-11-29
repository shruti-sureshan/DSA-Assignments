#include <stdio.h>
#include <iostream>
#include <stdlib.h>
// #include <conio.h>
using namespace std;

//BST implementation using classes and objects
class Node
{
public:
	int data;
	Node *l;
	Node *r;
	Node() //constructor
	{
		l = NULL;
		r = NULL;
	}
};

class Tree
{
	Node *root;

public:
	Tree() //constructor
	{
		root = NULL;
	}

	//function declaration
	Node *insert();
	void preorder(Node *);
	void inorder(Node *);
	void postorder(Node *);
	Node *deleteEle(Node *root, int m);
	Node *getsuccessor(Node *node);
	Node *search(Node *t);
};

//Creation of a linked list or Insert in the end
Node *Tree::insert()
{
	int x, found, choice;
	Node *t, *parent;
	do
	{
		cout << "Enter Element\n";
		cin >> x;
		Node *n = new Node();
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
				cout << "Duplicate not allowed\n";
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

		cout << "Press 1 to enter more elements: ";
		cin >> choice;
	} while (choice == 1);
	return (root);
}

void Tree::preorder(Node *t)
{
	if (t)
	{
		cout << t->data << "\t";
		preorder(t->l);
		preorder(t->r);
	}
}

void Tree::postorder(Node *t)
{
	if (t)
	{
		postorder(t->l);
		postorder(t->r);
		cout << t->data << "\t";
	}
}

void Tree::inorder(Node *t)
{
	if (t)
	{
		inorder(t->l);
		cout << t->data << "\t";
		inorder(t->r);
	}
}

Node *Tree::getsuccessor(Node *curr)
{
	curr = curr->r;
	while (curr && curr->l != NULL)
		curr = curr->l;
	return curr;
}

//delete element
Node *Tree::deleteEle(Node *root, int x)
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
			Node *t = root->r;
			free(root);
			return t;
		}
		else if (root->r == NULL)
		{
			Node *t = root->l;
			free(root);
			return t;
		}
		Node *succ = getsuccessor(root->r);
		root->data = succ->data;
		root->r = deleteEle(root->r, succ->data);
	}
	return root;
}

//search element
Node *Tree::search(Node *t)
{
	int b;
	cout << "Enter element to be searched\n";
	cin >> b;
	while (t && t->data != b)
	{
		if (b < t->data)
			t = t->l;
		else
			t = t->r;
	}

	return t;
}

int main()
{
	//clrscr();
	int choice, m;
	Tree t; //object
	Node *root;
	do
	{
		cout << "1.Insert\n2.Preorder Traversal\n3.Inorder Traversal\n4.Postorder Traversal\n5.Delete an element\n6.Search\nEnter your Choice: \n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			root = t.insert();
			break;
		case 2:
			cout << "\n The elements of the tree are : \n";
			t.preorder(root);
			break;
		case 3:
			cout << "\n The elements of the tree are : \n";
			t.inorder(root);
			break;
		case 4:
			cout << "\n The elements of the tree are : \n";
			t.postorder(root);
			break;
		case 5:
			cout << "enter the element to be deleted\n";
			cin >> m;
			t.deleteEle(root, m);
			break;
		case 6:
			Node *s = t.search(root);
			if (s == NULL)
				cout << "element not found\n";
			else
				cout << "element found\n";

			break;
		}

		cout << "\nEnter 1 to continue: ";
		cin >> choice;
	} while (choice == 1);
	//printf("Press any key to exit");
	//getch();
	return 0;
}

/*OUTPUT:
1.Insert
2.Preorder Traversal 
3.Inorder Traversal  
4.Postorder Traversal
5.Delete an element  
6.Search
Enter your Choice:   
1
Enter Element
2
Press 1 to enter more elements: 1
Enter Element
4
Press 1 to enter more elements: 1
Enter Element
1
Press 1 to enter more elements: 1
Enter Element
3
Press 1 to enter more elements: 1
Enter Element
5
Press 1 to enter more elements: 2

Enter 1 to continue: 1
1.Insert
2.Preorder Traversal
3.Inorder Traversal
4.Postorder Traversal
5.Delete an element
6.Search
Enter your Choice:
2

 The elements of the tree are :
2       1       4       3       5
Enter 1 to continue: 1
1.Insert
2.Preorder Traversal
3.Inorder Traversal
4.Postorder Traversal
5.Delete an element
6.Search
Enter your Choice:
3

 The elements of the tree are :
1       2       3       4       5
Enter 1 to continue: 1
1.Insert
2.Preorder Traversal
3.Inorder Traversal
4.Postorder Traversal
5.Delete an element
6.Search
Enter your Choice:
4

 The elements of the tree are :
1       3       5       4       2
Enter 1 to continue: 1
1.Insert
2.Preorder Traversal
3.Inorder Traversal
4.Postorder Traversal
5.Delete an element
6.Search
Enter your Choice:
5
enter the element to be deleted
3

Enter 1 to continue: 1
1.Insert
2.Preorder Traversal
3.Inorder Traversal
4.Postorder Traversal
5.Delete an element
6.Search
Enter your Choice:
4

 The elements of the tree are :
1       5       4       2
Enter 1 to continue: 1
1.Insert
2.Preorder Traversal
3.Inorder Traversal
4.Postorder Traversal
5.Delete an element
6.Search
Enter your Choice:
6
Enter element to be searched
4
element found

Enter 1 to continue: 2
*/