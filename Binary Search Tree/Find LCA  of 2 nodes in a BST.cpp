/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/1#
* @TC: O(h) :height of the tree
* @desc: we can do it same as binary tree also
*   # Observation: but in BST condn for LCA node is n1 <= LCA <= n2
*
*/

Node* LCA(Node *root, int n1, int n2)
{
   if(root->data > n1 and root->data > n2){
       return LCA(root->left, n1, n2);
   }
   else if(root->data < n1 and root->data < n2){
       return LCA(root->right, n1, n2);
   }
   
   return root;
}