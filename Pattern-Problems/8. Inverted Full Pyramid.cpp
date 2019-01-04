/*
Enter number of rows needed: 20
 
 ***************************************
  *************************************
   ***********************************
    *********************************
     *******************************
      *****************************
       ***************************
        *************************
         ***********************
          *********************
           *******************
            *****************
             ***************
              *************
               ***********
                *********
                 *******
                  *****
                   ***
                    *

 Algorithm has been discussed as part of comments

*/

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    
    int i, j, space;
    int n;
    
    cout<<"Enter number of rows needed: ";
    cin>>n;
    
    for(i=1; i<=n; i++) //for each row
    {
        for(space=1; space<=i-1; space++) //give space on each row: i-1 spaces in each row (i is 1 to n)
        {
            cout<<" ";
        }
        
        /*
         Algorithm:
         For each row i:
            Print n-i stars, followed by 1 star in center, followed by n-i stars. In total: 2*(n-i) + 1
         */
         for(j=1; j<=2*(n-i)+1; j++)
             cout<<"*";
        
        cout<<endl;
    }
    return 0;
}
