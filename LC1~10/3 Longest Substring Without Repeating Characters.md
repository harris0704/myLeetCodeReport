# 3 Longest Substring Without Repeating Characters

## description
Given a string, find the length of the **longest substring** without repeating characters.

```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.size();
        int maxsublen=0;
        map<char, int> Hashmap;
        for(int i=0, j=0; j<len;j++){
            if(Hashmap.find(s[j]) != Hashmap.end()){
                if(i<Hashmap[s[j]]+1)
                    i=Hashmap[s[j]] + 1;
            }
            Hashmap[s[j]] = j;
            if(maxsublen<j-i+1)
                maxsublen=j-i+1;
        }
        return maxsublen;
    }
    
// public:
//     bool allUnique(string s, int start, int end){
        
//     }
};
```

