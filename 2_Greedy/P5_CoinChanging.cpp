#include <bits/stdc++.h>
using namespace std;

vector<int> coinChanging(int N)
{
    vector<int> ans;
    vector<int> denominations = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    sort(denominations.begin(), denominations.end(), greater<int>());

    int i = 0;
    while (N > 0)
    {
        int val = denominations[i];
        if (val <= N)
        {
            N -= val;
            ans.push_back(val);
        }
        else
        {
            i++;
        }
    }

    return ans;
}

int main()
{
    cout << "Enter Amount: ";
    int N;
    cin >> N;

    vector<int>ans = coinChanging(N);
    cout << "Following is the breakdown: " << endl;
    for(int ele: ans){
        cout << ele << " ";
    }
    return 0;
}