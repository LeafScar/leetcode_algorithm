/*
 *  反转步骤可以演示为以下步骤
 *  (1)	1            → 2 → 3 → 4 → 5 → NULL
 *  (2) 1 → 2 | NULL ← 2   3 → 4 → 5 → NULL
 *  (3) 1 → 2 | NULL ← 2 ← 3   4 → 5 → NULL
 *  (4) 1 → 2 | NULL ← 2 ← 3 ← 4   5 → NULL
 *      ↑   ↑                  ↑   ↑
 *     m-1  m                  n  n+1
 *  (5) 将2(节点m)的next指向5(节点n+1)，将1(节点m-1)的next指向4(节点n)
 *  (6) 1 → 4 → 3 → 2 → 5 → NULL
 */
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* node = head;		// 当前节点：node
		ListNode* leader = nullptr;	// 节点 m-1

		for (int i = 1; i <= m - 1; ++i)
		{
			leader = node;
			node = node->next;
		}

		ListNode* tempNode = node;	// 记录节点 m
		ListNode* prec = nullptr;	// 前驱节点：prec
		ListNode* succ = node->next;// 后继节点：succ

		for (int i = m; i < n; ++i)
		{
			node->next = prec;		// 当前节点指向前驱节点
			prec = node;			// 进行递归，前驱节点赋值为当前节点		
			node = succ;			// 初始化当前节点为当前节点的后继节点
			succ = node->next;		// 初始化后继节点为当前节点的后继节点的后继节点
		}
		node->next = prec;			// 实现 m ~ n 反转
		// 此时node为节点 n，succ为节点 n+1
		// 对于第(5)点m.next → n+1，(m - 1).next → n
		tempNode->next = succ;		// tempNode为节点m，进行 m.next → n+1 步骤

		if (m == 1)
			head = node;			// 如果head包含在反转范围内，则返回新head
		else
			leader->next = node;	// leader为节点m - 1，进行 (m - 1).next → n

		return head;
	}
};
