#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class friendClass
{
public:
	int friendID;
	int postPopularity;
	string postContent;
};

class by_popularity
{
public:
	bool operator()(friendClass &a, friendClass &b)
	{
		return a.postPopularity>b.postPopularity;
	}
};

int main()
{
	int numberOfSpecialFriends, numberOfPosts;
	cin>>numberOfSpecialFriends>>numberOfPosts;

	vector<friendClass> people;
	vector<friendClass> specialPeople;
	vector<int> specialID;

	int id, popularity;
	string post;

	for(int i=0; i<numberOfSpecialFriends; i++)
	{
		cin>>id;
		specialID.push_back(id);
	}

	for(int i=0; i<numberOfPosts; i++)
	{
		friendClass tempFriend;
		cin>>id>>popularity>>post;

		tempFriend.friendID=id;
		tempFriend.postPopularity=popularity;
		tempFriend.postContent=post;

		//The way find() method works is:
		/*
		http://www.cplusplus.com/reference/algorithm/find/
		An iterator to the first element in the range that compares equal to val.
		If no elements match, the function returns last.
		*/

		if(find(specialID.begin(), specialID.end(), id)!=specialID.end())
			specialPeople.push_back(tempFriend);
		else
			people.push_back(tempFriend);
	}


	//Helpful link:
	// http://www.geeksforgeeks.org/sort-c-stl/
	// by_popularity() refers to *this
	// operator() will be called as a comparator function
	sort(specialPeople.begin(), specialPeople.end(), by_popularity());
	sort(people.begin(), people.end(), by_popularity());


	for(int i=0; i<specialPeople.size(); i++)
		cout<<specialPeople[i].postContent<<endl;

	for(int i=0; i<people.size(); i++)
		cout<<people[i].postContent<<endl;


}