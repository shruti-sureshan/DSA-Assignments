/*Given an array A of N integers. Rearrange the array in non-decreasing order.
Expected time complexity - O(N)

Input Format:
First line of input contains N i.e. the number of elements in the array.
Second line contains N space-separated integers which are the elements of the array A.

Constraints:
1 <= T <= 30
1 <= N <= 10^5
1 <= A[i] <= 10^3

Output Format:
Print T lines. ith line contains all the elements of the resultant array after rearranging the values for the ith test case in a space-separated manner.

Sample Input:
2
5
20 4 17 56 18
3
4 1 5

Sample Output:
4 17 18 20 56
1 4 5
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int temp;  
 void heapify(int data[], int n, int i)  
{  
int maximum = i;    
int l = 2*i + 1;    
int r = 2*i + 2;    
  
if (l < n && data[l] >data[maximum])  
maximum = l;  
  
if (r < n && data[r] > data[maximum])  
maximum = r;  
  
if (maximum != i)  
{  
temp = data[i];  
    data[i]= data[maximum];   
    data[maximum] = temp;  
heapify(data, n, maximum);  
}  
}  
  
void heapsort(int data[], int n)  
{  
int i;  
for (i = n / 2 - 1; i >= 0; i--)  
heapify(data, n, i);  
for (i=n-1; i>=0; i--)  
{  
temp = data[0];  
    data[0]= data[i];   
    data[i] = temp;  
heapify(data, i, 0);  
}  
}  



int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int m;
    int n;
    scanf("%d",&m);
    while(m){
    scanf("%d",&n);
    int data[n];
    for(int i=0;i<n;i++){
                 scanf("%d",&data[i]);
    }
    
 heapsort(data, n);

for (int i=0; i<n; ++i)  
printf("%d ",data[i]); 
        printf("\n");
    m--;
    }
       
    return 0;

}