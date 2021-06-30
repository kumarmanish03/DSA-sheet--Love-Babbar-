// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n^2)
// Space Complexity : O(n^2)

https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1#

// Using DP

int LongestRepeatingSubsequence(string A){
		    int n = A.size();
		    int dp[n+1][n+1];
		    for(int i = 0; i < n+1; i++){
		        dp[i][0] = dp[0][i] = 0;
		    }
		    for(int i = 1; i < n+1; i++){
		        for(int j = 1; j < n+1; j++){
		            if(i!=j && A[i-1] == A[j-1])
		                dp[i][j] = 1 + dp[i-1][j-1];
		            else
		                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		        }
		    }
		    return dp[n][n];
		}