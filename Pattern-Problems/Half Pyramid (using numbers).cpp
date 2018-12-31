/*
 Output:
 
 Enter number of rows needed
 10
 1
 1 2
 1 2 3
 1 2 3 4
 1 2 3 4 5
 1 2 3 4 5 6
 1 2 3 4 5 6 7
 1 2 3 4 5 6 7 8
 1 2 3 4 5 6 7 8 9
 1 2 3 4 5 6 7 8 9 10
 
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
        for(j=1; j<=i; j++)
            cout<<j<<" ";
        
        cout<<endl;
    }
    
    return 0;
}
