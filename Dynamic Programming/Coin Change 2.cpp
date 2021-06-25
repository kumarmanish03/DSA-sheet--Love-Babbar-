// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(mn)
// Space Complexity : O(n) & o(mn)

// O(n) SP is Tricky

https://leetcode.com/problems/coin-change-2/


// Space Complexity : O(n) 
// Optimized

class Solution {
public:    
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(auto c : coins){
            for(int i = c; i <= amount; i++){
                dp[i] += dp[i-c]; 
            }
        }
            
        return dp[amount];
    }
};


// ==================================

// Space Complexity : O(mn)

long long int dp[1001][1001];
  long long int recur(int c[], int m, int n){
    if(n == 0)
        return 1;
    if(m == 0)
        return 0;
        
    if(dp[m][n] != -1)
        return dp[m][n];
        
    if(c[m-1] <= n){
        dp[m][n] = recur(c, m, n-c[m-1]) + recur(c, m-1, n);
    }
    else{
        dp[m][n] = recur(c, m-1, n);
    }
    
    return dp[m][n];
  }
  
    long long int count( int c[], int m, int n ){
       memset(dp, -1, sizeof(dp));
       return recur(c, m, n);
    }