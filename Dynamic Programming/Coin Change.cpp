// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n)
// Space Complexity : O(n)

https://leetcode.com/problems/coin-change

class Solution {
public:
    int dp[10005]; // dp[n] is equal to minimum no. of coins used to make sum n
    int inf = 100000;
    
    int recur(vector<int>& coins, int amount){
        if(amount == 0)
            return 0;
        if(amount <= 0)
            return inf;
        
        if(dp[amount] != -1)
            return dp[amount];
        
        int noOfCoins = inf;
        for(auto coin : coins){
            noOfCoins = min(1 + recur(coins, amount-coin), noOfCoins);
        }
        
        return dp[amount] = noOfCoins;    
    }
    
    int coinChange(vector<int>& coins, int amount) {
        memset(dp, -1, sizeof(dp));
        return recur(coins, amount) == inf ? -1 : recur(coins, amount);
    }
};