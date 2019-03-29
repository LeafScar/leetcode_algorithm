struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
 
class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		mergeTree(t1, t2);
		return t1;
	}

	void mergeTree(TreeNode*& t1, TreeNode*& t2)
	{
		if (t1 == nullptr && t2 == nullptr)
			return;
		else if (t1 == nullptr && t2 != nullptr)
			t1 = t2;
		else if (t1 != nullptr && t2 != nullptr)
		{
			t1->val += t2->val;
			mergeTree(t1->left, t2->left);
			mergeTree(t1->right, t2->right);
		}
	}
};