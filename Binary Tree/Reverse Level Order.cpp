// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n)
// Space Complexity : O(n)

https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1#

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> v;
    queue<Node*> q;
    q.push(root);
    stack<int> s;
    while(!q.empty()){
        int size = q.size();
        while(size--){
            Node* temp = q.front();
            q.pop();
            s.push(temp->data);
            if(temp->right)
                q.push(temp->right);
            if(temp->left)
                q.push(temp->left);
        }
    }
    while(!s.empty()){
        v.push_back(s.top());
        s.pop();
    }
    return v;
}