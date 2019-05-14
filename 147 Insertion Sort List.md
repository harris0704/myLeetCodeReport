# 147. Insertion Sort List

Sort a linked list using insertion sort.  使用插入排序对链表排序

A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list

**Algorithm of Insertion Sort:**

1. Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
2. At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
3. It repeats until no input elements remain.


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
    ListNode* insertionSortList(ListNode* head) {
        // 链表的插入排序
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        ListNode *cur = head, *pre = dummy;
        while(cur){
            // cur->next->val 即将插入元素
            if((cur -> next) && (cur -> next -> val < cur -> val)){
                while( (pre -> next) && (pre -> next -> val < cur -> next -> val)){
                    pre = pre -> next;
                }
                
                ListNode* tmp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = tmp;
                pre = dummy;
                
            }else{
                cur = cur -> next;
            }
        }
        return dummy -> next;
        
    }
};
```

