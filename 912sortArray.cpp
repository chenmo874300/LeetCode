#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        int i, j;
        for (i = 1; i < nums.size(); ++i)
        {
            int tmp = nums[i];
            for (j = i; j > 0 && tmp < nums[j - 1]; --j)
            {
                nums[j] = nums[j - 1];
            }
            nums[j] = tmp;
        }
        return nums;
    }

    void swap(int &a, int &b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> vec = {5,2,3,1};
    s->sortArray(vec);
    cout << "End" << endl;
}