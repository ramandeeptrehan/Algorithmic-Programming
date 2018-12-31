/*
 Output:
 Enter last row character
 M
 A
 B B
 C C C
 D D D D
 E E E E E
 F F F F F F
 G G G G G G G
 H H H H H H H H
 I I I I I I I I I
 J J J J J J J J J J
 K K K K K K K K K K K
 L L L L L L L L L L L L
 M M M M M M M M M M M M M
 
 Lessons learnt: Basic knowledge of handling characters
 
 ASCII values:
  0 : 48
 'A': 65
 'a': 97
 
 */
 
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    char n;
    int i, j;
    char alphabet = 'A';
    
    cout<<"Enter last row character\n";
    cin>>n; //enter input with quotes 'E'. If you type E, ASCII value is 53 (ASCII value of integer 5)
            //If you enter 'E', ASCII value is 69 (ASVII value of alphabet E is 69, ASCII value of alphabet A being 65)
    
    //cout<<(int)n;
    
    for(i=1; i<=(n-'A'+1); i++) // n-'A'+1 computes difference between letters, which decides total rows
                                // 'E'-'A' is 69 - 65 = 4 (but E is fifth letter, hence adding 1)
    {
        for(j=1; j<=i; j++)
            cout<<alphabet<<" ";
        
        alphabet++;
        
        cout<<endl;
    }
    
    return 0;
}
