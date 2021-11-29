/*
Its a famous question, given a chess board having N*N cells, you need to place N queens on the board in such a way that no queen attacks any other queen.

Input Format-
The only line of input consists of a single integer denoting N.

Constraints-
1<=N<=10

Output Format-
If it is possible to place all the N queens in such a way that no queen attacks another queen, then print N lines having N integers. 
The integer in ith line and jth column will denote the cell (i,j) of the board and should be 1 if a queen is placed at (i,j) otherwise 0. 
If there are more than way of placing queens print any of them. If it is not possible to place all N queens in the desired way, then print "Not possible" (without quotes).

Sample Input-
5

Sample Output-
1 0 0 0 0 
0 0 1 0 0 
0 0 0 0 1 
0 1 0 0 0 
0 0 0 1 0
*/


#include <stdio.h>

int b[100][100];
int N;

//find if attacking
int findattack(int i,int j)
{
    int k;
    int l;

    for(k=0;k<N;k++)
    {
        if((b[i][k] == 1) || (b[k][j] == 1))
            return 1;
    }

    for(k=0;k<N;k++)
    {
        for(l=0;l<N;l++)
        {
            if(((k+l) == (i+j)) || ((k-l) == (i-j)))
            {
                if(b[k][l] == 1)
                    return 1;
            }
        }
    }
    return 0;
}

//find the solution to the problem
int calculate(int n)
{
    int i;
    int j;

    if(n==0)
        return 1;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if((!findattack(i,j)) && (b[i][j]!=1))
            {
                b[i][j] = 1;
     
                if(calculate(n-1)==1)
                {
                    return 1;
                }
                b[i][j] = 0;
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d",&N); //N*N cells in the board

    int i;
    int j;
  
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            b[i][j]=0;
        }
    }

    calculate(N);

int flag=0;
        for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++){
            if(b[i][j]!=0)
            flag=1;
        }
    }

if(flag==0){
    printf("Not possible");
}
else{
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%d ",b[i][j]);
        printf("\n");
    }
}
return 0;
}