#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int ans = 0;
    vector<string> vec;
    vector<int> col, row, dg, udg;
    int totalNQueens(int n) {
        vec.resize(n, string(n, '.'));// 构建一个n * n 的 '.' 棋盘
        col.resize(n, 0);
        row.resize(n, 0);
        dg.resize(2 * n, 0);
        udg.resize(2 * n, 0);
        dfs(0, n);
        return ans;
    }

    void dfs(int curRow, int n)
    {
        if (curRow == n)
        {
            ++ans;
        }
        else
        {
            for (int i = 0; i < n; ++i)
            {
                if (!row[i] && !col[i] && !dg[n + i - curRow] && !udg[i + curRow])
                {
                    vec[curRow][i] = 'Q';
                    row[i] = col[i] = dg[n + i - curRow] = udg[i + curRow] = 1;
                    dfs(curRow + 1, n);
                    vec[curRow][i] = '.';
                    row[i] = col[i] = dg[n + i - curRow] = udg[i + curRow] = 0;
                }
            }
        }
    }
};

int main() {
    Solution* s = new Solution();
    s -> totalNQueens(4);
}