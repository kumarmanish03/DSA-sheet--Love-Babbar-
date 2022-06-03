/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1#
* @TC: O(H + K)
* @desc: finding kth element when traversing Inorder
*
*/

    void dfs(Node* root, int &k, int &node){
        if(!root)
            return;

        if(k < 0)
            return;
        
        dfs(root->left, k, node);
        k--;
        if(k == 0){
            node = root->data;
        }
        dfs(root->right, k, node);
    }

    int KthSmallestElement(Node *root, int K) {
        int k = K;
        int node;
        dfs(root, k, node);
        if(k > 0) return -1;
        return node;
    }
