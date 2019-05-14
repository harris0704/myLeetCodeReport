# 148 Sort List

Sort a linked list in *O*(*n* log *n*) time using constant space complexity.

**Example 1:**

```
Input: 4->2->1->3
Output: 1->2->3->4
```

**Example 2:**

```
Input: -1->5->3->4->0
Output: -1->0->3->4->5
```

### 解法

题目要求使用常数空间复杂度对链表用O（nlogn）算法排序，链表的性质+时间复杂度能使用的就是归并排序，快速排序和堆排序。

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
    ListNode* sortList(ListNode* head) {
        
        // 不符合题意的解，但是能过
        // if(!head || !head->next)return head;
        // vector<int> v;
        // ListNode* cur = head;
        // while(cur){
        //     v.push_back(cur->val);
        //     cur = cur -> next;
        // }
        // sort(v.begin(), v.end());
        // ListNode*  result = new ListNode(0);
        // ListNode* dummy = result;
        // for(int i = 0; i < v.size(); ++i){
        //     ListNode* tmp = new ListNode(v[i]);
        //     result -> next =  tmp;
        //     result = result -> next;
        // }
        // return  dummy->next;
        
        
        // 常数空间解法-单链表的归并排序
        if(!head || head -> next == NULL)
            return head;
        ListNode *slow = head, *fast = head, *pre = head;
        while(fast){
            // pre 始终指向slow前一个元素
            pre = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        pre -> next = NULL;
        return merge(sortList(head), sortList(slow));
    } 
    
   ListNode* merge(ListNode* l1, ListNode* l2) {
       ListNode *dummy = new ListNode(-1);
       ListNode* cur = dummy;
       while(l1 && l2){
           if(l1->val <= l2->val){
               cur -> next = l1;
               l1 = l1 -> next;
           }else{
               cur -> next = l2;
               l2 = l2 -> next;
           }
           cur = cur -> next;
       }
       if(l1) cur->next = l1;
       if(l2) cur->next = l2;
       return dummy -> next;
   }
};
```

