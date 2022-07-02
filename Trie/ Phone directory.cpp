// Manish Kumar, IIIT Allahabad

struct trie{
    trie *next[26];
    vector<int> ind;
    
    trie(){
        for(auto &c:next)
            c = NULL;
        ind.clear();
    }
};

class Solution{
    private:
        trie *root;
        
    public:
    
    void insert(string s, int i){
        trie *temp = root;
        for(char c:s){
            if(!temp->next[c-'a']){
                temp->next[c-'a'] = new trie();
            }
            temp = temp->next[c-'a'];
            (temp->ind).push_back(i);
        }
    }
    
    void dfs(trie *temp, string &s, int i, vector<vector<int>>&res){
        if(i < s.size() && temp->next[s[i]-'a']){
            res.push_back(temp->next[s[i]-'a']->ind);
            dfs(temp->next[s[i]-'a'], s, i+1, res);
            return;
        }
    }
    
    vector<vector<string>> displayContacts(int n, string con[], string s)
    {
        set<string> mp;
        for(int i = 0; i < n; i++){
            mp.insert(con[i]);
        }
        
        vector<string>contact;
        
        for(auto s:mp){
            contact.push_back(s);
        }

        root = new trie();
        for(int i = 0; i < mp.size(); i++){
            insert(contact[i], i);
        }
        
        vector<vector<int>> res;
        dfs(root, s, 0, res);
    
        vector<vector<string>> ans(s.size());
        
        for(int i= 0 ; i < s.size(); i++){
            if(i >= res.size()){
                ans[i] = {"0"};
                continue;
            }
            vector<string>v;
            for(int j:res[i]){
                v.push_back(contact[j]);
            }
            ans[i] = v;
        }
            
        return ans;
    }
};
