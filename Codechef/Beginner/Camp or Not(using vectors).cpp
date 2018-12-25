/*
 Problem: https://www.codechef.com/problems/CAMPON
 
 ALGORITHM:
 Compare deadline day with days that are part of schedule.
 if deadline is before scheduled plan, case of not going to camp (Go Sleep)
 
 If deadline is >= my schedule day,
 compare problems mentioned in scenario by coach with problems solved till that day (totalSolved)
 
 Lessons learnt:
 1. Usage of struct to insert a triplet into a vector
 2. Compute totalProblemsSolvedTillNow when input is coming, since it's needed in solution itself. Rather than calulating this
 part in solve() method.
 3. solve() doesn't need size value to iterate over vectors. We use vector.size()
 
 My mistakes:
 1. There was a point when my solution was giving correct answer for given test, but giving wrong answer on Codechef (since portal is having more test cases).
    Tried putting debug logs and printing what is being compared in solve() method. All seemed fine.
 
    What could be the issue?
    There are multiple test cases possible, but I am trying only one.
    If logic is correct, what could go wrong with act of running multiple test cases?
    Our data structure is not fresh for each test case. Older test case DS is being used in next test cases.
 
    Thus, below code was needed for each test case to have fresh DS (vectors).
    clear() function is used to remove all the elements of the vector. Hence, making its size as 0.
 
    mySchedule.clear();
    myScenario.clear();
 
    This is not needed in Camp or Not.cpp where I am using structures to handle data since there, next test case inserts data from first index.
    But in vectors, we are using push_back
*/


#include <iostream>
#include <vector>
using namespace std;

struct schedule{
    int day;
    int problem;
    int totalSolvedTillDay;
};

void solve(vector<schedule> &mySchedule, vector<pair<int, int>> &myScenario)
{
    int flag;
    for(int i=0; i<myScenario.size(); i++) //print result for each iteration
    {
        flag = 0;
        for(int j=0; j<mySchedule.size(); j++)
        {
            if(myScenario[i].first >= mySchedule[j].day) //only case when we need to validate. Apart from this, Go Sleep
            {
                if(myScenario[i].second <= mySchedule[j].totalSolvedTillDay) //case of success
                {
                    flag = 1;
                    break;
                }
            }
            else flag = 0;  //Go Sleep
        }
        
        if(flag == 1)
            cout<<"Go Camp"<<endl;
        else cout<<"Go Sleep"<<endl;
    }
}

int main(int argc, const char * argv[]) {
    
    int t, days, d, p, Q;
    int totalProblemsSolvedTillDay;
    int deadline, numberOfProblems;
    
    vector<schedule> mySchedule;
    vector<pair<int, int>> myScenario;
    
    cin>>t;
    
    while(t--)
    {
        totalProblemsSolvedTillDay = 0;
        
        cin>>days;
        for(int i=1; i<=days; i++)
        {
            cin>>d>>p;
            totalProblemsSolvedTillDay += p;
            mySchedule.push_back({d, p, totalProblemsSolvedTillDay}); //NOTE: Curly braces needed since using structure as
            //part of this code. Example code: https://www.geeksforgeeks.org/store-data-triplet-vector-c/
        }
       
        cin>>Q;
        for(int i=1; i<=Q; i++)
        {
            cin>>deadline>>numberOfProblems;
            myScenario.push_back(make_pair(deadline, numberOfProblems));
        }
       
        solve(mySchedule, myScenario);
        
        mySchedule.clear();
        myScenario.clear();
    }
    
    return 0;
}
