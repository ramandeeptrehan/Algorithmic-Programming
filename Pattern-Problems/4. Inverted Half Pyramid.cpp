/*
 Output:
 Enter number of rows needed
 10
 * * * * * * * * * *
 * * * * * * * * *
 * * * * * * * *
 * * * * * * *
 * * * * * *
 * * * * *
 * * * *
 * * *
 * *
 *
 
 */

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int n;
    int i, j;
    
    cout<<"Enter number of rows needed\n";
    cin>>n;
    
    for(i=1; i<=n; i++)
    {
        for(j=n-i+1; j>0; j--) //compute j=n-i+1 by checking corner cases (for i=1 and i=n)
            cout<<"*"<<" ";
        
        cout<<endl;
    }
    
    return 0;
}
