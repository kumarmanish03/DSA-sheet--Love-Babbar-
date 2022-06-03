/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1
* @TC: O(h) :h is the height of tree
*
*/

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(!root)
        return;
    
    if(root->key == key){
        if(root->left){
            Node* temp = root->left;
            while(temp->right)
                temp = temp->right;
            pre = temp;
        }
        
        if(root->right){
            Node* temp = root->right;
            while(temp->left)
                temp = temp->left;
            suc = temp;
        }
    }
    else if(root->key < key){
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
    else{
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
}