#include <iostream>
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
    ListNode* insertionSortList(ListNode* head) {
        if (head == nullptr)
        {
            return head;
        }
        ListNode* phead = new ListNode(-1);
        ListNode* cur = head -> next;
        phead -> next = head;
        ListNode* pre = head;

        while (cur)
        {
            if (cur -> val < pre -> val)
            {
                ListNode* tmp = phead;
                while (tmp -> next -> val < cur -> val)
                {
                    tmp = tmp -> next;
                }
                pre -> next = cur -> next;
                cur -> next = tmp -> next;
                tmp -> next = cur;
                cur = pre -> next;
            }
            else
            {
                cur = cur -> next;
                pre = pre -> next;
            }         
        }

        return phead -> next;
    }
};

int main()
{
    Solution *s = new Solution();
    vector<int> vec = {4,2,1,3};
    ListNode* head = buildList(vec);
    s->insertionSortList(head);
    cout << "End" << endl;
}