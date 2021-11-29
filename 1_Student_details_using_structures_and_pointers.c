#include<stdlib.h>
#include<string.h>
#include<stdio.h>
struct Student
{
    int rollno;
    char sname[20];
    float marks;
    struct Student *next;
}* start;

//Insert student details
void insert(int rollno, char* sname, float marks)
{
    struct Student *s = (struct Student *) malloc(sizeof(struct Student));
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

//Search student details by rollno
void search(int rollno)
{
    struct Student *t = start;
    while(t!=NULL){
        if(t->rollno==rollno){
            printf("Roll No: %d\n", t->rollno);
            printf("Name: %s\n", t->sname);
            printf("Marks: %f\n", t->marks);
            return;
        }
        t = t->next;
    }
    printf("Not found\n");
}


//Update student details by rollno
void update(int rollno)
{
    
    struct Student *t = start;
    while(t!=NULL){
        
        if(t->rollno==rollno){
            printf("Enter new name: ");
            scanf("%s", t->sname);
            printf("Enter new marks: ");
            scanf("%f",&t->marks);
            return;
        }
        t = t->next;
        
    }
    printf("Not found\n");
    
}

//Delete student details
void Delete(int rollno)
{
    struct Student *t1 = start;
    struct Student *t2 = start; 
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
    printf("Not found\n");
    
}

//display student details
void display()
{
    struct Student * t = start;
    while(t!=NULL){
        
        printf("Roll NO: %d\n", t->rollno);
        printf("Name: %s\n", t->sname);
        printf("Marks: %f\n", t->marks);
        t = t->next;
        
    }
}


int main()
{
    start = NULL;
    int choice;
    char sname[20];
    int rollno;
    float marks;
    printf("1.Insert\n2.Search\n3.Delete\n4.Update\n5.Display\nEnter your choice:\n");
    do
    {
        printf("\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &rollno);
                printf("Enter name: ");
                scanf("%s", sname);
                printf("Enter marks: ");
                scanf("%f", &marks);
                insert(rollno, sname, marks);
                break;
            case 2:
                printf("Enter roll no: ");
                scanf("%d", &rollno);
                search(rollno);
                break;
            case 3:
                printf("Enter roll no: ");
                scanf("%d", &rollno);
                Delete(rollno);
                break;
            case 4:
                printf("Enter roll no: ");
                scanf("%d", &rollno);
                update(rollno);
                break;
            case 5:
            printf("The records are:\n");
                display();
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