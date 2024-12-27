#include <iostream>
#include <vector>

using namespace std;

string longestPalindrome(string s){
    int n = s.size();

    vector<vector<bool>> dp(n, vector<bool> (n, false));

    int start_pos = 0;
    int max_len = 1;

    for(int i = 0; i < n; i++) dp[i][i] = true;

    int j = 0;
    for(int len = 2; len <= n; len++){
        for(int i = 0; i <= n - len; i++){
            j = i + len - 1;
            if(s[i] == s[j] && dp[i + 1][j - 1]){
                dp[i][j] = true;
                if(j - i + 1 > max_len){
                    max_len = j - i + 1;
                    start_pos = i;
                }
            }
        }
    }

    return s.substr(start_pos, max_len);
}

int main(){
    cout << longestPalindrome("bababadd") << '\n';
}