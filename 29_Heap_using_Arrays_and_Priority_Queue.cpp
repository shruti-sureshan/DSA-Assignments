#include <stdio.h>
#include <iostream>
#include <stdlib.h>
// #include <conio.h>
using namespace std;

//heapify
void heapify(int data[], int n, int i)
{
    int maximum = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && data[l] > data[maximum])
        maximum = l;

    if (r < n && data[r] > data[maximum])
        maximum = r;

    if (maximum != i)
    {
        swap(data[i], data[maximum]);
        heapify(data, n, maximum);
    }
}

//build heap
void buildheap(int data[], int n)
{

    int s = (n / 2) - 1;
    for (int i = s; i >= 0; i--)
    {
        heapify(data, n, i);
    }
}

//deletion
void deleteRoot(int data[], int &n)
{
    int last = data[n - 1];
    data[0] = last;
    n = n - 1;
    heapify(data, n, 0);
}

//Heapify after insert
void heapify1(int data[], int n, int i)
{
    int par = (i - 1) / 2;

    if (data[par] > 0)
    {
        if (data[i] > data[par])
        {
            swap(data[i], data[par]);
            heapify1(data, n, par);
        }
    }
}

//insertion
void insert(int data[], int n, int element)
{
    n = n + 1;
    data[n - 1] = element;
    heapify1(data, n, n - 1);
}

//display
void display(int data[], int n)
{
    cout << "Representation of Heap:\n";

    for (int i = 0; i < n; ++i)
        cout << data[i] << " ";
    cout << "\n";
}

//for deletion from priority queue
void deleteQ(int data1[], int m)
{
    int last = data1[m - 1];
    data1[0] = last;
    m = m - 1;
    heapify(data1, m, 0);
}

int main()
{
    int n, m;
    cout << "Enter the no of node: ";
    cin >> n;
    int data[n], data1[10];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    int choice;
    do
    {
        cout << "1.Create Heap using Arrays\n2.Insert\n3.Delete\n4.Display\n5.Create Heap using Priority Queue\nEnter a choice\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            buildheap(data, n);

            display(data, n);
            break;
        case 2:
            int element;
            cout << "enter a value of node to be inserted: ";
            cin >> element;

            insert(data, n, element);
            cout << "insertion\n";
            display(data, n);
            break;
        case 3:
            deleteRoot(data, n);
            cout << "deletion\n";
            display(data, n);
            break;
        case 4:
            display(data, n);
            break;
        case 5:
            cout << "Enter the no of elements in the priority queue : ";
            cin >> m;
            cout << "Enter the elements of the priority queue:\n";
            for (int i = 0; i < m; i++)
            {
                cin >> data1[i];
            }
            buildheap(data1, m);
            display(data1, m);
            deleteQ(data1, m);
            cout << "After deletion:\n";
            display(data1, m);
            break;
        }
        cout << "\nEnter 1 to continue: ";
        cin >> choice;
    } while (choice == 1);
    return 0;
}

/*Output:
Enter the no of node: 5
Enter the elements:
5
3
10
2
4
1.Create Heap using Arrays
2.Insert
3.Delete
4.Display
5.Create Heap using Priority Queue
Enter a choice
1
Representation of Heap:
10 4 5 2 3

Enter 1 to continue: 1
1.Create Heap using Arrays
2.Insert
3.Delete
4.Display
5.Create Heap using Priority Queue
Enter a choice
2
enter a value of node to be inserted: 11
insertion
Representation of Heap:
11 4 10 2 3

Enter 1 to continue: 1
1.Create Heap using Arrays
2.Insert
3.Delete
4.Display
5.Create Heap using Priority Queue
Enter a choice
3
deletion
Representation of Heap:
10 4 3 2 3

Enter 1 to continue: 1
1.Create Heap using Arrays
2.Insert
3.Delete
4.Display
5.Create Heap using Priority Queue
Enter a choice
4
Representation of Heap:
10 4 3 2 3

Enter 1 to continue: 1
1.Create Heap using Arrays
2.Insert
3.Delete
4.Display
5.Create Heap using Priority Queue
Enter a choice
5
Enter the no of elements in the priority queue : 5
Enter the elements of the priority queue:
5
3
10
2
4
Representation of Heap:
10 4 5 2 3
After deletion:
Representation of Heap:
5 4 3 2 3

Enter 1 to continue: 2
*/