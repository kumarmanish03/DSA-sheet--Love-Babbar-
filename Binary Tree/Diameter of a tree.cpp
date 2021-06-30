// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n)
// Space Complexity : O(n)

https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1#

int ans = 0;

int find(struct Node* root){
    if(root == NULL)
        return 0;
    
    int left = find(root->left);
    int right = find(root->right);
    
    int temp = max(left,right)+1;
    int mx = max(left+right+1, temp);
    ans = max(ans, mx);
    return temp;
}

int diameter(struct Node* root) {
    ans = 0;
    find(root);
    return ans;
}