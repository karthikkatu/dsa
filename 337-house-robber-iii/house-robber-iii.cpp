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

    pair<int, int> dfs(TreeNode* root) {
        if(!root) return {0, 0};

        int loot = 0;
        int notLoot = 0;

        auto lootLeft = dfs(root->left);
        auto lootRight = dfs(root->right);

        loot = root->val + lootLeft.second + lootRight.second;
        notLoot = max(lootLeft.first, lootLeft.second) + max(lootRight.first, lootRight.second);

        return {loot, notLoot};
    }

    int rob(TreeNode* root) {
        auto res = dfs(root);
        return max(res.first, res.second);
    }
};