#include <iostream>
#include <string.h>
#include <algorithm>
#include <unordered_map>
#include "map"

using namespace std;

class Solution{
public:
    string multiply(string num1, string num2){
        string sum(num1.size() + num2.size(), '0');
        for(int i = num1.size() - 1; i > 0 ; i--){
            int carry = 0;
            for(int j = num2.size() - 1; j > 0; j--){
                int tmp = (sum[i+j+1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                sum[i + j + 1] = tmp % 10 + '0';
                carry = tmp / 10;
            }
            sum[i] += carry;
        }
        size_t start_pos = sum.find_first_not_of('0');
        if (string::npos != start_pos) {
            return sum.substr(start_pos);
        }
        return "0";
    }

};

int main() {
    long long max1, max2, max3;
    long long  min1, min2;
    max1 = max2 = max3 = INT32_MIN;
    min1 = min2 = INT32_MAX;
    int num = 0;
    cin>>num;
    int input;
    for(int i = 0; i < num; i++){
        cin>>input;
        // min1 最小
        if(input < min1){
            min2 = min1;
            min1 = input;
        }else if(input < min2){
            min2 = input;
        }
        // max1 最大
        if(input > max1){
            max3 = max2;
            max2 = max1;
            max1 = input;
        }else if(input > max2){
            max3 = max2;
            max2 = input;
        }else if(num > max3){
            max3 = input;
        }

    }
    long long res = min1 * min2 * max1 > max1 * max2 * max3 ? min1 * min2 * max1 : max1 * max2 * max3;
    cout<<min1<<" "<< min2<<" "<<max1<<" "<<max2<<" "<<max3<<endl;
    cout<<res;

    string str1, str2;
//    while(cin>>str1 >> str2){}
    cout<<cin<<cout<<endl;
    return 0;
}