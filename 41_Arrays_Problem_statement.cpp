/*
There is an array Arr of size N, the problem is to find pairs (i, j) such that it satisfies the below inequality:- 
(Arr[i] | Arr[j]) – (Arr[i] & Arr[j]) = (Arr[i] – Arr[j]); Where “|” denotes bitwise OR and “&” denotes bitwise AND operators.

Input Format:
First line show be T which denotes number of test cases.
First line of each test cases contains an integer N.
Second line of each test cases contains N space-separated integer denoting array Arr.

Output Format:
For each test case, print the number of pairs, in a new line, satisfying the equation.
*/


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    int n;
    cin>>t;
    while(t--){
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int c=0;
        
         for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if((a[i] | a[j])-(a[i]&a[j])==(a[i]-a[j]))
               c++;  
            
        }
         }
        cout<<c;
        
    }
    return 0;
}


