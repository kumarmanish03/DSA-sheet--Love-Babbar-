/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1#
* @TC: O(N)
* @desc: see comments
*
*/

int cnt(TreeNode<int>* root){
    if(!root)
        return 0;
    
    return 1 + cnt(root->left) + cnt(root->right);
}

// This func finds kth element in BST (acc to inorder traversal)
void dfs(TreeNode<int>* root, int &k, int &node){
    if(!root)
        return;
    
    dfs(root->left, k, node);
    k--;
    if(k == 0){
        node = root->data;
    }
    dfs(root->right, k, node);
}

int medianBST(TreeNode<int>* root) 
{
    int total = cnt(root);
    int pos;
    int node = 0;
    // for odd, median is n/2+1;
    if(total & 1){
        pos = total/2+1;
        dfs(root, pos, node);
        return node;
    }
    // for even median is (n/2, n/2+1)
    else {
        pos = total/2;
        dfs(root, pos, node);
        int temp = node;
        pos = total/2+1;
        dfs(root, pos, node);
        return (temp + node) / 2;
    }
}
