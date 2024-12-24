#include <iostream>
#include <vector>

using namespace std;

bool isInterleave(string s1, string s2, string s3){
    int y = s1.size();
    int x = s2.size();

    if(x + y != s3.size()) return false;

    vector<vector<bool>> dp(y + 1, vector<bool> (x + 1, false));

    dp[0][0] = true;

    for(int i = 1; i <= x; i++){
        if((s2[i - 1] == s3[i - 1]) && dp[0][i - 1]){
            dp[0][i] = true;
        }else{
            dp[0][i] = false;
        }
    }

    for(int i = 1; i <= y; i++){
        if((s1[i - 1] == s3[i - 1]) && dp[i - 1][0]){
            dp[i][0] = true;
        }else{
            dp[i][0] = false;
        }
    }

    int pos = 0;
    for(int i = 1; i <= y; i++){
        for(int j = 1; j <= x; j++){
            pos = i + j;

            if((s1[i - 1] == s3[pos - 1]) && dp[i - 1][j]){
                dp[i][j] = true;
            }

            if((s2[j - 1] == s3[pos - 1]) && dp[i][j - 1]){
                dp[i][j] = true;
            }
        }
    }

    return dp[y][x];
}

int main(){
    string s1 = "abcd";
    string s2 = "ef";
    string s3 = "abecdf";

    cout << isInterleave(s1, s2, s3) << "\n";
}