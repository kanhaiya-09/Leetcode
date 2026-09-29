class Solution {
public:
    unordered_map<int, int> pos;

    TreeNode* build(vector<int>& inorder, vector<int>& postorder,
                    int inStart, int inEnd,
                    int postStart, int postEnd) {

        if (inStart > inEnd || postStart > postEnd)
            return nullptr;

        int rootValue = postorder[postEnd];

        TreeNode* root = new TreeNode(rootValue);

        int rootIndex = pos[rootValue];

        int leftSize = rootIndex - inStart;

        root->left = build(
            inorder, postorder,
            inStart,
            rootIndex - 1,
            postStart,
            postStart + leftSize - 1
        );

        root->right = build(
            inorder, postorder,
            rootIndex + 1,
            inEnd,
            postStart + leftSize,
            postEnd - 1
        );

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        for (int i = 0; i < inorder.size(); i++)
            pos[inorder[i]] = i;

        return build(
            inorder,
            postorder,
            0,
            inorder.size() - 1,
            0,
            postorder.size() - 1
        );
    }
};