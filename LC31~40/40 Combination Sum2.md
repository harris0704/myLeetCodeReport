# 33 Search in Rotated Sorted Array

## description
- Given a collection of candidate numbers (`candidates`) and a target number (`target`), find all unique combinations in `candidates` where the candidate numbers sums to `target`.

  Each number in `candidates` may only be used **once**in the combination.

  **Note:**

  - All numbers (including `target`) will be positive integers.
  - The solution set must not contain duplicate combinations.

  **Example 1:**

  ```
  Input: candidates = [10,1,2,7,6,1,5], target = 8,
  A solution set is:
  [
    [1, 7],
    [1, 2, 5],
    [2, 6],
    [1, 1, 6]
  ]
  ```

  **Example 2:**

  ```
  Input: candidates = [2,5,2,1,2], target = 5,
  A solution set is:
  [
    [1,2,2],
    [5]
  ]
  ```

### C++

```c++
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 和39的区别每个数只用一次
        std::sort(candidates.begin(), candidates.end());
        std::vector<vector<int>> res;
        std::vector<int> v;
        // dfs find the target
        dfs(candidates, 0, target, candidates.size(), v, res);
        return res;
        
    }
    void dfs(vector<int>& candidates, int start, int target, int size, vector<int> &v, vector<vector<int>> &res){
        if(target == 0){
            res.push_back(v);
            return ;
        }
        
        int i = start;
        while(i < size && target - candidates[i] >= 0){
            if(i == start || candidates[i] != candidates[i-1]){
                v.push_back(candidates[i]);
                dfs(candidates, i + 1, target - candidates[i], size, v, res);
                v.pop_back();
            }
            i++;
        }
    }
};
```

### Java
```java

```

