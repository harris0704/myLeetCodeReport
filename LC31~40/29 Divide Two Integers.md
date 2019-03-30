# 5 Reverse Integer

## description
Given two integers `dividend` and `divisor`, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing `dividend` by `divisor`.

The integer division should truncate toward zero.

**Example 1:**

```
Input: dividend = 10, divisor = 3
Output: 3
```

**Example 2:**

```
Input: dividend = 7, divisor = -3
Output: -2
```

**Note:**

- Both dividend and divisor will be 32-bit signed integers.
- The divisor will never be 0.
- Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.


### C++

```c++
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || (dividend == INT32_MIN && divisor == -1))
            return INT32_MAX;
        // 异或求符号
        int sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1;
        // 转化为正数
        long long m = abs((long long)dividend), n = abs((long long)divisor);
        int result = 0;
        if(n == 1)return sign == 1 ? m: -m;
        while(m >= n){
            long long t = n, p = 1;
            // m >= 2n
            while(m >= (t << 1)){
                t <<= 1;
                p <<= 1;
            }
            result += p;
            m -= t;
        }
        return sign == 1 ? result : -result;
    }
};
```

### Java
```java

```

