#include <cstdio>

using namespace std;

int BinarySearch(int* NumGroup, int left, int right, int x, bool flag);
void qsort(int* NumGroup, int lo, int hi);
void swap(int* NumGroup, int i, int j);

int main()
{
#ifndef _OJ_
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	// 数组总数
	int n = 0;
	scanf("%d\n", &n);

	// 范围数
	int rangeNum = 0;
	scanf("%d\n", &rangeNum);

	// 数组元素填充
	int* NumGroup = new int[n + 2];
	NumGroup[0] = -1;
	NumGroup[n + 1] = 10e7 + 1;
	for (int i = 1; i < n + 1; ++i)
		scanf("%d\n", &NumGroup[i]);

	qsort(NumGroup, 1, n);
	n = n + 2;

	int** descriptioin = new int*[rangeNum];
	for (int i = 0; i < rangeNum; ++i)
	{
		descriptioin[i] = new int[2];
		scanf("%d\n", &descriptioin[i][0]);
		scanf("%d\n", &descriptioin[i][1]);
	}

	for (int i = 0; i < rangeNum; ++i)
	{
		int lowerBound = BinarySearch(NumGroup, 0, n - 1, descriptioin[i][0], false);
		int upperBound = BinarySearch(NumGroup, lowerBound, n - 1, descriptioin[i][1], true);
		printf("%d\n", upperBound - lowerBound + 1);
	}

#ifndef _OJ_
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}

// int flag 上界true或下届false
int BinarySearch(int* NumGroup, int left, int right, int x, bool flag)
{
	int mid = (left + right + 1) / 2;
	if (NumGroup[mid] == x)
		return mid;

	if (NumGroup[mid - 1] < x && x < NumGroup[mid])
	{
		if (flag)
			return mid - 1;
		else
			return mid;
	}

	if (x < NumGroup[mid])
		return BinarySearch(NumGroup, left, mid - 1, x, flag);
	else
		return BinarySearch(NumGroup, mid, right, x, flag);
}

void qsort(int* NumGroup, int lo, int hi)
{
	if (lo > hi)
		return;

	int base = NumGroup[lo];
	int i = lo;
	int j = hi;
	while (i != j)
	{
		while (NumGroup[j] >= base && i < j)
			j--;
		while (NumGroup[i] <= base && i < j)
			i++;


		swap(NumGroup, i, j);
	}

	swap(NumGroup, lo, i);
	qsort(NumGroup, lo, i - 1);
	qsort(NumGroup, i + 1, hi);
}

void swap(int* NumGroup, int i, int j)
{
	int temp = NumGroup[i];
	NumGroup[i] = NumGroup[j];
	NumGroup[j] = temp;
}