// 快速排序，需要借助轴点
// 所谓轴点(pivot)：其左侧元素均不比它大，其右侧元素均不比它小

/*
 template <typename T>
 void quickSort(int lo, int hi)
 {
	 if (hi - lo < 2) return;	// 单元素区间自然有序，否则
	 int mi = partition(lo, hi - 1); // 先构造轴点
	 quickSort(lo, mi);
	 quickSort(mi + 1, hi);
 }
*/

// 快速排序的核心就是如何快速确定轴点
// 在有序序列中，所有元素皆为轴点；反之亦然
// 所以所谓快速排序，就是将所有元素逐个转换为轴点的过程
// 可以通过适当的交换，可使任一元素转换为轴点

/*

  普通的快速排序，是将序列划分成：候选轴点、所有元素不大于候选轴点的子序列L，未知大小序列U，所有元素不小于候选轴点的子序列G
  |lo|     L     |      U     |     G     |
   ↑             ↑      ↑     ↑
   0            lo      k     hi
   参数说明：秩为0处是候选轴点，lo为子序列L与U的分界，hi为子序列G与U的分界，hi与lo碰面位置即为候选轴点存放位置

  快速排序的一个变种即，讲序列划分成：候选轴点、所有元素不大于候选轴点的子序列L，所有元素不小于候选轴点的子序列G，未知大小序列U
  |lo|     L     |      G     |     U     |
   ↑             ↑		      ↑
   0             mi           k
   参数说明：秩为0处是候选轴点，mi为子序列L与G的分界，k为子序列G与U的分界，最终mi停止的位置，即为候选轴点存放位置
   [k]不小于轴点 ? 直接拓展G(即k++) : G滚动后移，L拓展(即++mi)，且交换mi与k，k++
*/

// 快速排序的变种，正好满足单向链表，寻秩只能从起到末的访问特点
// 对于链表，节点交换的惯性思维是，指针交换，其实可以直接将链表的两节点的值交换来完成换位操作 

#include <vector> 
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		sortList(head, nullptr);
		return;
	}

	void sortList(ListNode* lo, ListNode* hi)
	{
		if (lo == hi)			// 递归基，递归结束条件，即当待排序链表只有一个节点时
			return;

		ListNode* mi = paitition(lo, hi);
		sortList(lo, mi);
		sortList(mi->next, hi);
	}

	ListNode* paitition(ListNode* lo, ListNode* hi)
	{
		ListNode* pivot = lo;		// 候选轴点
		ListNode* mi = lo;			// 序列L与G的分界点，指向L序列的最后一个
		for (ListNode* k = lo->next; k != hi; k = k->next)		// 子序列G与U的分界，直到k遍历到整个链表的最末节点结束
		{
			if (k->val < pivot->val)
			{
				mi = mi->next;		// k比pivot小，所以k此时的位置应属于L序列，将mi后一个元素与k的值交换，可以起到将L序列扩大
				swap(mi, k);
			}
		}
		// 此时，mi所在节点即为轴点应存放位置
		swap(pivot, mi);
		return mi;
	}

	void swap(ListNode* a, ListNode* b)
	{
		int val = a->val;
		a->val = b->val;
		b->val = val;
	}
};