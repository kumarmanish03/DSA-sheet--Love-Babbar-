// Manish Kumar, IIIT Allahabad
// Good question

https://leetcode.com/problems/word-ladder/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int> hash;
        for(auto s:wordList){
            hash[s] = 0;
        }
        
        if(!hash.count(endWord)){
            return 0;
        }
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        if(hash.count(beginWord)){
            hash[beginWord] = 1;
        }
        
        while(!q.empty()){
            auto [word, step] = q.front();
            q.pop();
            
            if(word == endWord){
                return step;
            }
            
            for(int i = 0; i < word.size(); i++){
                for(int k = 0; k < 26; k++){
                    if(word[i] != char(k+'a')){
                        char old = word[i];
                        word[i] = char(k+'a');
                        if(hash.count(word) && hash[word] == 0){
                            hash[word] = 1;
                            q.push({word, step+1});
                        }
                        word[i] = old;
                    }
                }
            }
        }
        
        return 0;
    }
};