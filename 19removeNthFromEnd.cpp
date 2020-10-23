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

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr)
            return head;
        ListNode *phead = new ListNode(-1);
        phead -> next = head;
        ListNode* fast = phead, *slow = phead;
        while (fast != nullptr && n > 0)
        {
            fast = fast -> next;
            --n;
        }
        if (fast == nullptr)
        {
            phead -> next = nullptr;
        }
        while (fast -> next)
        {
            slow = slow -> next;
            fast = fast -> next;
        }
        slow -> next = slow -> next -> next;
        return phead -> next;
    }
};

int main() {
    Solution* s = new Solution();
    vector<int> vec = {-4, -1, 0, 2, 4, 7, 8};
    ListNode *head = buildList(vec);
    s -> removeNthFromEnd(head, 2);
    cout << "End" << endl;
    
}