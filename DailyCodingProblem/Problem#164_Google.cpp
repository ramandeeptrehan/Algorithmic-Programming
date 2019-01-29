/*
 Daily Coding Problem #164
 Google.
 
 You are given an array of length n + 1 whose elements belong to the set {1, 2, ..., n}. By the pigeonhole principle, there must be a duplicate.
 Find it in linear time and space.
 
 Algorithm:
 Iterate over the array and look in location i of the array: if arr[i] holds i, then keep going.
 If arr[i] holds j, then swap arr[i] and arr[j] and repeat until it's the correct value.
 Duplicate: If we encounter the same value at arr[j] then we have found our duplicate.
 
 */

#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int c = *b;
    
    *b = *a;
    *a = c;
}

void duplicate(int *arr, int n)
{
    int i;
    
    for(i=1;i<=n+1; i++)
    {
        while(arr[i]!=i)
        {
            if(arr[i] == arr[arr[i]]) //duplicate
            {
                cout<<"Duplicate element is "<<arr[i]<<endl;
                return;
            }
            swap(&arr[i], &arr[arr[i]]);
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int n, i;
    
    cout<<"Enter value of n: ";
    cin>>n;
    
    int arr[n+2]; //using n+1 elements from 1 to n+1
    
    cout<<"Enter "<< n+1 <<" elements from set 1 to " << n <<endl;
    for(i=1; i<=n+1; i++)
        cin>>arr[i];
    
    duplicate(arr, n);
    
    return 0;
}

