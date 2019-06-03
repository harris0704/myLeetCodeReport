#  242.Valid Anagram

Given two strings *s* and *t* , write a function to determine if *t* is an anagram of *s*.

**Example 1:**

```
Input: s = "anagram", t = "nagaram"
Output: true
```

**Example 2:**

```
Input: s = "rat", t = "car"
Output: false
```

**Note:**
You may assume the string contains only lowercase alphabets.

### 题目大意

给定两个字符串，判断这两个字符串是否是相同字母的不同词序序列。
采用一个数组记录每一个单词出现的次数。两次遍历数组，时间复杂度o(n)，空间复杂度o(n)。

```C++
class Solution {
public:
    bool isAnagram(string s, string t) {
        // 判断是否为同字母异词序
        if(s.size() != t.size())
            return false;
        int m[26] = {0};
        for(int i = 0; i < s.size(); ++i)
        {
            ++m[s[i] - 'a'];
        }
        for(int i = 0; i < t.size(); ++i){
            if((--m[t[i] - 'a']) <0)
                return false;
        }
        return true;
    }
};
```

