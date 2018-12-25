/*
 Problem: https://www.codechef.com/problems/CAMPON
 
 ALGORITHM:
 Compare deadline day with days that are part of schedule.
    if deadline is before scheduled plan, case of not going to camp (Go Sleep)
 
 If deadline is >= my schedule day,
    compare problems mentioned in scenario by coach with problems solved till that day (totalSolved)
 
 Lessons learnt:
 1. Usage of struct to structurize and store data properly.
 2. Compute totalProblemsSolvedTillNow when input is coming, since it's needed in solution itself. Rather than calulating this
    part in solve() method.
 
*/

#include <iostream>
using namespace std;

struct schedule{
    int day[32]; //schedule has 31 days at max
    int problem[32]; //schedule has 31 days at max
    int totalSolved[32];
};

struct scenario
{
    int deadline[101]; //100 scenarios at max
    int numberOfProblems[101]; //100 scenarios at max
};

void solve(struct schedule mySchedule, struct scenario myScenario, int days, int Q)
{
    int flag;
    for(int i=1; i<=Q; i++) //print result for each iteration
    {
        flag = 0;
        for(int j=1; j<=days; j++)
        {
            if(myScenario.deadline[i] >= mySchedule.day[j]) //only case when we need to validate. Apart from this, Go Sleep
            {
                if(myScenario.numberOfProblems[i] <= mySchedule.totalSolved[j]) //case of success
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
    
    schedule mySchedule;
    scenario myScenario;
    
    cin>>t;
    while(t--)
    {
        totalProblemsSolvedTillDay = 0;
        
        cin>>days;
        for(int i=1; i<=days; i++)
        {
            cin>>d>>p;
            mySchedule.day[i] = d;
            mySchedule.problem[i] = p;
            totalProblemsSolvedTillDay += p;
            mySchedule.totalSolved[i] = totalProblemsSolvedTillDay;
        }
        
        cin>>Q;
        for(int i=1; i<=Q; i++)
        {
            cin>>deadline>>numberOfProblems;
            myScenario.deadline[i] = deadline;
            myScenario.numberOfProblems[i] = numberOfProblems;
        }
        
        solve(mySchedule, myScenario, days, Q);
    }
    
    return 0;
}
