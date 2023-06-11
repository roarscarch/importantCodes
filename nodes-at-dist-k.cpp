/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // bina visited array ke bfs pura nahi ho sakta
        // and bina queue ke.
    // first step sabka parent and target find karna hai
    // first traversal mein u dont need visited array
    vector<int> ans;
    if(!root)
    return ans;
    queue<TreeNode*> q;
    q.push(root);
    unordered_map<TreeNode*,TreeNode*>parent;
    parent[root]=NULL;
    while(!q.empty())
    {// normal traversal without 2 while loops
        TreeNode* front=q.front();
        q.pop();
        if(front->left)
        {
        q.push(front->left);
        parent[front->left]=front;
        }
        if(front->right)
        {
            q.push(front->right);
            parent[front->right]=front;
        }
    }
    unordered_map<TreeNode*,bool> vis;// one of the two most important things
    q.push(target);
    vis[target]=true;
    int count=0;
    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            TreeNode* front=q.front();
            q.pop();
            if(k==0)
            {// hum ye check bhul gaye the. important hai
                ans.push_back(front->val);
                return ans;
            }
            if(front->left && !vis[front->left])
            {
                q.push(front->left);
                vis[front->left]=true;
            }
            if(front->right && !vis[front->right])
            {
                q.push(front->right);
                vis[front->right]=true;
            }
            if(parent[front] && !vis[parent[front]])
            {
                q.push(parent[front]);
                vis[parent[front]]=true;
            }

        }
        count++;
        if(count==k)
        break;
    }
    while(!q.empty())
    {
        TreeNode* front=q.front();
        q.pop();
        ans.push_back(front->val);
    }
    return ans;

    }
};