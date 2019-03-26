// ����������Ҫ�������
// ��ν���(pivot)�������Ԫ�ؾ������������Ҳ�Ԫ�ؾ�������С

/*
 template <typename T>
 void quickSort(int lo, int hi)
 {
	 if (hi - lo < 2) return;	// ��Ԫ��������Ȼ���򣬷���
	 int mi = partition(lo, hi - 1); // �ȹ������
	 quickSort(lo, mi);
	 quickSort(mi + 1, hi);
 }
*/

// ��������ĺ��ľ�����ο���ȷ�����
// �����������У�����Ԫ�ؽ�Ϊ��㣻��֮��Ȼ
// ������ν�������򣬾��ǽ�����Ԫ�����ת��Ϊ���Ĺ���
// ����ͨ���ʵ��Ľ�������ʹ��һԪ��ת��Ϊ���

/*

  ��ͨ�Ŀ��������ǽ����л��ֳɣ���ѡ��㡢����Ԫ�ز����ں�ѡ����������L��δ֪��С����U������Ԫ�ز�С�ں�ѡ����������G
  |lo|     L     |      U     |     G     |
   ��             ��      ��     ��
   0            lo      k     hi
   ����˵������Ϊ0���Ǻ�ѡ��㣬loΪ������L��U�ķֽ磬hiΪ������G��U�ķֽ磬hi��lo����λ�ü�Ϊ��ѡ�����λ��

  ���������һ�����ּ��������л��ֳɣ���ѡ��㡢����Ԫ�ز����ں�ѡ����������L������Ԫ�ز�С�ں�ѡ����������G��δ֪��С����U
  |lo|     L     |      G     |     U     |
   ��             ��		      ��
   0             mi           k
   ����˵������Ϊ0���Ǻ�ѡ��㣬miΪ������L��G�ķֽ磬kΪ������G��U�ķֽ磬����miֹͣ��λ�ã���Ϊ��ѡ�����λ��
   [k]��С����� ? ֱ����չG(��k++) : G�������ƣ�L��չ(��++mi)���ҽ���mi��k��k++
*/

// ��������ı��֣��������㵥������Ѱ��ֻ�ܴ���ĩ�ķ����ص�
// ���������ڵ㽻���Ĺ���˼ά�ǣ�ָ�뽻������ʵ����ֱ�ӽ���������ڵ��ֵ��������ɻ�λ���� 

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
		if (lo == hi)			// �ݹ�����ݹ������������������������ֻ��һ���ڵ�ʱ
			return;

		ListNode* mi = paitition(lo, hi);
		sortList(lo, mi);
		sortList(mi->next, hi);
	}

	ListNode* paitition(ListNode* lo, ListNode* hi)
	{
		ListNode* pivot = lo;		// ��ѡ���
		ListNode* mi = lo;			// ����L��G�ķֽ�㣬ָ��L���е����һ��
		for (ListNode* k = lo->next; k != hi; k = k->next)		// ������G��U�ķֽ磬ֱ��k�����������������ĩ�ڵ����
		{
			if (k->val < pivot->val)
			{
				mi = mi->next;		// k��pivotС������k��ʱ��λ��Ӧ����L���У���mi��һ��Ԫ����k��ֵ�����������𵽽�L��������
				swap(mi, k);
			}
		}
		// ��ʱ��mi���ڽڵ㼴Ϊ���Ӧ���λ��
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