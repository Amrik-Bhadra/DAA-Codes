#include<bits/stdc++.h>
using namespace std;

void findSubsetSum(int n, vector<int>& nums, int index, vector<int>& currentSubset, int sum)
{
    if(index == n){
        cout << "Sum of subset { ";
        for(int ele: currentSubset){
            cout << ele << " ";
        }
        cout << " }: " << sum << endl;
        return;
    }

    currentSubset.push_back(nums[index]);
    findSubsetSum(n, nums, index + 1, currentSubset, sum + nums[index]);

    currentSubset.pop_back();
    findSubsetSum(n, nums, index + 1, currentSubset, sum);
}


int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter elements in array: ";
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    vector<int> currentSubset;
    findSubsetSum(n, nums, 0, currentSubset, 0);
    return 0;
}