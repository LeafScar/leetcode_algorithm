/*
 * 单向链表只有两个成员，一个是值，一个是指向后继节点的指针
 * 要起到反转链表的作用，只需要改变指针的指向，每个节点都指向它的前驱节点，即可实现反转的效果
 * 示例：
 *		(1)		   1 → 2 → 3 → 4 → 5 → NULL
 *		(2) NULL ← 1   2 → 3 → 4 → 5 → NULL
 *		(3) NULL ← 1 ← 2   3 → 4 → 5 → NULL
 *		(4) NULL ← 1 ← 2 ← 3   4 → 5 → NULL
 *		(5) NULL ← 1 ← 2 ← 3 ← 4   5 → NULL
 *		(6) NULL ← 1 ← 2 ← 3 ← 4 ← 5
 *		
 *	对于改变节点指针指向的方法：
 *		顺序遍历链表，遍历过程中，记录前驱节点，当前节点，后继节点
 *		记录后继节点：防止链表后续段丢失
 *		将当前节点的指向后继节点的指针赋值为前驱节点
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
	 * 前驱节点：prec
	 * 当前节点：node
	 * 后继节点：succor
	 */
	ListNode* swapNotePt(ListNode* prec, ListNode* node, ListNode* succ)
	{
		if (succ == nullptr)	// 当后继节点为空时，说明当前节点已经是最后一个非空节点，将其链表指针指向前驱节点，即完成递归
		{
			node->next = prec;	
			return node;		// 返回表头
		}
		succ = node->next;		// 记录后继节点
		node->next = prec;		// 当前节点指向前驱节点
		prec = node;			// 进行递归，前驱节点赋值为当前节点
		node = succ;			// 当前节点赋值为其后继节点
		return swapNotePt(prec, node, node->next);
	}
};
