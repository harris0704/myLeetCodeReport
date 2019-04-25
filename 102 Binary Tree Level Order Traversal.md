# 102. Binary Tree Level Order Traversal
Given a binary tree, return the *level order* traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree `[3,9,20,null,null,15,7]`,

```
    3
   / \
  9  20
    /  \
   15   7
```



return its level order traversal as:

```
[
  [3],
  [9,20],
  [15,7]
]
```

### 解法
```C++
// 方法一
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 非递归法
        vector<vector<int>> result;
        if(root == NULL) return result;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> v;
            for(int i = q.size(); i > 0; --i){
                TreeNode *t = q.front(); q.pop();
                v.push_back(t->val);
                if(t -> left != NULL) q.push(t -> left);
                if(t -> right != NULL) q.push(t -> right);
            }
            result.push_back(v);
        } 
        return result;
    }
};

// 方法二，递归法有点难理解
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        levelorder(root, 0, res);
        return res;
    }
    void levelorder(TreeNode* node, int level, vector<vector<int>>& res) {
        if (!node) return;
        if (res.size() == level) res.push_back({});
        res[level].push_back(node->val);
        if (node->left) levelorder(node->left, level + 1, res);
        if (node->right) levelorder(node->right, level + 1, res);
    }
};
```

