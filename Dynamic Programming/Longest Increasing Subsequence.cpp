// Manish Kumar, IIIT Allahabad
// Hard
// Time Complexity : O(nlogn)
// Space Complexity : O(n)

// nlogn soln tricky

https://www.youtube.com/watch?v=1qD1FLhKrIE
https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1#

int longestSubsequence(int n, int a[])
    {
      // https://www.youtube.com/watch?v=1qD1FLhKrIE
      
      // Stores length of longest increasing subsequence of length n
      int dp[n+1]; 
      // checking

      dp[0] = INT_MIN;
      for(int i = 1; i < n+1; i++)
        dp[i] = INT_MAX;
        
      for(int i = 0; i < n; i++){
        int idx = upper_bound(dp, dp+n+1, a[i]) - dp;
        if(dp[idx-1] < a[i] && dp[idx] > a[i])
          dp[idx] = a[i];
      }
       
      for(int i = n; i>=0; i--){
        if(dp[i] != INT_MAX)
          return i;
      } 
    }