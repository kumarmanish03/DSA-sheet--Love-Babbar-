// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n)
// Space Complexity : O(1)

// Easy

https://leetcode.com/problems/count-and-say/

class Solution {
public:
    
    string countAndSay(int n) {
        n--;
        string s = "1";
        string tmp = "";
        while(n--){
            int cnt = 1;
            char k = s[0];
            for(int i = 1; i < s.size(); i++){
                if(s[i-1] == s[i]){
                    cnt++;
                }else {
                    tmp.push_back(cnt + '0');
                    tmp.push_back(k);
                    cnt = 1;
                    k = s[i];
                }
            }
            tmp.push_back(cnt + '0');
            tmp.push_back(k);
            
            s = tmp;
            tmp = "";
        }
        // string s = "1";
        // find(s, n-1);
        return s;
    }
};