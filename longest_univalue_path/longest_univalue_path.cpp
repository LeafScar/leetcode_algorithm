 #include <algorithm>
using namespace std;
 struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	
};
class Solution {
public:
	int maxLen = 0;
	int longestUnivaluePath(TreeNode* root) {
		if (root == nullptr)
			return 0;

		getMaxLen(root, root->val);
		return maxLen;
	}

	int getMaxLen(TreeNode* root, int val)
	{
		if (root == nullptr)
			return 0;

		int left = getMaxLen(root->left, root->val);
		int right = getMaxLen(root->right, root->val);
		maxLen = max(maxLen, left + right);
		if (root->val == val)
			return max(left, right) + 1;

		return 0;
	}
};