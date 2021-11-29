#include <stdio.h>
#include <iostream>
#include <stdlib.h>
// #include <conio.h>
#define N 10
using namespace std;

//Queue implementation using classes and objects
class Queue
{
    public:
	int top1, top2, count;
	int s1[N];
    int s2[N];


	Queue() //constructor
	{
		top1=-1;
        top2=-1;
        count=0;
	}

	//function declaration
	void Enqueue(int x);
	void Dequeue();
	void displayElement();
    void push1(int data);
    void push2(int data);
    int pop1();
    int pop2();
};

//Insertion
void Queue::Enqueue(int x)
{
push1(x);
count++;
}

void Queue::push1(int data){
    if(top1==N-1)
        cout<<"overflow";
    else{
        top1++;
        s1[top1]=data;
    }
}

void Queue::push2(int data){
    if(top2==N-1)
        cout<<"overflow";
    else{
        top2++;
        s2[top2]=data;
    }
}


void Queue::Dequeue()
{
	int i,a,b;
    if(top1==-1 && top2==-1)
        cout<<"Queue is empty";
    else{
        for(i=0;i<count;i++){
            a=pop1();
            push2(a);
        }
        b=pop2();
        cout<<"Deleting "<<b<<"\n";
        count--;
        for(i=0;i<count;i++){
            a=pop2();
            push1(a);
        }
    }
}

int Queue::pop1(){
return s1[top1--];
}

int Queue::pop2(){
    return s2[top2--];
}




void Queue::displayElement()
{
    cout<<"The elements are:\n";
    for(int i=0;i<=top1;i++){
        cout<<s1[i]<<"\n";
    }
}

int main()
{
	//clrscr();
	int choice;
	Queue q; //object
int element;
	do
	{
		cout << "1.Insert\n2.Delete\n3.Display\n";
		cout << "enter your choice\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
        cout<<"Enter the element:\n";
        cin>>element;
			q.Enqueue(element);
			break;
		case 2:
			q.Dequeue();
			break;
		case 3:
			q.displayElement();
			break;
		}

		cout << "Enter 1 to continue: ";
		cin >> choice;
	} while (choice == 1);
	//printf("Press any key to exit");
	//getch();
	return 0;
}


