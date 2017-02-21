#include <iostream>
#define MAX 10000
using namespace std;

int main()
{
	int t;
	int n;
	
	int j=0;
	int element;
	cin>>t;

	int a[MAX];
	int b[MAX];

	while(j!=t) // will run from 0 to t-1
	{
		cin>>n;
		
		for(int i=0; i<n; i++)
		{
			cin>>element;

			b[i] = element>>16;
			//int bx = b[i]<<16;
			a[i] = element-(b[i]<<16);
		}

		cout<<"Case "<< j+1<<":"<<endl;
		for(int i=0; i<n; i++)
			cout<<a[i]<<" ";

		cout<<endl;

		for(int i=0; i<n; i++)
			cout<<b[i]<<" ";

		cout<<endl;
		
		j++;

	}

	return 0;
}