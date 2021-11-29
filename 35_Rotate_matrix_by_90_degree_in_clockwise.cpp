/*Given an NXN matrix A, you are required to rotate it by 90 degrees in clockwise direction.

Input Format:
First line of input contains the valuue of N .
Next N lines contain N space-separated integers which are the elements of the matrix.

Constraints:
1<= N <= 10^3
1 <= A[i][j] <=10^5

Output Format:
Output should contain N lines each having N integers representing the rotated matrix.

Sample Input:
2
1 11
2 21

Sample Output:
2 1
21 11
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    
    //Transpose of the input matrix
    for (int i = 0; i < n; i++)
    {
    for (int j =i+1; j < n; j++)
    {
        swap(a[i][j], a[j][i]);
    }
    }
    
    //swap the columns of the transposed matrix
        for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n/2; j++) {
            swap(a[i][j], a[i][n - j - 1]);
        }
    }
    
    
    //print the rotated matrix
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
           cout<<"\n";
    }
    return 0;
}