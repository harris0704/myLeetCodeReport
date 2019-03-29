# 5 Reverse Integer

## description
Given a 32-bit signed integer, reverse digits of an integer.

### C++

```c++
class Solution {
public:
    int reverse(int x) {
        if(x>=0) return 
            reversePos(x);
        else
            return -reversePos(-x);
    }
    
public:
    int reversePos(int x){
        
        int remaining = x;
        int sum = 0;
        int currentDigit = 0;
        int count = 0;
        
        while(remaining > 0){
            count++;
        
            if(sum > INT_MAX/10){
                // check overflow
                return 0;
            }
            
            currentDigit = remaining % 10;
            remaining /= 10;
            sum = sum * 10 + currentDigit;
        }
        return sum;
    }
};
```

### Java
```java
class Solution {
    public int reverse(int x) {
        if(x >= 0) return reversePos(x);
        else return -reversePos(-x);
    }
    
    public int reversePos(int x){
        int currentDigit;
        int remaining = x;
        int sum = 0;
        int count = 0;
        
        while(remaining > 0){
            count ++;
            
            if(sum > Integer.MAX_VALUE / 10 ){
                // judge overflow
                return 0;
            }
            
            currentDigit = remaining % 10;
            remaining /= 10;
            sum = sum * 10 + currentDigit;
            
        }
        return sum;
    }
}

```

