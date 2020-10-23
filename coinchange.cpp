#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int f[amount + 10];
        int N = coins.size();
        int cnt;
        for (int i = 1; i <= N; ++i) {
            cnt = 0;
            for(int j = coins[i - 1]; j <= amount; ++j) {
                // if (f[j] <= f[j - coins[i - 1]] + coins[i - 1]) {
                //     cnt++;
                //     f[j] = f[j - coins[i - 1]] + coins[i - 1];
                // }
                f[j] = max(f[j], f[j - coins[i - 1]] + coins[i - 1]);
            }
        }
        cout << f[amount] << endl;
        if(f[amount] != amount)
            return -1;
        else
            return cnt;
    }
};

int main() {
    Solution* s = new Solution();
    vector<int> nums = {1,2,5};    
    int maxcoin = s -> coinChange(nums, 11);
    cout << maxcoin << endl;
    // vector<int> a;
    // if (a.empty()) {
    //     cout << "a is empty" << endl;
    // }
}