/*
 * ��������ֻ��������Ա��һ����ֵ��һ����ָ���̽ڵ��ָ��
 * Ҫ�𵽷�ת��������ã�ֻ��Ҫ�ı�ָ���ָ��ÿ���ڵ㶼ָ������ǰ���ڵ㣬����ʵ�ַ�ת��Ч��
 * ʾ����
 *		(1)		   1 �� 2 �� 3 �� 4 �� 5 �� NULL
 *		(2) NULL �� 1   2 �� 3 �� 4 �� 5 �� NULL
 *		(3) NULL �� 1 �� 2   3 �� 4 �� 5 �� NULL
 *		(4) NULL �� 1 �� 2 �� 3   4 �� 5 �� NULL
 *		(5) NULL �� 1 �� 2 �� 3 �� 4   5 �� NULL
 *		(6) NULL �� 1 �� 2 �� 3 �� 4 �� 5
 *		
 *	���ڸı�ڵ�ָ��ָ��ķ�����
 *		˳������������������У���¼ǰ���ڵ㣬��ǰ�ڵ㣬��̽ڵ�
 *		��¼��̽ڵ㣺��ֹ��������ζ�ʧ
 *		����ǰ�ڵ��ָ���̽ڵ��ָ�븳ֵΪǰ���ڵ�
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == nullptr || head->next == nullptr)
			return head;

		head = swapNotePt(nullptr, head, head->next);
		return head;
	}

	/*
	 * ǰ���ڵ㣺prec
	 * ��ǰ�ڵ㣺node
	 * ��̽ڵ㣺succor
	 */
	ListNode* swapNotePt(ListNode* prec, ListNode* node, ListNode* succ)
	{
		if (succ == nullptr)	// ����̽ڵ�Ϊ��ʱ��˵����ǰ�ڵ��Ѿ������һ���ǿսڵ㣬��������ָ��ָ��ǰ���ڵ㣬����ɵݹ�
		{
			node->next = prec;	
			return node;		// ���ر�ͷ
		}
		succ = node->next;		// ��¼��̽ڵ�
		node->next = prec;		// ��ǰ�ڵ�ָ��ǰ���ڵ�
		prec = node;			// ���еݹ飬ǰ���ڵ㸳ֵΪ��ǰ�ڵ�
		node = succ;			// ��ǰ�ڵ㸳ֵΪ���̽ڵ�
		return swapNotePt(prec, node, node->next);
	}
};
