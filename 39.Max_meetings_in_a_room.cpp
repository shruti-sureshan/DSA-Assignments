/*Given starting and end time of N meetings. One meeting room can be used for only one meeting at a time. Find the minimum number of rooms required to accomodate all the meetings. Starting and end time of a meeting cannot be same. However, start time for a meeting can be equal to end time of another meeting(in this case it is required to allot two different rooms to the meetings starting and ending at that time).
Time is represented in 24-hour format.
Example : 7:30 PM is represented as 1930.

Input Format:
First line of input contains the value of N i.e. the number of meetings to be held.
Second line contains N space-separated integers which is the list of start times.
Third line contains N space-separated integers which is the list of end time.

Constraints:
1 <= N <= 1000

Output Format:
Print a single integer which is the minimum number of meeting rooms required.

Sample Input 0:
3
0930 1145 1200 
1000 1230 1215

Sample Output 0:
2

Sample Input 1:
2
0800 0900
0900 0930

Sample Output 1:
2
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


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




int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int s[n],f[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }

     for(int i=0;i<n;i++){
        cin>>f[i];
    }
    
    quick(s,0,n-1);
       quick(f,0,n-1);
int c=0;
int i=0;
int j=0;
int r=0;
       while(i<n){
           if(s[i]<=f[j]){
               c++;
               i++;
               if(r<c){
                   r=c;
               }
           }
           else{
               --c;
               j++;
           }
       }
       cout<<r;
 
    return 0;
}