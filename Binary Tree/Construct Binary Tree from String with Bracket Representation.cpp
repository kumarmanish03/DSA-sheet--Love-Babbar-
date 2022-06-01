/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://www.codingninjas.com/codestudio/problems/binary-tree-from-bracket_1118117?leftPanelTab=0
* @TC: O(N ^ 2) : N is no. of nodes
* @desc: First intilize no as root of tree then if next char is '(' then find index of ')' and if found call recursively for left and right subtree
*
*/

BinaryTreeNode<int>* formTree(string &s, int i, int j){
     
    if(i > j){
        return NULL;
    }
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(s[i]-'0');
    
    int ind = -1;
    // if next char is '(' then find index of ')' and if found call recursively for left and right subtree
    if(i+1 <= j && s[i+1] == '('){
        int delta = 0;
        for(int k = i+2; k <= j; k++){
            if(delta == 0 && s[k] == ')'){
                ind = k;
                break;
            }
            if(s[k] == '(') delta++;
            if(s[k] == ')') delta--;
        }
    }
    
    if(ind != -1){
        root->left = formTree(s, i+2, ind-1);
        root->right = formTree(s, ind+2, j-1);
    }
    
    return root;
}

BinaryTreeNode<int>* treeFromBracket(string &str)
{
    return formTree(str, 0, str.size()-1);
}
