#include <bits/stdc++.h>
using namespace std;

void sortArrays(vector<int> &start, vector<int> &finish)
{
    int n = start.size();
    
    // Check if finish array is already sorted
    bool alreadySorted = true;
    for (int i = 1; i < n; i++) {
        if (finish[i-1] > finish[i]) {
            alreadySorted = false;
            break;
        }
    }

    if (!alreadySorted) {
        // Only sort if not already sorted
        vector<pair<int, int>> activities;
        for (int i = 0; i < n; i++) {
            activities.push_back({finish[i], start[i]});
        }

        sort(activities.begin(), activities.end());

        for (int i = 0; i < n; i++) {
            finish[i] = activities[i].first;
            start[i] = activities[i].second;
        }
    }
}



int activitySelection(vector<int> &start, vector<int> &finish)
{
    // code here
    int count = 1;
    int recentFinish = finish[0];
    for (int i = 1; i < finish.size(); i++)
    {
        if (start[i] > recentFinish)
        {
            recentFinish = finish[i];
            count++;
        }
    }

    return count;
}

int main()
{

    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};

    cout << "start: ";
    for(int ele: start) cout << ele << " ";
    cout << endl;

    cout << "end: ";
    for(int ele: finish) cout << ele << " ";
    cout << endl;

    sortArrays(start, finish);

    cout << "start: ";
    for(int ele: start) cout << ele << " ";
    cout << endl;

    cout << "end: ";
    for(int ele: finish) cout << ele << " ";

    cout << "\nCount: " << activitySelection(start, finish) << endl;

    return 0;
}