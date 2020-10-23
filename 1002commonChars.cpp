#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        int strcnt = A.size();
        vector<string> ans;
        vector<vector<int> > hash(strcnt, vector<int>(26, 0));
        for (int i = 0; i < strcnt; ++i)
        {
            for (int j = 0; j < A[i].size(); ++j) {
                ++hash[i][A[i][j] - 'a'];
            }
        }
        for (int j = 0; j < 26; ++j) {
            int i = 0, cnt = INT_MAX;
            for(; i < strcnt; ++i) {
                cnt = min(hash[i][j], cnt);
            }

            while(cnt--) {
                string s(1, 'a' + j);
                ans.push_back(s);
            }
        }
        return ans;
    }
};

int main() {
    Solution* s = new Solution();
    vector<string> str = {"bella","label","roller"};  
    s -> commonChars(str);
}