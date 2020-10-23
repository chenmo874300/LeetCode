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
    void reorderList(ListNode* head) {
        if (head == nullptr || head -> next == nullptr)
            return;
        ListNode *p = head, *q = head;
        //找到链表中点
        while (q -> next)
        {
            p = p -> next;
            q = q -> next;
            if (q -> next)
                q = q -> next;
        }
        //反转链表后半段
        ListNode *pre = nullptr;
        ListNode *head2 = p -> next;
        p -> next = nullptr;
        while(head2)
        {
            ListNode *tmp = head2 -> next;
            head2 -> next = pre;
            pre = head2;
            head2 = tmp;
        }
        head2 = pre;
        //合并两个链表
        while(head2)
        {
            ListNode *tmp = head2;
            head2 = head2 -> next;
            
            tmp -> next = head -> next;
            head -> next = tmp;
            head = head -> next -> next;
        }
        return;
    }
};

int main() {
    Solution* s = new Solution();
    vector<int> vec = {-4, -1, 0, 2, 4, 7, 8};
    ListNode *head = buildList(vec);
    s -> reorderList(head);
    cout << "End" << endl;
    
}