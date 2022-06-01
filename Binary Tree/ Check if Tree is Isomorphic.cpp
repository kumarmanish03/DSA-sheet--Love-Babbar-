/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic/1#
* @TC: O(min(n1, n2) ^ 2)  : n1 &  n2 are no. of nodes in both tress respectively
*
*/

bool isIsomorphic(Node *root1,Node *root2)
    {
        if(!root1 || !root2){
            if(!root1 && !root2)
                return true;
            else
                return false;
        }
        
        if(root1->data != root2->data)
            return false;
        
        bool ans = false;
        // First we check for, if nodes were not swapped
        ans = ans || (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right));
        // if nodes were swapped
        ans = ans || (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left));
        return ans;
    }