## 题目描述

给定一棵二叉搜索树，请找出其中的第k小的结点。例如， （5，3，7，2，4，6，8）    中，按结点数值大小顺序第三小结点的值为4。

相关问题：二叉搜索树的第k大节点。
考察要点：二叉树的中序遍历。

```Java
// 这里给出一种不使用递归的解法

import java.util.Stack;

public class Solution {
    TreeNode KthNode(TreeNode pRoot, int k)
    {
        // 中序遍历 
        if(pRoot == null || k == 0)return null;
        TreeNode p = pRoot;
        Stack<TreeNode> stack = new Stack<>();
        int cnt = 0;
        // stack.push(pRoot);
        while(p != null || !stack.isEmpty()){
            while(p != null){
                stack.push(p);
                p = p.left;
            }
            p = stack.pop();
            cnt++;
            if(cnt == k) return p;
            //if(node.right != null) 
            p = p.right;
        }
        return null;
    }
}
```
