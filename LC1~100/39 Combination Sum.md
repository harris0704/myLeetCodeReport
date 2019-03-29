# 33 Search in Rotated Sorted Array

## description
Given a **set** of candidate numbers (`candidates`) **(without duplicates)** and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sums to `target`.

The **same** repeated number may be chosen from `candidates` unlimited number of times.

**Note:**

- All numbers (including `target`) will be positive integers.
- The solution set must not contain duplicate combinations.

### C++

```c++
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        // 先排序
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> save;
        // dfs
        dfs(candidates, candidates.size(), 0, 0, target, save, res);
        return res;
    }
    
    void dfs(vector<int> &candidates, int size, int start, int now, int target, vector<int> &save,  vector<vector<int>> &res){
        if(target == now){
            res.push_back(save);
            return;
        }
        for(int i = start; i < size; ++i){
            // 大于target 回溯，直接返回
            if(now + candidates[i] > target)
                return;
            
            save.push_back(candidates[i]);
            dfs(candidates, size, i, now+candidates[i], target, save, res);
            save.pop_back();
        }
    }
};
```

### Java
```java

```

