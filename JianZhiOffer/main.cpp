#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isValid(char c){
    return c != '0';
}

bool isValid(char c1, char c2){
    return (c1 == '1' || c1 == '2') && c2 <='6';
}

int numDecodings(string s){
    if(s.empty() || (s['0'] == '0' && s.size() == 1)) return 0;
    if(s.size() == 1) return 1;
    vector<int> dp(s.size() + 1, 0);
    dp[0] = 1;
    for(int i = 1; i < s.size(); ++i){
        // cout << s[i] << " ";
        if(isValid(s[i]))
            dp[i] += dp[i-1];
        if(i >= 1 && isValid(s[i-1], s[i])){
            if (1 == i)
                dp[i] += dp[0];
            else if(i > 1)
                dp[i] += dp[i-2];
        }
        // cout << dp[i] << " ";
    }
    return dp[s.size() - 1];
}

int numTrees(int n){
    // Given n, how many structurally unique BST's (binary search trees)
    // that store values 1 ... n?
    vector<int> dp(n+1, 0);
    dp[0] = 1, dp[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < i; j++){
            dp[i] += dp[j] * dp[i -j - 1];
         }
    }
    return dp[n];
}

int minimumTotal(vector<vector<int>>& triangle){
    vector<int> path(triangle.size(), 0);
    for(int i = 1; i < triangle.size(); ++i){
        for(int j = 0; j < triangle.size(); ++j){
            if(j == 0){
                triangle[i][j] += triangle[i-1][j];
            }
            else if(j == triangle[i].size() - 1){
                triangle[i][j] += triangle[i-1][j-1];
            }else
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
        }
    }
    return *min_element(triangle.back().begin(), triangle.back().end());
}


int main(){
    cout << "res" << numDecodings("226") << endl;
    string s = "0";
    cout << s.size();
    cout << "Unique Binary Tree: " << numTrees(3) << endl;
    // cout << "Triangle: " << minimumTotal()
    return 0;
}