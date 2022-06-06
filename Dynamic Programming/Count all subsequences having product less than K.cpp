/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://www.codingninjas.com/codestudio/problems/count-the-number-of-subsequences-having-product-not-more-than-p_1214647?leftPanelTab=0
* @desc: 0-1 Knapsack
*
*/

int dp[1005][1005];
int func(vector<int>&a, int n, int P, int p = 1) {
    if(n == 0)
        return 1;
    
    if(dp[n][p] != -1)
           return dp[n][p];
    
    if(P >= a[n-1] * p){
        return dp[n][p] = func(a, n-1, P, p*a[n-1]) + func(a, n-1, P, p);
    }
    else{
        return dp[n][p] = func(a, n-1, P, p);
    }
}

int countSubsequences(vector<int>&a, int n, int P, int p = 1) {
    memset(dp, -1, sizeof(dp));
    // subtracting empty subsequence
    return func(a, n, P, 1)-1;
}