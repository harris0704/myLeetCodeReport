#include <iostream>
#include <string.h>
#include <algorithm>
#include <unordered_map>
#include "map"
#include <queue>
#include <stack>
#include <deque>

using namespace std;
vector<int> height;
deque<int> dq;

int singleLive(){
    int x, f, d, p;
    int cnt = 0;
    cin >> x >> f >> d >> p;
    // 每日房租大于小易所有钱，直接返回0
    if(x > d){
        cout << 0;
        return 0;
    }
    if(d >= f*x){
        // f个水果全部吃完
        d -= f * x;
        cnt += f;
        while (d > p + x){
            cnt++;
            d -= x;
            d -= p;
        }
    }
    else{
        // f个水果还没吃完就已经付不起房租
        while(d > 0){
            if(f > 0){
                d -= x;
                f--;
                cnt ++;
            }else{
                d -= x;
                d -= p;
                cnt++;
            }
        }
    }
    cout << cnt;
    return cnt;
}

void crazyQueue(){
    int num;
    cin >> num;
    height.resize(num);
    for(int i = 0; i < num; i++){
        cin >> height[i];
    }
    std::sort(height.begin(), height.end());
    int left = 0, right = num - 1;
    int res = 0;
    while(left != right){
        int min1 = left, min2 = left + 1;
        res += height[right] - height[min1] + height[right] - height[min2];
        res += abs(height[min1] - height[--right]) + abs(height[min2] - height[--right]);
        left += 2;

    }
}

void strToInt(string str){
    if(str.size() == 0){
        cout << 0;
        return;
    }
    int len = str.size(), flag = 1, i = 0;
    int result = 0;
    if(str[i] == '-' || str[i] == '+')
        i++;
    if(str[0] == '-')
        flag = -1;
    for(; i < len; ++i){

        if(!isdigit(str[i])) {
            cout << 0;
            break;
        }
        if((result > INT32_MAX / 10 || (result == INT32_MAX/10 && (str[i] - '0') >= INT32_MAX%10)) && flag == 1){
            cout << INT32_MAX;
            return;
        }
        if((result > -(INT32_MIN / 10) || (result == -(INT32_MIN/10 ) && (str[i] - '0' >= -(INT32_MIN % 10)))) && flag == -1){
            cout << INT32_MIN;
            return;
        }
        result = result * 10 + str[i] - '0';
    }
    cout << result * flag <<endl;
}

// 翻转字符串
void Reverse(char *pBegin, char *pEnd){
    // 剑指offer char解法
    if(pBegin == nullptr || pEnd == nullptr)
        return;
    while(pBegin < pEnd){
        char tmp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = tmp;
        pBegin++;
        pEnd++;
    }
}
void Reverse(int start, int end, string& str){
//    if(start == end || start < 0 || end < 0)
//        return;
    while(start < end){
        auto tmp = str[start];
        str[start] = str[end];
        str[end] = tmp;

        start++;
        end--;
    }
}

string ReverseSentence(string str){
    if(str.length() <= 0)return str;
    // int start = 0, end  = str.size() - 1;
    // 得到整个逆置的字符串
    std::reverse(str.begin(), str.end());
    // 接着按照单词挨个逆置
    int begin = 0, end = 0;
    while(str[begin] != '\0'){
        if(str[begin] == ' '){
            begin++;
            end++;
        }else if(str[end] == ' '|| str[end] == '\0'){

            begin = ++end;
        }else
            end++;
    }
    return str;
}



class Solution_1{
public:
    vector<int, int> TwoSum(vector<int> &nums, int target){
        unordered_map<int, int> hashmap;
        vector<int, int> result;
        for(int i = 0; i < nums.size(); i++){
            int rest = target - nums[i];
            if(hashmap.count(rest) > 0){
                result.push_back(hashmap.at(rest));
                result.push_back(i);
            }
            hashmap.insert(make_pair(nums[i], i));
        }
        return result;
    }
};


struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

class Solution_2{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        return addTwoNodes(l1, l2, 0);
    }
    ListNode* addTwoNodes(ListNode* l1,  ListNode* l2, int carry){
        if(l1 == NULL)
            l1 = new ListNode(0);
        if(l2 == NULL)
            l2 = new ListNode(0);
        ListNode* l =new ListNode((l1->val + l2->val + carry) % 10);
        carry = (l1->val + l2->val + carry) / 10;
        if(l1->next != NULL || l2->next != NULL && carry != 0)
            l -> next = addTwoNodes(l1->next, l2->next, carry);
        return l;
    }

};

class Solution_3{
public:
    int lengthOfLongestSubstring(string s){
        /*
         * HashMap 建立字符与其出现位置之间的映射
         * */
        if(s.length() == 0)return 0;
        int result = 0, left = -1;
        unordered_map<int, int> hashMap;
        for(int i = 0; i < s.size(); ++i){
            if(hashMap.count(s[i])&& hashMap[s[i]] > left){
                left = hashMap[s[i]];
            }
            hashMap[s[i]] = i;
            result = max(result, i - left);
        }
        return result;
    }
};

class Solution_4{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        // 有序数组的归并问题
        vector<int> res;
        int i = 0, j = 0;
        while (i < nums1.size() || j < nums2.size()){
            if(i == nums1.size())
                res.push_back(nums2[j++]);
            else if(j == nums2.size())
                res.push_back(nums1[i++]);
            else
                nums1[i] > nums2[j] ? res.push_back(nums2[j++]): res.push_back(nums1[i++]);
        }
        int middle = res.size() / 2;
        if(res.size() % 2 == 0)
            return (double)(res[middle] + res[middle - 1]) / 2;
        else
            return res[middle];
    }
};

class Solution_5{
public:
    string longestPalindrome(string s) {
        
    }
};
int main(){
    strToInt("-2147483649");
    cout << INT32_MIN <<" "<< INT32_MAX<< "" << endl;
    cout << ReverseSentence("I am a student.") << endl;
    return 0;
}

