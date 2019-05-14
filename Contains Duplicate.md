#  Contains Duplicate （相关题目，一共三题）
### 217. Contains Duplicate1

Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

**Example 1:**

```
Input: [1,2,3,1]
Output: true
```

**Example 2:**

```
Input: [1,2,3,4]
Output: false
```

**Example 3:**

```
Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
```

### 解法

```C++
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size() < 2)
            return false;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 1; ++i){
            if(nums[i] == nums[i+1])
                return true;
        }
        return false;
    }
};
```

### 219 Contains Duplicate2

Given an array of integers and an integer *k*, find out whether there are two distinct indices *i* and *j* in the array such that **nums[i] = nums[j]** and the **absolute** difference between *i* and *j* is at most *k*.

**Example 1:**

```
Input: nums = [1,2,3,1], k = 3
Output: true
```

**Example 2:**

```
Input: nums = [1,0,1,1], k = 1
Output: true
```

**Example 3:**

```
Input: nums = [1,2,3,1,2,3], k = 2
Output: false
```

### 解法

与1的区别在于，相同的字符的下标必须差必须在k以内

```C++
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k==0 || nums.empty() || nums.size() < 2)
            return false;
        // unordered_map 存放最近的相同数字的下标，避免双重循环TLE
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            if(map.count(nums[i]) > 0){
                if(map[nums[i]] != i && abs(map[nums[i]]- i) <= k)
                    return true;
                else
                    map[nums[i]] = i;
            }        
            else
                map.insert(make_pair(nums[i], i));
        }
        return false;
    }
};
```

### 220 Contian Duplicate3

Given an array of integers, find out whether there are two distinct indices *i* and *j* in the array such that the **absolute**difference between **nums[i]** and **nums[j]** is at most *t* and the **absolute** difference between *i* and *j* is at most *k*.

**Example 1:**

```
Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
```

**Example 2:**

```
Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
```

**Example 3:**

```
Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
```

### 解题

与2的区别在于，增加了一个条件：数字之间的绝对值差小于t时，也算是一个重复的例子

```C++
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.size() < 2)
            return false;
        int j = 0;
        map<long long, int> m;
        for(int i = 0; i < nums.size(); ++i){
            if(i -j > k)
                m.erase(nums[j++]);
            auto a = m.lower_bound((long long)nums[i] - t);
            if(a != m.end() && abs(a->first - nums[i]) <= t)
                return true;
            m[nums[i]] = i;
        }
        return false;
    }
};
```

