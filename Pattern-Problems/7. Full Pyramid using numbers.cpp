/*
 Output:
 
 Enter the value of n: 6
      1
     232
    34543
   4567654
  567898765
 67891011109876
 
 */

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int i, j;
    int counter;
    int space;
    int n;
    
    cout<<"Enter the value of n: ";
    cin>>n;
    
    for(i=1; i<=n; i++) //iteration for each row
    {
        for(space=1; space<=n-i; space++) //space for each row
            cout<<" ";
        
        /*
         Print numbers for each row
         Algorithm:
         For each row, print i numbers starting from i. Then, reverse counter till i
         */
        
        counter = i;
        for(j=1; j<=i; j++) //iterate i times to print left side of triangle
            cout<<counter++;
        
        counter--; //example: second row made 3++ = 4. Need to reduce by 2.
        counter--;
        
        for(j=1; j<i; j++) //right side of triangle (print i-1 numbers)
            cout<<counter--;
        
        cout<<endl;
    }
    return 0;
}
