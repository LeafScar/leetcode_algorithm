/
  ��.���Կ��ɹ�����ȱ���
  ����һ������
  
      3
     / \
    9  20
      /  \
     15   7
  �Ӹ��ڵ㿪ʼ��Ϊ��ǰ�ڵ�
  �����Ƕ��е������ȳ���ʾ��
  
  ���г�ʼ���������ڵ������
  (1) 3 
  ����ʱ����ǰ�ڵ���ӣ�������ǰ�ڵ������������˳�����
                                 ����˳��
  (2) |20 9|      3(��)              3
  (3) |20|        9(��)              9
  (4) |7 15|      20(��)             20
  (5) |7|         15(��)             15
  (6) ||          7(��)              7
  
  ���㷨�����Ե�������ʽʵ��
  1.����ǰ�ڵ㸳ֵΪ�Ӷ��ڵ㲢����
  2.����ǰ�ڵ���������
  3.����ǰ�ڵ���������
  
  ��.ÿ�ζ���һ��ڵ�˳������꣬��˳����Ӹò�ڵ���ӽڵ㣬˳�򲻻����
  ���е��ص��������ȳ�
  
  
  ��.��������ֻ�ܰ���˳�η��ʣ�ȴ�޷��ֲ㣬���ܴﵽ��Ŀ���
  �ʣ���Ҫ���ÿһ������һ���ڵ㣬�����ʵ�ʱ�������һ��ķ��ʣ�push�����ؽ��
  
  ���С�����: ���Ե�������ò����һ���ڵ�ʱ��
             ͬʱ�Ὣ���һ���ڵ������������ӣ�
             ���һ���ڵ��������������һ������һ���ڵ㣬
             ���ɻ�ñ�ǽڵ�
  
  ͨ���ñ�ǽڵ��𵽷ֲ����ã�ÿ�ε�������
 /
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode root) {
		vector<vector<int>> rel;

		if (root == nullptr)
			return rel;

		queue<TreeNode> tempQueue;

		tempQueue.push(root);
		TreeNode lastNode = root;		// ��¼��ǰ������һ��Ԫ�أ�����һ��˳�����һ���ڵ㣬push�������е����һ������
		TreeNode lastNodeSign = root;	// �洢��һ������һ���ڵ�
		vector<int> levelInt;
		while (!tempQueue.empty())
		{
			TreeNode x = tempQueue.front();
			tempQueue.pop();

			levelInt.push_back(x->val);	// �洢����Ԫ�ص�ֵ

			if (x->left != nullptr)
			{
				tempQueue.push(x->left);	// ���뵱ǰ�ڵ�����
				lastNodeSign = x->left;		// ���뵱ǰ�ڵ����Ӻ�������Ϊ��һ������һ���ڵ�
			}

			if (x->right != nullptr)
			{
				tempQueue.push(x->right);	// ���뵱ǰ�ڵ�����
				lastNodeSign = x->right;	// ��һ������һ���ڵ��Ϊ������
			}

			if (x == lastNode)				// �����ʵ���ǰ�����һ��Ԫ��ʱ��
			{								
				lastNode = lastNodeSign;	// ����lastNodeΪ��һ������һ��Ԫ��
				rel.push_back(levelInt);	// levelInt�Ѿ�������ǰ�������ֵ�����뷵�ؽ����
				levelInt.clear();			// ���levelInt��׼����¼��һ���ֵ
			}
		}

		return rel;
	}
};
