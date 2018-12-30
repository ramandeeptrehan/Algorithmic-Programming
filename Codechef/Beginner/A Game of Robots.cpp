/*
 Problem: https://www.codechef.com/problems/ROBOGAME
 
 Algorithm:
 Given a digit, compute lower limit and upper limit for robot movement. Mark these positions as 'x'
 
 While traversing from lower limit to upper limit,
    if we encounter '.' we mark it as x
    if we encounter x or digit //means there is a collision of robots that is possible. Hence, return 'unsafe scenario'
 
 Lessons learnt:
 
 1. Concept of using str[i] - '0'
    It converts a char to an integer by subtracting the ASCII value (48) of 0 from the char
    '0' - '0' = 48 - 48 = 0
    '1' - '0' = 49 - 48 = 1
    '2' - '0' = 50 - 48 = 2
    ...
    ...
 
 2. Did corner checks for lower limit and upper limit computation
 */

#include <iostream>
#include <string>
using namespace std;

int compute(string &str, int len) //pass by reference
{
    int lower_limit, upper_limit;
    int digit;
    int i, j;
    
    for(i=0; i<len; i++)
    {
        if(str[i]!='.' && str[i]!='x')    //x denotes robot's possible moves
                                          //Excluding . and x since we want to process only when we encounter digit
        {
            digit = str[i] - '0';
            
            lower_limit = i - digit; //compute lower limit
            if(lower_limit < 0) //corner check
                lower_limit = 0;
            
            upper_limit = i + digit; //compute upper limit
            if(upper_limit>len-1) //corner check
                upper_limit = len-1;
            
            for(j=lower_limit; j<=upper_limit; j++)
            {
                if(j!=i) //we don't want to replace digit itself. Without this, it always returns 1 (unsafe scenario)
                {
                    if(str[j] == '.')
                        str[j] = 'x';
                    else return 1;
                }
            } //end of inner for loop
        }
    } //end of outer for loop
    
    return 0;
}

int main(int argc, const char * argv[]) {
    
    int t, len;
    string s;
    
    cin>>t;
    
    while(t--)
    {
        len=0; //for each test case, initialize variable named 'len'
        
        cin>>s; //input string
        len=s.length();
        
        if(compute(s, len)!=0)
            cout<<"unsafe"<<endl;
        else
            cout<<"safe"<<endl;
    }
    return 0;
}
