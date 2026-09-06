class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nums) {
        if (root == nullptr)
            return;

        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
    }

    TreeNode* build(vector<int>& nums, int left, int right) {
        if (left > right)
            return nullptr;

        int mid = left + (right - left) / 2;

        TreeNode* root = new TreeNode(nums[mid]);

        root->left = build(nums, left, mid - 1);
        root->right = build(nums, mid + 1, right);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nums;

        // 1. Get sorted values
        inorder(root, nums);

        // 2. Build balanced BST
        return build(nums, 0, nums.size() - 1);
    }
};