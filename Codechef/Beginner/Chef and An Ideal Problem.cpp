/*
 Problem: https://www.codechef.com/problems/CHFIDEAL

 ALGORITHM:
 Monty Hall problem explained: https://www.youtube.com/watch?v=mhlc7peGlGg
 Detailed wiki of Monty Hall problem: https://en.wikipedia.org/wiki/Monty_Hall_problem
 
 Solution:
 Always swap. Choose the other door when offered by host since it doubles the changes of winning car
 If we swap, 66.66% chances are I will win car. 33.33% chances are I will win goat
 
 Lessons learnt:

 Which number should be chosen as first door number?
 
 Problem statement has it mentioned:
 If there are multiple optimal possible ways to pick doors for Chef, you may choose any one.
 
 Here, I am taking door 1 as first door, always.
 */

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int y;
    
    cout<<"1"<<endl;
    
    cin>>y;
    
    cout<<(y==2 ? 3:2)<<endl;
    
    return 0;
}
