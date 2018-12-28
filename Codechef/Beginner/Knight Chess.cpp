/*
 Problem: https://www.codechef.com/problems/KCHESS
 
 Algorithm:
 Keeping check for all possible moves of knight and comparing each final configuration with current coordinates of opponent's KING
 
 Lessons learnt:
 Stored coordinates of knights in a vector.
 */

#include <iostream>
#include <vector>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int t, n, flag=0;
    int x,y; //position of knight
    int kingX,kingY;

    vector<pair<int, int>> knightPosition;
    
    cin>>t;
    
    while(t--)
    {
        flag = 0;
        cin>>n;
        for(int i=0; i<n; i++)
        {
            cin>>x>>y;
            knightPosition.push_back(make_pair(x, y));
        }
                        
        cin>>kingX>>kingY;
                                     
        for(int i=0; i<n; i++)
        {
            if(((knightPosition[i].first+1 == kingX) && (knightPosition[i].second+2 == kingY)) ||   //upwards
               ((knightPosition[i].first-1 == kingX) && (knightPosition[i].second+2 == kingY)) ||
               ((knightPosition[i].first+2 == kingX) && (knightPosition[i].second+1 == kingY)) ||
               ((knightPosition[i].first-2 == kingX) && (knightPosition[i].second+1 == kingY)) ||
               ((knightPosition[i].first+1 == kingX) && (knightPosition[i].second-2 == kingY)) ||   //downwards
               ((knightPosition[i].first-1 == kingX) && (knightPosition[i].second-2 == kingY)) ||
               ((knightPosition[i].first+2 == kingX) && (knightPosition[i].second-1 == kingY)) ||
               ((knightPosition[i].first-2 == kingX) && (knightPosition[i].second-1 == kingY)))
            {
                flag = 1;
                break;
            }
        }
        if(flag == 1)
          cout<<"YES";
        else cout<<"NO";
        
        cout<<endl;
    }
    return 0;
}
