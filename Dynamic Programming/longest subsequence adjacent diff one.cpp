// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n)
// Space Complexity : O(1)

// Same as longest Increasing subsequence
// dp[i] is the longest subseqence(s.t adjacent diff is 1) ending with i

https://practice.geeksforgeeks.org/problems/longest-subsequence-such-that-difference-between-adjacents-is-one4724/1#

int longestSubsequence(int N, int A[]){
    int dp[N];
    for(int i = 0; i < N; i++){
        dp[i] = 1;
        for(int j = 0; j < i; j++){
            if(abs(A[i] - A[j]) == 1)
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    
    return *max_element(dp, dp + N);
}