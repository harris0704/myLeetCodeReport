# 33 Search in Rotated Sorted Array

## description
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., `[0,1,2,4,5,6,7]` might become `[4,5,6,7,0,1,2]`).

You are given a target value to search. If found in the array return its index, otherwise return `-1`.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of *O*(log *n*).

### C++

```c++
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int middle = (low + high) / 2;
            if(nums[middle] == target){
                return middle;
            }
            
            if(nums[middle] > nums[high]){
                // 左序列递增
                if(target >= nums[low] && target < nums[middle])
                    high = middle - 1;
                else
                    low = middle + 1;
            }
            else if(nums[low] > nums[middle]) {
                // 右序列递增
                if(target <= nums[high] && target > nums[middle])
                    low = middle + 1;
                else
                    high = middle - 1;
            }else{
                // 当前序列有序
                if(target < nums[middle])
                    high = middle - 1;
                else
                    low = middle + 1;
            }
                 
        }
        return -1;
    }
};
```

### Java
```java

```

