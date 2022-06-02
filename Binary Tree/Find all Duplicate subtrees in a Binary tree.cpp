/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://practice.geeksforgeeks.org/problems/duplicate-subtrees/1
*
*/

// Solution 1: TC: O(n^2); SC: O(n^2)
// @desc: we store the preorder traversal in form of string and hash it for each subtree, then we can easily find duplicate trees
 
unordered_map<string, int> m;
vector<Node*> ans;
string dfs(Node* root){
    if(!root)
        return "";
    
    string s = "(";
    s += to_string(root->data);
    s += dfs(root->left);
    s += dfs(root->right);
    s += ")";
    
    m[s]++;
    if(m[s] == 2)
        ans.push_back(root);
    
    return s;
}

vector<Node*> printAllDups(Node* root)
{
    m.clear();
    ans.clear();
    dfs(root);
    return ans;
}


// Solution 2: TC: O(n^3); SC: O(n)
vector<Node*> nodes;
void dfs(Node* root){
    if(!root)
        return;
    
    nodes.push_back(root);
    dfs(root->left);
    dfs(root->right);
}

bool isDuplicate(Node* root1, Node* root2){
    if(!root1 || !root2){
        if(!root1 && !root2) return true;
        else return false;
    }
        
    return (root1->data == root2->data) && isDuplicate(root1->left, root2->left) && isDuplicate(root1->right, root2->right);
}

vector<Node*> printAllDups(Node* root)
{
    nodes.clear();
    dfs(root);
    vector<Node*> ans;
    vector<bool> isInclude(nodes.size(), false);
    for(int i = 0; i < nodes.size(); i++){
        if(!isInclude[i])
            for(int j = i+1; j < nodes.size(); j++){
                if(!isInclude[j] && isDuplicate(nodes[i], nodes[j])){
                    if(!isInclude[i]){
                        ans.push_back(nodes[i]);
                        isInclude[i] = true;
                        isInclude[j] = true;
                    } 
                    else{
                        isInclude[j] = true;
                    }
                }
            }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}