/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1#
* @TC: O(N)
* @desc: Just traverse reverse inorder and mark current root->next = prev
*
*/

    Node* prev = NULL;
    void populateNext(Node *root)
    {
        if(!root)
            return;
        
        populateNext(root->right);
        
        root->next = prev;
        prev = root;
        
        populateNext(root->left);
    }
