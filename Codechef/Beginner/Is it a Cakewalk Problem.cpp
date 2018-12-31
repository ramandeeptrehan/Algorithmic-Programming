/*
  Problem: https://www.codechef.com/problems/ISITCAKE
 
  Very basic problem.
  Usage of 2D array.
 
 */
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int i, j, t;
    int count;
    int time[10][10];
    
    cin>>t;
    
    while(t--)
    {
        count=0;
        
        for(i=0; i<10; i++)
            for(j=0; j<10; j++)
            {
                cin>>time[i][j];
                
                if(time[i][j]<=30)
                    count++;
            }
        
        if(count>=60)
            cout<<"yes";
        else
            cout<<"no";
        
        cout<<endl;
    }
    return 0;
}
