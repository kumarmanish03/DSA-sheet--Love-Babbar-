// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n*sum)
// Space Complexity : O(n*sum)

https://practice.geeksforgeeks.org/problems/subset-sum-problem2014/1#

int equalPartition(int N, int arr[])
    {
        int sum = 0;
        for(int i = 0; i < N; i++) sum += arr[i];
        if(sum % 2 == 1)
            return false;
        
        bool dp[sum/2+1][N+1];
        for(int i = 0; i < N; i++){
            dp[0][i] = true;
        }
        for(int i = 1; i < sum/2+1; i++){
            dp[i][0] = false;
        }
        
        for(int i = 1; i < sum/2+1; i++){
            for(int j = 1; j < N+1; j++){
                dp[i][j] = dp[i][j-1];
                if(i >= arr[j-1])
                    dp[i][j] = dp[i][j-1] || dp[i-arr[j-1]][j-1];
            }
        }
        
        return dp[sum/2][N];
    }