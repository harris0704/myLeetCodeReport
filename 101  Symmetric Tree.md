#  101. Symmetric Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree `[1,2,2,3,4,4,3]` is symmetric:

```
    1
   / \
  2   2
 / \ / \
3  4 4  3
```



But the following `[1,2,2,null,3,null,3]` is not:

```
    1
   / \
  2   2
   \   \
   3    3
```



**Note:**
Bonus points if you could solve it both recursively and iteratively.

### 解法

相同题目剑指offer28，判断一棵二叉树是否对称

```C++
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return helper(root->left, root->right);
    }
    bool helper(TreeNode* left, TreeNode* right){
        if(!left && !right)
            return true;
        if((left && !right) || (!left && right)|| (left -> val != right -> val) )
            return false;
        return helper(left->left, right->right) && helper(left->right, right->left);
            
    }
};
```

