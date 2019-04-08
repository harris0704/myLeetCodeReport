# 206 Reverse Linked List

Reverse a singly linked list.

**Example:**

```
Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
```

**Follow up:**

A linked list can be reversed either iteratively or recursively. Could you implement both?

```C++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
         // 非递归解法
        
        // ListNode *newHead = NULL;
        // while(head){
        //     ListNode *t = head->next;
        //     head->next = newHead;
        //     newHead = head;
        //     head = t;
        // }
        // return newHead;
        // 递归解法
        
        if(!head || !head->next)return head;
        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }
};
```



```C++

```

