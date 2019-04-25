# 94. Binary Tree Inorder Traversal

Given a binary tree, return the *inorder* traversal of its nodes' values.
二叉树的中序遍历
**Example:**

```
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
```

**Follow up:** Recursive solution is trivial, could you do it iteratively?

```C++
// 递归解很简单
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        helper(root, result);
        return result;
    }
    
    void helper(TreeNode* root, vector<int> &result){
        if(root == NULL)return;
        if(root->left) helper(root->left, result);
        result.push_back(root->val);
        if(root->right) helper(root -> right, result);
    }
};
```

```C++
// 接下来介绍非递归解

```

