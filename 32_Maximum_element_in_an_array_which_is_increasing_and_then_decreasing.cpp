/*Given an array A of N distinct integers which is first increasing and then decreasing. 
Find the maximum number in the array. If the array does not decrease print the last element.
Expected time Complexity- O(logN)

Input Format:
First lne of the input contains an integer N which is the total number of elements in the array A.
Second line contains N space-separated integers which are the elements of the array A.

Constraints:
0 < N <= 10^5
0 < A[i], K <= 10^6

Output Format:
Print the largest element in the array

Sample Input:
6
12 15 21 87 23 11

Sample Output:
87
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int LargestElement(int a[], int l, int h)
{
 
    if (l == h)
        return a[l];    //single element
     

    if ((h == l + 1) && a[l] >= a[h])   //two elements in the array
        return a[l];
     
    if ((h == l + 1) && a[l] < a[h])        //two elements in the array
        return a[h];
     
    int mid = (l + h)/2; /*l + (h - l)/2;*/

    if ( a[mid] > a[mid + 1] && a[mid] > a[mid - 1])
        return a[mid];
     
    if (a[mid] > a[mid + 1] && a[mid] < a[mid - 1])
        return LargestElement(a, l, mid-1);
         
    else
        return LargestElement(a, mid + 1, h);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
        int N;
    cin>>N;
    int a[N];
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
cout<<LargestElement(a, 0, N-1);
    return 0;
}