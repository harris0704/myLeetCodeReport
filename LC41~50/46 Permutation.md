# 46 Permutations

Given a collection of **distinct** integers, return all possible permutations.

**Example:**

```
Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
```

```C++
class Solution{
public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> res;
        vector<int> v;
        vector<int> visited(nums.size(), 0);
        if (nums.size() == 0)return res;
        if (nums.size() == 1){
            res.push_back(nums);
            return res;
        }
        dfs(nums, 0, visited, res, v);
        return res;

    }

    void dfs(vector<int> &nums, int level, vector<int> &visited, vector<vector<int>> &res, vector<int> &v){
        if(level == nums.size()){
            res.push_back(v);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(visited[i] == 1)continue;
            v.push_back(nums[i]);
            visited[i] = 1;
            dfs(nums, level + 1, visited, res, v);
            v.pop_back();
            visited[i] = 0;
        }
    }
};
```

