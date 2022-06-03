/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://practice.geeksforgeeks.org/problems/check-for-bst/1#
* @TC: O(N)
*
*/

// Solution 1: prev stores value of last visited node, Now just do inorder traversal and check with previous
    long long prev = -1e11;
    bool isBST(Node* root) 
    {
        if(!root)
            return true;
        
        if(!isBST(root->left))
            return false;
        
        if(prev >= root->data){
            return false;
        }
        prev = root->data;
        
        if(!isBST(root->right))
            return false;
        
        return true;
    }

// Solution 2: make counter mn, mx, And for each node check conditions and recursively call left subtree and right subtree
bool isBST(Node* root, int mn = INT_MIN, int mx = INT_MAX) 
    {
        if(!root){
            return true;
        }
        
        return (root->data > mn && root->data < mx) && isBST(root->left, mn, root->data) && isBST(root->right, root->data, mx);
    }


// Solution 3
    bool isBST(Node* root) 
    {
        if(!root)
            return true;
        
        if(root->left){
            Node* temp = root->left;
            while(temp->right)
                temp = temp->right;
            if(temp->data >= root->data)
                return false;
        }
        
        if(root->right){
            Node* temp = root->right;
            while(temp->left)
                temp = temp->left;
            if(temp->data <= root->data)
                return false;
        }
        
        return isBST(root->left) && isBST(root->right);
    }

// 
