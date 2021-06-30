// Manish Kumar, IIIT Allahabad
// Easy
// Time Complexity : O(n)
// Space Complexity : O(n)

// Easy

https://practice.geeksforgeeks.org/problems/level-order-traversal/1#

vector<int> levelOrder(Node* node)
    {
        vector<int> v;
      queue<Node*> q;
      q.push(node);
      while(!q.empty()){
          int sz = q.size();
          while(sz--){
              Node* temp = q.front();
            v.push_back(temp->data);
              q.pop();
              if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
          }
      }
      return v;
    }