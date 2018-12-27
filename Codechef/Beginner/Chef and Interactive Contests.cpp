/*
 Problem: https://www.codechef.com/problems/CHFINTRO
 
 Solution: Simple
 */

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    
    int N, r, rating;
    cin>>N>>r;
    
    for(int i=0; i<N;i++)
    {
        cin>>rating;
        
        if(rating>=r)
            cout<<"Good boi";
        else cout<<"Bad boi";
        
        cout<<endl;
    }
    return 0;
}
