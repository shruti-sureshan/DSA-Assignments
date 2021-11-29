#include <stdio.h>
#include <iostream>
#include <stdlib.h>
// #include <conio.h>
using namespace std;

#define N 3

class CQueue
{
  int f, r;
  int data[N];

public:
  CQueue() //constructor
  {
    f = -1;
    r = -1;
  }

  //function declaration
  void insert();
  void del();
  void display();
  void search();
};

void CQueue::insert()
{
  int x, choice;
  do
  {
    cout << "Enter element to be inserted\n";
    cin >> x;
    if (f == (r + 1) % N)
    {
      cout << "QUEUE IS FULL\n";
    }
    else
    {
      if (f == -1 && r == -1)
      {
        f = r = 0;
      }
      else
      {
        r = (r + 1) % N;
      }

      data[r] = x;
    }

    cout << "Press 1 to enter more elements: ";
    cin >> choice;
  } while (choice == 1);
}

void CQueue::del()
{
  if (f == -1 && r == -1)
  {
    cout << "QUEUE IS EMPTY\n";
  }
  else
  {
    if (f == r)
    {
      cout << "deleting " << data[f] << "\n";
      f = r = -1;
    }
    else
    {
      cout << "deleting " << data[f] << "\n";
      f = (f + 1) % N;
    }
  }
}

void CQueue::display()
{
  int i;
  if (f == -1 && r == -1)
  {
    cout << "QUEUE IS EMPTY\n";
  }
  else
  {
    i = f;
    cout << "The elements are: \n";
    while (i != r)
    {
      cout << data[i] << "\n";
      i = (i + 1) % N;
    }
    cout << data[i] << "\n";
  }
}

void CQueue::search()
{
  int i;
  int x;
  int flag = 0;
  cout << "enter element to be search\n";
  cin >> x;
  if (f == -1 && r == -1)
  {
    cout << "QUEUE IS EMPTY\n";
  }
  else
  {
    for (int i = f; i <= r; i++)
    {
      if (data[i] == x)
      {
        flag = 1;
        cout << "Element found at " << i << "\n";
        break;
      }
    }
    if (flag == 0)
      cout << "element not found\n";
  }
}

int main()
{
  // clrscr();

  int ch, choice, x;
  CQueue cq; //object
  do
  {
    cout << "1.Insert\n2.Delete\n3.Display\n4.Search\n";
    cout << "Enter your choice\n";
    cin >> ch;
    switch (ch)
    {
    case 1:
      cq.insert();
      break;
    case 2:
      cq.del();
      break;
    case 3:
      cq.display();
      break;
    case 4:
      cq.search();
      break;
    }
    cout << "Press 1 to continue\n";
    cin >> choice;
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
Enter your choice
1
Enter element to be inserted
11
Press 1 to enter more elements: 1
Enter element to be inserted
22
Press 1 to enter more elements: 1
Enter element to be inserted
33
Press 1 to enter more elements: 1
Enter element to be inserted
44
QUEUE IS FULL
Press 1 to enter more elements: 2
Press 1 to continue
1
1.Insert
2.Delete
3.Display
4.Search
Enter your choice
3
The elements are: 
11
22
33
Press 1 to continue
1
1.Insert
2.Delete
3.Display
4.Search
Enter your choice
2
deleting 11
Press 1 to continue
1
1.Insert
2.Delete
3.Display
4.Search
Enter your choice
3
The elements are: 
22
33
Press 1 to continue
1
1.Insert
2.Delete
3.Display
4.Search
Enter your choice
4
enter element to be search
33
Element found at 2
Press 1 to continue
2

*/