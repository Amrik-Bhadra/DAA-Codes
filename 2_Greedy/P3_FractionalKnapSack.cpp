#include<bits/stdc++.h>
using namespace std;

struct Item {
    int profit, weight;
    float ratio;
};

bool cmp(Item a, Item b){
    return a.ratio > b.ratio;
}

float fractionalKnapsack(vector<int>& profit, vector<int>& weight, int capacity){
    int n = profit.size();
    vector<Item> items(n);

    for(int i=0; i<n; i++){
        items[i].profit = profit[i];
        items[i].weight = weight[i];
        items[i].ratio = (profit[i] * 1.0) / weight[i];
    }

    sort(items.begin(), items.end(), cmp);

    float totalProfit = 0;
    int index = 0;

    while(capacity > 0 && index < n){
        int wt = items[index].weight;
        int p = items[index].profit;

        if(wt <= capacity){
            totalProfit += p;
            capacity -= wt;
        } else {
            totalProfit += (capacity * 1.0 / wt) * p;
            capacity = 0;
        }
        index++;
    }

    return totalProfit;
}

int main() {
    vector<int> profit = {10, 20, 30};
    vector<int> weight = {5, 10, 15};
    int capacity = 100;

    float totalProfit = fractionalKnapsack(profit, weight, capacity);
    cout << "Total profit: " << totalProfit << endl;
    return 0;
}
