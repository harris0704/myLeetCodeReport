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




int main(){
    strToInt("-2147483649");
    cout << INT32_MIN <<" "<< INT32_MAX<< "" << endl;
    cout << ReverseSentence("I am a student.") << endl;

    return 0;
}

