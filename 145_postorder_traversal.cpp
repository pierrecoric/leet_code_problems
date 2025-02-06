/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> result;
        if(root -> left) {
            vector<int> local = postorderTraversal(root -> left);
            result.insert(result.end(), local.begin(), local.end());
        }
        if(root -> right) {
            vector<int> local = postorderTraversal(root -> right);
            result.insert(result.end(), local.begin(), local.end());
        }
        result.push_back(root -> val);
        return result;
    }
};