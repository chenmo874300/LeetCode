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

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *pre = head, *cur = head, *ans, *tmp;
        if (head == nullptr || head -> next == nullptr)
        {
            return head;
        }
        ans = head -> next;
        while (1)
        {
            if (cur == nullptr || cur -> next == nullptr){
                pre -> next = cur;
                return ans;
            }
            else
            {
                pre -> next = cur -> next;
            }

            pre = pre -> next;
            tmp = pre -> next;
            pre -> next = cur;
            cur = tmp;
            pre = pre -> next;

        }
        return ans;
    }
};

int main(){
    Solution* s = new Solution();
    vector<int> vec = {1,2,3,4};
    ListNode *head = new ListNode(vec[0]);
    ListNode *cur = head;
    for (int i = 1; i < vec.size(); ++i) {
        ListNode *p = new ListNode(vec[i]);
        cur -> next = p;
        cur = cur -> next;
    }
    ListNode* v = s -> swapPairs(head);

    return 0;
}