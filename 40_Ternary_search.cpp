/*Given a sorted array A of N integers, your task is to search for a given key K. For this, you need to implement Ternary search.
Ternary search is a divide-and-conquer algorithm similar to binary search. The difference is that in ternary search, we divide the array into 3 parts and check which part contains the key.
Print 1 if Search is Successful i.e. the key is found, Else print 0.

Input Format:
First line of the input contains two space-separated integers, N and K
Second line contains N space-separated integers which are the elements of the array A.

Constraints:
0 < N <= 10^5
0 < A[i], K <= 10^8

Output Format:
Print 1 if Search is Successful i.e. the key is found, Else print 0.

Sample Input:
5 12
11 12 21 51 108

Sample Output:
1
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//ternary search implementation
int tSearch(int l, int h, int k, int a[])
{
    if (h >= l) {
        int m1 = l + (h - l) / 3;
        int m2 = h - (h - l) / 3;
 
        
        if (a[m1] == k) {
            return m1;
        }
        if (a[m2] == k) {
            return m2;
        }
 
       
        if (k < a[m1]) {
 
       
            return tSearch(l, m1 - 1, k, a);
        }
        else if (k > a[m2]) {
 

            return tSearch(m2 + 1, h, k, a);
        }
        else {
 
      
            return tSearch(m1 + 1, m2 - 1, k, a);
        }
    }
 

    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,k;
    cin>>n>>k;
       int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0;
    int h=n-1;
int   p = tSearch(l, h, k, a);
    if(p!=-1)
        cout<<"1";
    else
        cout<<"0";
    return 0;
}