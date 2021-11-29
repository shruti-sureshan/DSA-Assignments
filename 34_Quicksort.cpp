/*Given an array A of N integers, sort the array in increasing order using Quick Sort.

Input Format:
First line of input contains N i.e. the number of elements in the array.
Second line contains N space-separated integers which are the elements of the array A.

Constraints:
1 <= N <= 10^3
1 <= A[i] <= 10^5

Output Format:
Print all the elements of the resultant array after sorting the values in a space-separated manner.

Sample Input:
5
12 31 9 11 5

Sample Output:
5 9 11 12 31
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// partition algorithm
int partition(int a[],int lb,int ub)
{
int t,x,up,down;
 x=a[lb];
 up=ub;
 down=lb;
 while(down<up)
 {
 while(a[down]<=x && down<ub)
 {
 down=down+1;
 }
 while(a[up]>x)
      {
    up=up-1;
      }
 if(down<up)
 {
  t=a[down];
  a[down]=a[up];
  a[up]=t;
  }
 }
 a[lb]=a[up];
 a[up]=x;
 /*for(int i=0;i<n;i++)
 {
cout<<a[i]<<" ";
 }
 cout<<"\n";*/
 return up;
}



void quick(int a[],int lb,int ub)
{
 int pivot;
 if(lb<ub)
 {
 pivot=partition(a,lb,ub);

 quick(a,lb,pivot-1);
 quick(a,pivot+1,ub);
 }
}

//print the sorted array
void display(int a[], int n)
{
    for (int i=0; i < n; i++)
        cout<< a[i] <<" ";

}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    quick(a,0,n-1);
    display(a, n);
    return 0;
}