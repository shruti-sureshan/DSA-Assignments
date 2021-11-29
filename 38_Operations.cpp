/*Given an array A of N integers, perform M operations on the array.
Each of the M operations is of the form (i, j, k): from index i to j, increment all values by k. 
After M operations, produce the resultant array A.

Input Format:
First line of input contains the value for N and M in space-separated manner.
Second line contains N integers in space-separated manner which are the elements of the array.
Next M lines correspond to M queries each line having three integers representing i, j, and k.

Constraints:
1 <= N <= 10^5
1 <= A[i] <= 10
0 <= i,j <= N-1
1 <= k <= 10

Output Format:
Print the elements of the resultant array in space-separated manner.

Sample Input:
5 3
2 5 3 1 7
0 2 2
3 4 1
1 3 7

Sample Output:
4 14 12 9 8
*/

#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

    
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int b[m][3];
    for(int i=0;i<m;i++){
        for(int j=0;j<3;j++)
        cin>>b[i][j];
    }
 int mask[n];
 memset(mask, 0, sizeof(mask));
    
    for(int i=0;i<m;i++){
  int l=b[i][0];
  int h=b[i][1];
  
  mask[l] += b[i][2];
        if(h+1<n)
            mask[h+1]-=b[i][2];
            //cout<<l;  
    }

    //prefix sum
    for(int i=1;i<n;i++){
        mask[i]+=mask[i-1];
    }
    
    for(int i=0;i<n;i++){
        cout<<mask[i] + a[i]<<" ";
    }
 
    return 0;
}