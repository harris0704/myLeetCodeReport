# 5 Reverse Integer

## description
Implement **next permutation**, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be **in-place** and use only constant extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

```
1,2,3` → `1,3,2`
`3,2,1` → `1,2,3`
`1,1,5` → `1,5,1
```

```c++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 2){
            reverse(nums.begin(), nums.end());
            return;
        }
        auto res = nums.end();
        for(auto it = nums.end() - 1; it != nums.begin(); it--){
            if(*(it - 1) < *it){
                res = it - 1;
                break;
            }
        }
        if(res == nums.end()){
            reverse(nums.begin(), nums.end());
            return;
        }
        auto res2 = res + 1;
        for(auto it = res2; it != nums.end(); ++it)
            if(*it > *res && *it <= *res2)res2 = it;
        iter_swap(res, res2);
        reverse(res + 1, nums.end());  

    }
};
```

### Java
```java

```

