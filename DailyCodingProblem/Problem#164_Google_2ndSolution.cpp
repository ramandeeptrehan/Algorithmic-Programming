/*
 Daily Coding Problem #164
 Google.

 You are given an array of length n + 1 whose elements belong to the set {1, 2, ..., n}. By the pigeonhole principle,
 there must be a duplicate. Find it in linear time and space.

 Algorithm:
 duplicate element = sum of all elements in array - sum of n natural numbers

 */

#include <iostream>

using namespace std;

void duplicate(int *arr, int n)
{
    int sum = 0;
    int duplicateElement=0;

    for(int i=1; i<=n+1; i++)
        sum += arr[i];

    duplicateElement = sum - (n*(n+1)/2);

    cout<<"Duplicate element is " <<duplicateElement;
}

int main()
{
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
