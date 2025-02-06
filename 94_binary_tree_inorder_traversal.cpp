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

void mergeVectors(vector<int>& A, vector<int>& B);

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) {
            return {};
        }
        if(root -> left != nullptr) {
            vector<int> leftTraversal = inorderTraversal(root -> left);
            mergeVectors(result, leftTraversal);
        }
        result.push_back(root -> val);
        if(root -> right != nullptr) {
            vector<int> rightTraversal = inorderTraversal(root -> right);
            mergeVectors(result, rightTraversal);
        }
        return result;
    }
    
};

void mergeVectors(vector<int>& A, vector<int>& B) {
    A.insert(A.end(), B.begin(), B.end());
}