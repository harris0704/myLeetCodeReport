# 4. Median of Two Sorted Arrays

There are two sorted arrays **nums1** and **nums2** of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume **nums1** and **nums2** cannot be both empty.

**Example 1:**

```
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
```

**Example 2:**

```
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
```
### 解题思路

一个有序数组的归并问题，其实不是很难。

```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
        vector<int> nums;
        int i = 0, j = 0;
        while(i < nums1.size() || j < nums2.size()){
            if(i==nums1.size())
                nums.push_back(nums2[j++]);
            else if(j == nums2.size())
                nums.push_back(nums1[i++]);
            else
                nums1[i] < nums2[j] ? nums.push_back(nums1[i++]) : nums.push_back(nums2[j++]);
        }
        // Return middle element if odd number of elements, return average if even
        int len = nums.size();
        return len % 2 == 1 ? nums[len/2] : (double)(nums[len/2] + nums[-1 + len/2])/2;
        */
        
        vector<int> merged;
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(merged));
        auto middle = merged.size()/2;
        
        if(merged.size()%2==0){
            
            auto a = merged[middle-1];
            auto b = merged[middle];
            
            return (a+b)/2.;
        }
        else{
            return merged[middle];
        }
    }
};
```

