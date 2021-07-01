// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n*m)
// Space Complexity : O(n*m)

https://leetcode.com/problems/edit-distance/

int dp[460][460];

int memorize(string A, string B, int i, int j){
    if(i == 0)
        return j;
    if(j == 0)
        return i;

    if(dp[i][j] != -1)
        return dp[i][j];
    
    if(A[i-1] == B[j-1])
        dp[i][j] = memorize(A, B, i-1, j-1);
    else{
        int insert_e = 1 + memorize(A, B, i, j-1);
        int delete_e = 1 + memorize(A, B, i-1, j);
        int replace_e = 1 + memorize(A, B, i-1, j-1);
        dp[i][j] = min(insert_e, min(delete_e, replace_e));
    }
    
    return dp[i][j];
}

int Solution::minDistance(string A, string B) {
    int n = A.size();
    int m = B.size();
    memset(dp, -1, sizeof(dp));
    return memorize(A, B, n, m);
}
