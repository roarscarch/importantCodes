/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        if(!root)
        return 0;
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*,TreeNode*>parent;
        TreeNode* target=NULL;
        parent[root]=NULL;
        while(!q.empty())// bina 2 loop ke humlog bfs kiye
        {
            TreeNode* front=q.front();
            q.pop();
            if(front->val==start)
            target=front;
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
        unordered_map<TreeNode* ,bool> vis;
        q.push(target);
        vis[target]=true;
        int time=-1;// -1 se initialize kiye kyunki last mein jab add karne ko kuch nai hota to ssirf pop hota hai
        // BFS mein 2 cheez necessary VISITED MAP and QUEUE
        //iske bina BFS IS IMPOSSIBLE
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                TreeNode* front=q.front();
                q.pop();
                if(front && !vis[front->left]&& front->left)
                {
                    q.push(front->left);
                    vis[front->left]=true;
                }
                if(front && !vis[front->right]&& front->right)
                {
                    q.push(front->right);
                    vis[front->right]=true;
                }
                if(front && !vis[parent[front]]&& parent[front])
                {
                    q.push(parent[front]);
                    vis[parent[front]]=true;
                }
            }
            time++;
        }
        return time;

    }
};