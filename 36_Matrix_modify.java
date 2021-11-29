/*Given an NXN matrix having binary values. For each 1 encountered, mark its whole row and column as 1.
Expected Time Complexity- O(N^2)

Input Format:
First line of input contains the value of N.
Next N lines contain N space-separated integers(0/1) corresponding to elements of the matrix.

Constraints:
1 <= N <= 700
0 <= A[i][j] <=1

Output Format:
Print the modified matrix. N lines corresponding to N rows, each row having N space-separated values.

Sample Input:
2
1 0
1 0

Sample Output:
1 1
1 1
*/

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    
    //print the output
     public static void display(int a[ ][ ], int row, int col)
    {
        int i, j;
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                System.out.print(a[i][j]+ " ");
            }
            System.out.println();
        }
    }


//set up ones in particular row and columns
    public static void binaryone(int a[ ][ ], int row, int col)
    {
        int i, j;
        int t1[ ]= new int [row]; // for row
        int t2[ ]= new int [col]; //for column
       
     //initialize
        for (i = 0; i < row; i++)
        {
        t1[i] = 0;
        }
     
   //initialize
        for (i = 0; i < col; i++)
        {
        t2[i] = 0;
        }
     
//setting up ones
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                if (a[i][j] == 1)
                {
                    t1[i] = 1;
                    t2[j] = 1;
                }
            }
        }
     
   
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                if ( t1[i] == 1 || t2[j] == 1 )
                {
                    a[i][j] = 1;
                }
            }
        }
    }

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
            int n;
    Scanner sc=new Scanner(System.in);
        n= sc.nextInt();  
    //int a[n][n];
        int[][] a = new int[n][n];
        
        //input array
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]= sc.nextInt();  
        }
    }
        binaryone(a,n,n);
        display(a,n,n);

    }
}