#include <iostream>

using namespace std;

int main()
{
	long long int t;
	long long int cats, dogs, legs;
	cin>>t;
	while(t--)
	{
		cin>>cats>>dogs>>legs;

		//max legs on ground = 4(dogs+cats)
		//cats-2*dogs: if negative, means all dogs can carry all cats, minLegs=4*dogs
		//else if positive: then minLegs = (value+dogs)*4

		long long int maxLegs = 4*(dogs+cats);
		long long int minLegs;
		long long int difference = cats - 2*dogs;
		
		if(difference<=0)
			minLegs = 4*dogs;
		else
			minLegs = 4*(dogs + difference);
		
		if(legs>=minLegs && legs<=maxLegs && legs%4==0)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
		
	}
}