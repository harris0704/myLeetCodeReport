# include<string>
# include<iostream>
# include<algorithm>
# include<stack>
# include<ctype.h>
#include <iomanip>
using namespace std;

//
//double helper(int round, bool flag, vector<float> &v){
//    if(round == v.size() && v.size()%2 == 1){
//        helper()
//    }
//    helper()
//}
int main(){

    double n = 0.9999999;
    cout.setf(ios::showpoint);
    cout.setf(ios::fixed);
    cout<<setprecision(4)<<n;

//    int N;
//    cin >> N;
//    double *pos = new double[100];
//    double *p = new double[100];
//    bool flag = N<100;
//
//    for(int i =0; i< N; i++)
//    {
//        cin>>*(p+i);
//
//    }
//
//    if(flag)
//    {
//        for(int i=0; i< 100/N; i++)
//        {
//            for(int j =0; j < N; j++)
//            {
//                if(i%2)
//                *(pos+j+i*N) = *(p+j);
//                else{
//                    *(pos+j+i*N) = 1-*(p+j);
//                }
//            }
//        }
//    }else
//    {
//        for(int i = 0; i<100; ++i)
//        {
//            *(pos+i) = *(pos+i);
//        }
//    }
//
//    for(int)






//    for(int i = 0; i < 100; ++i){
//        int value;
//        cin >> value;
//        if((i+1 <= N) && (i+1)%2==1)
//            *pos = value;
//        else
//            *pos = 1 - value;
//        if((i+1 > N) && (i+1)%2==0)
//            *pos = 1 - value;
//        else
//            *pos = value;
//    }
//    float res;
//    for(int i = 0; i < 100; i++)
//        res *= *(pos+1);
//    cout << res;
    return 0;

//    string str, result;
//    cin >> str;
//    stack<int> stackNum;
//    stack<char> stackChar;
//    stack<string> stackStr;
//    for(int i = 0; i < str.size(); ++i){
//        if(isdigit(str[i]))
//            stackNum.push(str[i] - '0');
//        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
//            stackChar.push(str[i]);
//            string tmp;
//            while(isalpha(str[++i]))
//                tmp.push_back(str[i]);
//            stackStr.push(tmp);
//            continue;
//        }if(str[i] == ')' || str[i] == ']' || str[i] == '}'){
//            stackChar.pop();
//            string tmp = stackStr.top();
//            stackStr.pop();
//            int repeat = stackNum.top();
//            stackNum.pop();
//
//            for(int j = 0 ; j<repeat; ++j){
//
//            }
//        }
//
//
//    }


    /*for(int i = 0; i < str.size(); ++i){
        if(!findNum && isalpha(str[i])){
            result.push_back(str[i]);
        }
        else if(isdigit(str[i])){
            int num = str[i] - '0';
            findNum = true;
            repeat = num;
        }else
            continue;

        if(findNum && isalpha(str[i])){
            for(int j = 0; j < repeat; ++j){
                result.push_back(str[i]);
            }
            repeat = 0;
            findNum = false;
        }
    }*/
//    reverse(result.begin(), result.end());
//    cout << result;

}
