/*
 Algorithm:
 For each row (i):
    Give n-i spaces. Last row has 0 space. Hence, don't use n-i+1
    Print 2i-1 stars for each row
 
 */

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int i, j, space;
    int n;
    
    cout<<"Enter number of rows needed\n";
    cin>>n;
    
    for(i=1; i<=n; i++)
    {
        for(space=1; space<=n-i; space++)
        {
            cout<<" ";
        }
        
        for(j=1; j<=(2*i-1); j++)
            cout<<"*";
        
        cout<<endl;
    }
    return 0;
}
