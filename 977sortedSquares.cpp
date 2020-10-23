#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        for (int i = 0; i < A.size(); ++i)
        {
            A[i] = A[i] * A[i];
        }
        sort(A.begin(), A.end());
        return A;
    }
};

int main() {
    Solution* s = new Solution();
    vector<int> vec = {-4, -1, 0, 2, 4, 7, 8};
    s -> sortedSquares(vec);
    
}