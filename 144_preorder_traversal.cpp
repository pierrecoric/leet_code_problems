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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) {
            return {};
        }
        result.push_back(root -> val);
        if(root -> left != nullptr) {
            vector<int> leftTraversal = preorderTraversal(root -> left);
            mergeVectors(result, leftTraversal);
        }
        if(root -> right != nullptr) {
            vector<int> rightTraversal = preorderTraversal(root -> right);
            mergeVectors(result, rightTraversal);
        }
        return result;
    }
    
};

void mergeVectors(vector<int>& A, vector<int>& B) {
    A.insert(A.end(), B.begin(), B.end());
}