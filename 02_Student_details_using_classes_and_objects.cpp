#include <stdio.h>
#include <iostream>
#include<string.h>
#include <stdlib.h>
// #include <conio.h>
using namespace std;

//Student details using classes and objects
class Node
{
	public:
    int rollno;
    char sname[20];
    float marks;
	Node *next;
    Node *start;
	Node()      //constructor
	{
		next = NULL;
        start=NULL;
	}
};


//Student class
class Student
{
	Node *start;
	public:
		
    Student(){
        start=NULL;
    }

	//function declaration 
    void insert(int rollno, char* sname, float marks);
    void search(int rollno);
    void update(int rollno);
    void Delete(int rollno);
    void display();
};



//Insert student details
void Student::insert(int rollno, char* sname, float marks)
{
    Node *s = new Node();
    s->rollno = rollno;
    strcpy(s->sname, sname);
    s->marks = marks;
    s->next = NULL;
    
    if(start==NULL){
        start = s;
    }
    else{
        s->next = start;
        start = s;
    }
    
}

//Search student details by roll no
void Student::search(int rollno)
{
    Node *t = start;
    while(t!=NULL){
        if(t->rollno==rollno){
            cout<<"Roll No: "<< t->rollno<<"\n";
            cout<<"Name: "<<t->sname<<"\n";
            cout<<"Marks: "<< t->marks<<"\n";
            return;
        }
        t = t->next;
    }
    cout<<"Not found\n";
}


//Update student details by roll no
void Student::update(int rollno)
{
    
    Node *t = start;
    while(t!=NULL){
        
        if(t->rollno==rollno){
            cout<<"Enter new name: ";
            cin>> t->sname;
            cout<<"Enter new marks: ";
            cin>>t->marks;
            return;
        }
        t = t->next;
        
    }
    cout<<"Not found\n";
    
}


//Delete student details by roll no
void Student::Delete(int rollno)
{
    Node *t1 = start;
    Node *t2 = start; 
    while(t1!=NULL){
        if(t1->rollno==rollno){
            if(t1==t2){
                start = start->next;
                free(t1);
            }
            else{
                t2->next = t1->next;
                free(t1); 
            }
            return;
        }
        t2 = t1;
        t1 = t1->next;
        
    }
    cout<<"Not found\n";
    
}


//Display student details
void Student::display()
{
    Node *t = start;
    while(t!=NULL){
        
        cout<<"Roll NO: "<< t->rollno<<"\n";
        cout<<"Name: " <<t->sname<<"\n";
        cout<<"Marks: "<< t->marks<<"\n";
        t = t->next;
        
    }
}


int main()
{
    int choice;
    char sname[20];
    int rollno;
    float marks;
    Student s;      //Object
    cout<<"1.Insert\n2.Search\n3.Delete\n4.Update\n5.Display\nEnter your choice:\n";
    do
    {
        cout<<"\nEnter Choice: ";
        cin>>choice;
        switch (choice)
        {
            case 1:
                cout<<"Enter roll number: ";
                cin>>rollno;
                cout<<"Enter name: ";
                cin>>sname;
                cout<<"Enter marks: ";
                cin>>marks;
                s.insert(rollno, sname, marks);
                break;
            case 2:
                cout<<"Enter roll no: ";
                cin>>rollno;
                s.search(rollno);
                break;
            case 3:
                cout<<"Enter roll no: ";
                cin>>rollno;
                s.Delete(rollno);
                break;
            case 4:
                cout<<"Enter roll no: ";
                cin>>rollno;
                s.update(rollno);
                break;
            case 5:
            cout<<"The records are:\n";
                s.display();
                break;
        }
        
    printf("\nEnter 1 to continue: ");
scanf("%d", &choice);
} while (choice == 1);
}


/*OUTPUT:
1.Insert
2.Search
3.Delete
4.Update
5.Display
Enter your choice:

Enter Choice: 1   
Enter roll number: 1
Enter name: abc   
Enter marks: 20

Enter 1 to continue: 1

Enter Choice: 1
Enter roll number: 2
Enter name: xyz
Enter marks: 30

Enter 1 to continue: 1

Enter Choice: 1
Enter roll number: 3
Enter name: pqr
Enter marks: 40

Enter 1 to continue: 1

Enter Choice: 5
The records are:
Roll NO: 3
Name: pqr
Marks: 40
Roll NO: 2
Name: xyz
Marks: 30
Roll NO: 1
Name: abc
Marks: 20

Enter 1 to continue: 1

Enter Choice: 2
Enter roll no: 2
Roll No: 2
Name: xyz
Marks: 30

Enter 1 to continue: 1

Enter Choice: 3
Enter roll no: 2

Enter 1 to continue: 1

Enter Choice: 5
The records are:
Roll NO: 3
Name: pqr
Marks: 40
Roll NO: 1
Name: abc
Marks: 20

Enter 1 to continue: 1

Enter Choice: 4
Enter roll no: 3
Enter new name: mno
Enter new marks: 60

Enter 1 to continue: 1

Enter Choice: 5
The records are:
Roll NO: 3
Name: mno
Marks: 60
Roll NO: 1
Name: abc
Marks: 20

Enter 1 to continue: 2
*/