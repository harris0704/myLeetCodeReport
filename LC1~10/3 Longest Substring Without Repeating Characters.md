# 3 Longest Substring Without Repeating Characters

## description
Given a string, find the length of the **longest substring** without repeating characters.

**Example 1:**

```
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
```

**Example 2:**

```
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
```

**Example 3:**

```
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
```
### 解题思路
&emsp;&emsp;找到字符串中最长的无重复子串长度，使用hashmap建立字符与其出现位置之间的映射

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() == 0)return 0;
        /*
         * HashMap 建立字符与其出现位置之间的映射
         * */
        unordered_map<int, int> m;
        int result = 0, left = -1;
        for(int i = 0; i < s.size(); ++i){
            if(m.count(s[i]) > 0 && m[s[i]] > left){
                left = m[s[i]];
            }
            m[s[i]] = i;
            result = max(result, i - left);
        };
    }
        return result
};
```

```Java

```

