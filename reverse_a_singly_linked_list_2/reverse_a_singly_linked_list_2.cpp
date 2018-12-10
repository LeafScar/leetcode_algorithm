/*
 *  ��ת���������ʾΪ���²���
 *  (1)	1            �� 2 �� 3 �� 4 �� 5 �� NULL
 *  (2) 1 �� 2 | NULL �� 2   3 �� 4 �� 5 �� NULL
 *  (3) 1 �� 2 | NULL �� 2 �� 3   4 �� 5 �� NULL
 *  (4) 1 �� 2 | NULL �� 2 �� 3 �� 4   5 �� NULL
 *      ��   ��                  ��   ��
 *     m-1  m                  n  n+1
 *  (5) ��2(�ڵ�m)��nextָ��5(�ڵ�n+1)����1(�ڵ�m-1)��nextָ��4(�ڵ�n)
 *  (6) 1 �� 4 �� 3 �� 2 �� 5 �� NULL
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* node = head;		// ��ǰ�ڵ㣺node
		ListNode* leader = nullptr;	// �ڵ� m-1

		for (int i = 1; i <= m - 1; ++i)
		{
			leader = node;
			node = node->next;
		}

		ListNode* tempNode = node;	// ��¼�ڵ� m
		ListNode* prec = nullptr;	// ǰ���ڵ㣺prec
		ListNode* succ = node->next;// ��̽ڵ㣺succ

		for (int i = m; i < n; ++i)
		{
			node->next = prec;		// ��ǰ�ڵ�ָ��ǰ���ڵ�
			prec = node;			// ���еݹ飬ǰ���ڵ㸳ֵΪ��ǰ�ڵ�		
			node = succ;			// ��ʼ����ǰ�ڵ�Ϊ��ǰ�ڵ�ĺ�̽ڵ�
			succ = node->next;		// ��ʼ����̽ڵ�Ϊ��ǰ�ڵ�ĺ�̽ڵ�ĺ�̽ڵ�
		}
		node->next = prec;			// ʵ�� m ~ n ��ת
		// ��ʱnodeΪ�ڵ� n��succΪ�ڵ� n+1
		// ���ڵ�(5)��m.next �� n+1��(m - 1).next �� n
		tempNode->next = succ;		// tempNodeΪ�ڵ�m������ m.next �� n+1 ����

		if (m == 1)
			head = node;			// ���head�����ڷ�ת��Χ�ڣ��򷵻���head
		else
			leader->next = node;	// leaderΪ�ڵ�m - 1������ (m - 1).next �� n

		return head;
	}
};
