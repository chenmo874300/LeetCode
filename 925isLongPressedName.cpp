#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int len = typed.size();
        int i = 0, j = 0;

        while (j < len)
        {
            if (name[i] == typed[j])
            {
                ++i;
                ++j;
            }
            else
            {
                if (name[i - 1] == typed[j])
                    ++j;
                else 
                    return false;
            }
        }
        return i == name.size();
    }
};
int main()
{
    Solution *s = new Solution();
    bool match = s->isLongPressedName("","");
    cout << "End" << endl;
}