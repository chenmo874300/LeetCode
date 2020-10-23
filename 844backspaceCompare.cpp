#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> s;
        stack<char> t;
        for (int i = 0; i < S.size(); ++i)
        {
            if (S[i] == '#')
            {
                if (!s.empty())
                {
                    s.pop();
                }
                continue;
            }
            s.push(S[i]);
        }

        for (int i = 0; i < T.size(); ++i)
        {
            if (T[i] == '#')
            {
                if (!t.empty())
                {
                    t.pop();
                }
                continue;
            }
            t.push(T[i]);
        }

        while (!s.empty() && !t.empty())
        {
            if (s.top() != t.top())
                return false;
            s.pop();
            t.pop();
        }
        if (s.empty() && t.empty())
            return true;
        else
            return false;
    }
};

int main() {
    Solution* s = new Solution();
    cout << s -> backspaceCompare("vec", "vv#eeee###C#c") << endl;
    cout << "End" << endl;
}