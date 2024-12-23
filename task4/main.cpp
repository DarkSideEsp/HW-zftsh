#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int>> m){
    vector<vector<int>> ans(m.size(), vector<int> (m[0].size(), 0));
    
    ans[0][0] = m[0][0];
    for(int i = 1; i < m.size(); i++) ans[0][i] = ans[0][i - 1] + m[0][i];
    for(int i = 1; i < m[0].size(); i++) ans[i][0] = ans[i - 1][0] + m[i][0];

    for(int y = 1; y < m.size(); y++){
        for(int x = 1; x < m[0].size(); x++){
            ans[y][x] = min(ans[y - 1][x], ans[y][x - 1]) + m[y][x];
        }
    }

    return ans[ans.size() - 1][ans[0].size() - 1];
}

int main(){
    vector<vector<int>> m = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {4, 1, 1, 1, 5},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    cout << minPathSum(m) << "\n";
}