#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;



// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if (!root) return root;
        q.push(root);
        while (!q.empty())
        {
            Node* node = q.front();
            if (node -> left != nullptr)    q.push(node -> left);
            if (node -> right != nullptr)  q.push(node -> right);
            q.pop();
            node -> next = q.front();
        }
        Node *node = root;
        while(node)
        {
            node -> next = nullptr;
            node = node -> right;
        }
        return root;
    }
};

Node* helper(vector<int>& vec, int index)
{
    if (index > vec.size() || vec[index] == -1)
        return nullptr;
    Node *root = new Node(vec[index]);
    root -> left = helper(vec, index * 2 + 1);
    root -> right = helper(vec, index * 2 + 2);
    return root;
}

Node* buildTree(vector<int>& vec) 
{
        int len = vec.size();
        Node* root = new Node(vec[0]);
        return helper(vec, 0);
}


int main() {
    Solution* s = new Solution();
    vector<int> vec = {1,2,3};
    Node* root = buildTree(vec);
    s -> connect(root);
}