/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1#
* @TC: O(N)
* @desc: we store the Inorder traversal in form of string and hash it for each subtree, then we can easily find this
*
*/

class Solution {
  public:
    /*This function returns true if the tree contains 
    a duplicate subtree of size 2 or more else returns false*/
    unordered_map<string, int> m;
    string dfs(Node* root){
        if(!root)
            return "";
        
        string s = "(";
        s += dfs(root->left);
        s += root->data;
        s += dfs(root->right);
        s += ")";
        
        m[s]++;
        
        return s;
    }
    
    int dupSub(Node *root) {
        m.clear();
        dfs(root);
        for(auto i:m){
            if(i.first.size() > 3 && i.second > 1){
                return true;
            }
        }
        return false;
    }
};