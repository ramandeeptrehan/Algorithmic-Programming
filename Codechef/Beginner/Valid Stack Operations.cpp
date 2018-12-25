/*
 Problem: https://www.codechef.com/problems/VALIDSTK
 Lessons learnt:
 1. Separate stack isn't needed.
 2. break statement takes the control out of loop.
 3. Think of solution as what should logically happen if current value being considered is 0/1. Think for both cases.
 
 My mistakes:
 1. I kept numberOfOne = 0, flag = 0 before while loop. These values need to be updated to 0 for every test case,
    else the old values get used in new test case and lead to logical error.
*/

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int t, n;
    int arr[100000];
    cin>>t;
    
    while(t--)
    {
        int numberOfOne = 0, flag = 0;
        cin>>n;
        for(int i=0; i<n; i++) //series of operations
            cin>>arr[i];
        
        /*
         Push is not an issue. Pop could lead to an issue
         */
        for(int i=0; i<n; i++)
        {
            if(arr[i]==1)
                numberOfOne++;
            
            if(arr[i]==0) //pop operation
            {
                if(numberOfOne == 0)
                {
                    flag = 1;
                    break;
                }
                else
                    numberOfOne--;
            }
        }
        
        if(flag == 1)
            cout<<"Invalid"<<endl;
        else
            cout<<"Valid"<<endl;
        
    }
    return 0;
}
