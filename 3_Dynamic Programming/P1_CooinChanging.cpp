#include<bits/stdc++.h>
using namespace std;

int main() {
    int coins[] = {1, 4, 6};
    int amount = 9;

    vector<int> dp(amount+1, amount+1);
    dp[0] = 0;

    for(int i=0; i <= amount; i++){
        for(auto coin: coins){
            if(coin <= i){
                dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }
    }

    return dp[amount] > amount ? -1 : dp[amount];
    return 0;
}