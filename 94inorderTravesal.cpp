#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (!st.empty() || cur != nullptr) {
            if (cur != nullptr) {
                st.push(cur);
                cur = cur -> left;
            }
            else {
                cur = st.top();
                st.pop();
                in.push_back(cur -> val);
                cur = cur -> right;
            }
        }
        return in;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();     
        return helper(inorder, postorder, 0, len - 1, 0, len - 1);
    }

    TreeNode* helper(vector<int>& inorder, vector<int> postorder, int inleft, int inright, int postleft, int postright) {
        if (inleft > inright)
            return NULL;
        
        int inmid = find(inorder.begin(), inorder.end(), postorder[postright]) - inorder.begin();
        cout << inmid;
        TreeNode* node = new TreeNode(inorder[inmid]);

        int leftlen = inmid - inleft;
        int rightlen = inright - inmid;
        node -> left = helper(inorder, postorder, inleft, inmid - 1, postleft, postleft + leftlen - 1);
        node -> right = helper(inorder, postorder, inmid + 1, inright, postright - rightlen, postright - 1);
        return node;
    }
};

int main(){
    Solution* s = new Solution();
    vector<int> inorder = {1,9,2,3,4,15,5,20,6,7,8};
    vector<int> postorder = {1,2,9,4,5,15,6,8,7,20,3};
    TreeNode* node = s -> buildTree(inorder, postorder);
    vector<int> vec = s -> inorderTraversal(node);

    return 0;
}
