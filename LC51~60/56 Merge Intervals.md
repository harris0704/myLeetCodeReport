# 56 Merge Intervals

Given a collection of intervals, merge all overlapping intervals.

**Example 1:**

```
Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
```

**Example 2:**

```
Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

### 题目大意

给定多个区间，合并重叠的区间。

重点在于重写sort中的比较函数。

```C++
class Solution {
    // 13ms的c++解法 
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.empty() || intervals.size() <= 1)
            return intervals;
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end(), [](vector<int> v1, vector<int> v2) {
            return v1.front() < v2.front();
        });
        result.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); ++i){
            int start = intervals[i][0], end = intervals[i][1];
            
            if(result.back()[1] < start) {
                result.push_back(intervals[i]);
                continue;
            }
            
            if(result.back()[1] >= start){
                result.back()[1] = max(end, result.back()[1]);
            }
        }
        return result;
    }
};
```

