#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1); // Initialize dp array with an amount + 1 (which represents an impossible value)
    dp[0] = 0; // Base case: 0 coins are needed to make amount 0

    for (int i = 1; i <= amount; ++i) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1); // Check if using the current coin gives a smaller number of coins
            }
        }
    }

    return dp[amount] > amount ? -1 : dp[amount]; // If dp[amount] is still greater than amount, return -1 (impossible)
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    cout << "Minimum coins needed: " << coinChange(coins, amount) << endl;
    return 0;
}
