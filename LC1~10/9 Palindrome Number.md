# 9.Palindrome  Number

Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

**Example 1:**

```
Input: 121
Output: true
```

**Example 2:**

```
Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
```

**Example 3:**

```
Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
```

### 解法

```C++
class Solution {
public:
    bool isPalindrome(int x) {
        // 判断一个数是否为回数，简单方法：将数字转化为字符串，逆置之后和原来的数比较，同则为回数。
        if(x < 0) return false;
        string s = to_string(x);
        string sr = s;
        reverse(sr.begin(), sr.end());
        return sr == s ? true : false;
    }
};
```

