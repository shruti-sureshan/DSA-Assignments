/*Given a sorted array A of N elements, search for a given key K and return 1 if the element is found. 
If the element is not present in the array, return 0.
Expected time Complexity- O(logN)

Input Format:
First line of the input contains an integer N which is the total number of elements in the array A.
Second line contains N space-separated integers which are the elements of the array A.
The third contains the value of K.

Constraints:
0 < N <= 10^5
0 < A[i], K <= 10^6

Output Format:
Print 1 if Search is Successful i.e. the key is found, Else print 0

Sample Input:
5
2 3 4 7 24
7

Sample Output:
1
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//binary search implementation
int Binsearch(int a[], int l, int h, int k){
    if (h >= l) {
        int mid = l + (h - l) / 2;

        if (a[mid] == k)
            return mid;
  

        if (a[mid] > k)
            return Binsearch(a, l, mid - 1, k);
 
        return Binsearch(a, mid + 1, h, k);
    }
  
    return -1;
}
    
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin>>N;
    int a[N];
    for(int i=0;i<N;i++){
        cin>>a[i];
    }
    int k, loc;
    cin>>k;
    loc=Binsearch(a,0, N-1,k);
    (loc == -1) ? cout << "0": cout << "1";
    return 0;
}