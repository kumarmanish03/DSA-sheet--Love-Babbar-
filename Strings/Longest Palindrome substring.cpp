// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n^2)
// Space Complexity : O(1)

// See soln once

https://leetcode.com/problems/longest-palindromic-substring/solution/

class Solution {
public:
    string longestPalindrome(string s) {
        string maxLen = "";
        int n = s.size();
        
        // For odd palindrome
        for(int k = 0; k < n; k++){
            int i = k;
            int j = k;
            if(maxLen.size() < j-i+1){
                maxLen = s.substr(i, j-i+1);
            }
            i--;
            j++;
            while(i >= 0 && j < n){
                if(s[i] == s[j]){
                    if(maxLen.size() < j-i+1){
                        maxLen = s.substr(i, j-i+1);
                    }
                    i--;
                    j++;
                }
                else{
                    break;
                }
            }
        }
        
        // For even palindrome
        for(int k = 0; k < n-1; k++){
            int i = k;
            int j = k+1;
            //string len = "";
            while(i >= 0 && j < n){
                if(s[i] == s[j]){
                    if(maxLen.size() < j-i+1){
                        maxLen = s.substr(i, j-i+1);
                    }
                    i--;
                    j++;
                }
                else{
                    break;
                }
            }
        }
        
        return maxLen;
    }
};