# Two Sum
Given an array of integers, return **indices** of the two numbers such that they add up to a specific target.

You may assume that each input would have **exactly** one solution, and you may not use the *same* element twice.

**Example:**

```
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
```
### 解题思路



```C++
class Solution {
private:
    unordered_map<int, int> hashmap;
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++){
            int complement = target - nums[i];
            if(hashmap.count(complement)>0){
                result.push_back(hashmap.at(complement));
                result.push_back(i);
                return result;
            }
            hashmap.insert(make_pair(nums[i], i));
        }
        return result;
    }
};
```