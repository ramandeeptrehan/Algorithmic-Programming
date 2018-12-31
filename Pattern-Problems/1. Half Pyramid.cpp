/*
 Output:
 Enter number of rows needed
 10
 *
 **
 ***
 ****
 *****
 ******
 *******
 ********
 *********
 **********
 
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
            cout<<"*";
        
        cout<<endl;
    }
    return 0;
}
