# 33 Search in Rotated Sorted Array

## description

You are given an *n* x *n* 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).（瞬时间就地旋转90度）

**Note:**

You have to rotate the image [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm), which means you have to modify the input 2D matrix directly. **DO NOT** allocate another 2D matrix and do the rotation.

**Example 1:**

```
Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
```

**Example 2:**

```
Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
```

### C++

```c++
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rowNums = matrix.size(), colNums = matrix[0].size();
        for(int i = 0; i < rowNums; ++i){
            for(int j = 0; j < i; ++j){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i = 0, j = rowNums - 1; i < j; i++, j--){
            for(int k = 0; k < rowNums; ++k){
                swap(matrix[k][i], matrix[k][j]);
            }
        }
    }
};
```

### Java
```java

```

