# 47 Permutations2

Given a collection of numbers that might contain duplicates, return all possible unique permutations.

**Example:**

```
Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
```

```C++
class Solution{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums){
        vector<vector<int>> res;
        vector<int> v;
        vector<int> visited(nums.size(), 0);
        if(nums.size() == 0){
            res.push_back(v);
            return res;
        }
        if(nums.size() == 1){
            res.push_back(nums);
            return res;
        }
        //
        std::sort(nums.begin(), nums.end());
        dfs(nums, 0, visited, v, res);
        return res;
    }
    void dfs(vector<int> &nums, int level, vector<int> &visited, vector<int> &v, vector<vector<int>> &res){
        if(level == nums.size()){
            res.push_back(v);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(visited[i] == 1 )continue;
            // 与46的区别: 当前数和前一个数不一样，且前一个数未使用
            if(i > 0 && nums[i] == nums[i-1] && visited[i - 1] == 0)continue;
            visited[i] = 1;
            v.push_back(nums[i]);
            dfs(nums, level + 1, visited, v, res);
            visited[i] = 0;
            v.pop_back();
        } 
    }
};
```

