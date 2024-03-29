# 100. Same Tree
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

**Example 1:**

```
Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
```

**Example 2:**

```
Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
```

**Example 3:**

```
Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
```

### 解法

```C++
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return helper(p, q);     
    }
    bool helper(TreeNode* p, TreeNode* q){
        // 两个树根节点同为空
        if(!q && !p)return true;
        if((q && !p) || (!q && p) || (p->val != q->val))
            return false;
        else
            return helper(p->right, q->right) && helper(p->left, q->left);
    }
};
```

