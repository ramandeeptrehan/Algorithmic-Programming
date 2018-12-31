/*
 Problem: https://www.codechef.com/problems/PPATTERN
 
 Algorithm:
 Compute upper triangle first. Then compute lower triangle
 
 Lessons learnt: Comments
 
 Bad approach also mentioned below
 
 */

#include <iostream>
using namespace std;

void printPattern(int arr[100][100], int n) //this affects original array as well. Try printing array value in main method
{
    int i, j;
    int x, y;
    int count = 0;
    
    for(j=0; j<n; j++) //upper triangle (traverse across columns)
    {
        x=0;    //fixed parameter for each such diagonal to start with
        y=j;    //appropriate initialization for each diagonal
        
        while(y>=0) //Why? Can we check with x also? No. For each diagonal, corner scenario is when y is 0
        {
            arr[x][y] = ++count;
            x++;
            y--;
        }
    }
    
    for(i=1; i<n; i++) //lower triangle (traverse across columns): start iteration from i=1 (second row)
    {
        y = n-1;    //fixed parameter for each such diagonal to start with
        x = i;      //appropriate initialization for each diagonal
        
        while(x<n) //Why? Can we check with y also? No. For each diagonal, corner scenario is when x is n-1 (last row)
        {
            arr[x][y] = ++count;
            x++;
            y--;
        }
    }
    
    /*
    Bad approach: Just trying to solve as I think. Trying to control parameters. This leads to missing corner cases.
     
    int i, j, k, count = 0;
    for(j=0; j<=n-1; j++)
    {
        k=j;
        for(i=0; i<=j;)
        {
            arr[i][k] = ++count;
     
            if(k>0)
                k--;
            
            i++;
        }
    }
    
    for(i=1; i<=n-1; i++)
    {
        k=i;
        
        for(j=n-1; j>=i; j--)
        {
            arr[k][j] = ++count;
            
            k++;
        }
    }
    */
    
    for(int row = 0; row<n; row++)
        for(int column = 0; column<n; column++)
            cout<<arr[row][column]<<" ";
}

int main(int argc, const char * argv[]) {
    
    int t;
    int n;

    int arr[100][100];
    
    cin>>t;
    
    while(t--)
    {
        cin>>n;

        printPattern(arr, n);
        cout<<endl;
    }
    return 0;
}
