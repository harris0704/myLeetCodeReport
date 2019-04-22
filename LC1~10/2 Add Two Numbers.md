# Add Two Numbers

You are given two **non-empty** linked lists representing two non-negative integers. The digits are stored in **reverse order** and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Example:**

```markdown
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
```

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addTwoNode(l1, l2, 0);
    }
    ListNode* addTwoNode(ListNode* l1, ListNode* l2, int carry){
        if(l1 == NULL)l1 = new ListNode(0);
        if(l2 == NULL)l2 = new ListNode(0);
        
        ListNode* l = new ListNode((l1 -> val + l2 -> val + carry) % 10);
        carry = (l1 -> val + l2 -> val + carry ) / 10;
        if(l1 -> next != NULL || l2 -> next != NULL || carry != 0){
            l -> next = addTwoNode(l1->next, l2->next, carry);
        }
        return l;
    }
    
};
```

