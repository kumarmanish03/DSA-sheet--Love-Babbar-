// Manish Kumar, IIIT Allahabad
// Medium, Kadane Modified
// Time Complexity : O(n)
// Space Complexity : O(1)

// Kadane Modified Soln
// Make zero as 1 and one as -1, then simply calculate max contigious sum using kadane Algo

https://practice.geeksforgeeks.org/problems/maximum-difference-of-zeros-and-ones-in-binary-string4111/1#

int maxSubstring(string s)
	{
        int maxDiff = INT_MIN;
        
        int curr = 0;
        for(int i = 0; i < s.length(); i++){
            if(curr < 0)
                curr = 0;
            (s[i] == '1') ? curr-- : curr++;
            maxDiff = max(curr, maxDiff);
        }
        
        return maxDiff;
	}