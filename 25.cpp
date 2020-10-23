// #include "./Assist/assist.h"
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* buildList(vector<int>& vec)
{
    if (vec.empty())    return nullptr;

    ListNode *head = new ListNode(vec[0]);
    ListNode *cur = head;
    for (int i = 1; i < vec.size(); ++i) {
        ListNode *p = new ListNode(vec[i]);
        cur -> next = p;
        cur = cur -> next;
    }
    return head;
}

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *pre = new ListNode(-1);
        ListNode *pg, *thead = head;
        pre -> next = head;
        pg = pre;
        while (1)
        {
            
            int tmp = k;
            ListNode *cur = thead;
            while (tmp > 0 && cur != nullptr)
            {
                cur = cur -> next;
                --tmp;
            }
            if (tmp > 0)    return pre -> next;
            
            ListNode *p,*q;
            tmp = k;
            p = thead;
            q = thead;
            while (--tmp)
            {
                p = thead -> next;
                thead -> next = p -> next;
                p -> next = q;
                q = p;         
            }
            pg -> next = q;
            pg = thead;
            thead = thead -> next;
        }
    }
};

int main(){
    Solution* s = new Solution();
    vector<int> vec = {1,2,3,4,5};
    ListNode* x = buildList(vec);
    ListNode* v = s -> reverseKGroup(x, 3);
    return 0;
}