/*Given an array A of N integers. Find the maximum sum of K consecutive elements in the array.
Expected Time Complexity - O(N)

Input Format:
First Line of the input contains two space-separated integers N and K respectively
Next line contains N space-separated integers which are the elements of the array

Constraints:
1 <= N <= 10^5
1 <= K <= 10^4
1 <= A[i] <= 10^4

Output Format:
Print a single integer which is the maximum possible sum of K consecutive elements

Sample Input:
6 2
12 10 15 30 21 6
Sample Output:
51
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int maximum_sum_subarray(int a[], int n, int k)     
{

    int sum = 0;
    for (int i=0; i<k; i++)     //first window
       sum += a[i];
 
    int current = sum;
    for (int i=k; i<n; i++)     //sliding window 
    {
       current =current+ a[i] - a[i-k];
       sum = max(sum, current);
    }
 
    return sum;
}
  
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, k;
    cin>>n>>k;
        int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
     cout << maximum_sum_subarray(a, n, k);
    

    return 0;
}