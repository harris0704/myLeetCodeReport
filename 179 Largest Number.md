# 179. Largest Number

Given a list of non negative integers, arrange them such that they form the largest number.

**Example 1:**

```
Input: [10,2]
Output: "210"
```

**Example 2:**

```
Input: [3,30,34,5,9]
Output: "9534330"
```

**Note:** The result may be very large, so you need to return a string instead of an integer.

### 题目大意

### 解法

```C++
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // 重写sort的compare，目标是能够以ab和ba之间的大小关系排序
        std::sort(nums.begin(), nums.end(), [](int a, int b){
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        });
        string result = "";
        for(auto num: nums)
            result += to_string(num);
        return result[0] == '0' ? "0" : result;
    }
};
```

