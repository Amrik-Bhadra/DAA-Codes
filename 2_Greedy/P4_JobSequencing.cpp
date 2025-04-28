#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int jobId, profit, deadline;
};

bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}

int jobSequencing(vector<Job> jobs, int n, int maxDeadline)
{
    sort(jobs.begin(), jobs.end(), cmp);
    vector<int> slot(maxDeadline + 1, 0);
    int maxProfit = 0;

    for (int i = 0; i < n; i++)
    {
        int idx = jobs[i].deadline - 1;
        while (slot[idx] != 0 && idx >= 0)
        {
            idx--;
        }

        if (idx >= 0)
        {
            slot[idx] = jobs[i].jobId;
            maxProfit += jobs[i].profit;
        }
    }

    cout << "\nOrder of jobs: ";
    for(int jobId: slot){
        if(jobId != 0)
        cout << "J" << jobId << " ";
    }
    return maxProfit;
}

int main()
{
    int n;
    cout << "Enter number of jobs: ";
    cin >> n;
    int maxDeadline = INT_MIN;
    vector<Job> jobs(n);
    cout << "Enter details of " << n << " jobs" << endl;
    for (int i = 0; i < n; i++)
    {
        jobs[i].jobId = i + 1;
        cout << "\nProfit of job1: ";
        cin >> jobs[i].profit;
        cout << "Deadline of job1: ";
        cin >> jobs[i].deadline;

        if (maxDeadline < jobs[i].deadline)
        {
            maxDeadline = jobs[i].deadline;
        }
    }

    cout << "Max Deadline: " << maxDeadline << endl;

    int maxProfit = jobSequencing(jobs, n, maxDeadline);
    cout << "\nMaximum Profit Obtained: " << maxProfit << endl;
    return 0;
}