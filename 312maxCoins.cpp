#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int len = nums.size();
        if (len == 1) {
            return nums[0];
        }
        vector<vector<int> > dp(len + 2, vector<int>(len + 2, 0));
        for (int i = 2; i < len; i++) {
            dp[i][i] = nums[i - 2] * nums[i - 1] * nums[i];
        }
        dp[1][1] = 1 * nums[0] * nums[1];
        dp[len][len] = nums[len - 2] * nums[len - 1] * 1;

        int left, right;
        for (int wide = 2; wide <= len; wide++) {
            for (int i = 1; i + wide - 1 < len + 1; i++) {
                int j = i + wide - 1;
                for(int m = i; m <= j; m++) {
                    left = i - 2 < 0 ? 1 : nums[i - 2];
                    right = j > len - 1 ? 1 : nums[j];                    
                    dp[i][j] = max(dp[i][j], left * nums[m - 1] * right + dp[i][m - 1] + dp[m + 1][j]);
                }
            }
        }
        return dp[1][len];
    }
};

int main() {
    Solution* s = new Solution();
    vector<int> nums = {7, 2, 9};    
    int maxcoin = s -> maxCoins(nums);
    cout << maxcoin << endl;
    // vector<int> a;
    // if (a.empty()) {
    //     cout << "a is empty" << endl;
    // }
}