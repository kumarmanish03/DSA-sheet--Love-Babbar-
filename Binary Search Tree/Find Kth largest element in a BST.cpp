/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://practice.geeksforgeeks.org/problems/kth-largest-element-in-bst/1#
* @TC: O(H + K)
* @desc: finding kth element when traversing reverse Inorder
*
*/

void dfs(Node* root, int &k, int &node){
        if(!root)
            return;

        if(k < 0)
            return;
        
        dfs(root->right, k, node);
        k--;
        if(k == 0){
            node = root->data;
        }
        dfs(root->left, k, node);
    }
    
    int kthLargest(Node *root, int K)
    {
        int k = K;
        int node;
        dfs(root, k, node);
        return node;
    }