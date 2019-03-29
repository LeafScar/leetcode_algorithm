#include <cstdio>

struct Point
{
	int x = 0;
	int y = 0;
};
bool isGroup(Point& a, Point& b);
void merge(Point points, int lo, int mi, int hi); 
void mergeSort(Point points, int lo, int hi);
long long invInside(int pointYs, int lo, int hi);
long long invBetween(int pointYs, int lo, int mi, int hi);


Point points = new Point[4000001];
Point B = new Point[4000001];
int  pointYs = new int[4000001];
int BY = new int[4000001];

int main()
{
#ifndef _OJ_
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	//setvbuf(stdin, new char[1 << 20], _IOFBF, 1 << 20);

	int n = 0;
	scanf("%d\n", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d\n", &points[i].x);
		scanf("%d\n", &points[i].y);
	}
	mergeSort(points, 0, n);
	for (int i = 0; i < n; ++i)
		pointYs[i] = points[i].y;
	long long rel = invInside(pointYs, 0, n);
	printf("%lld\n", rel);

#ifndef _OJ_
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}

bool isGroup(Point& a, Point& b)
{
	return (a.x > b.x && a.y > b.y || a.x < b.x && a.y < b.y);
}

void merge(Point points, int lo, int mi, int hi)
{
	Point A = points + lo;
	int lb = mi - lo; // Point B = new Point[lb];
	for (size_t i = 0; i < lb; B[i] = A[i++]);
	int lc = hi - mi; Point C = points + mi;

	for (int i = 0, j = 0, k = 0; j < lb; )
	{
		if (lc <= k || B[j].x < C[k].x) A[i++] = B[j++];
		if (k < lc && C[k].x <= B[j].x) A[i++] = C[k++];
	}
	//delete[] B;
}

void mergeSort(Point points, int lo, int hi)
{
	if(hi - lo < 2) return;
	int mi = (hi + lo) >> 1;
	mergeSort(points, lo, mi);
	mergeSort(points, mi, hi);
	merge(points, lo, mi, hi);
}

long long invInside(int pointYs, int lo, int hi)
{
	long long rel = 0;
	if (hi - lo < 2) return 0;
	const int mi = (lo + hi) >> 1;
	rel += invInside(pointYs, lo, mi);
	rel += invInside(pointYs, mi, hi);
	rel += invBetween(pointYs, lo, mi, hi);
	return rel;
}
long long invBetween(int pointYs, int lo, int mi, int hi)
{
	int A = pointYs + lo;
	int lb = mi - lo; // int B = new int[lb];
	for (size_t i = 0; i < lb; BY[i] = A[i++]);
	int lc = hi - mi; int C = pointYs + mi;
	long long num = 0;
	for (size_t i= 0, j = 0, k = 0; j < lb;)
	{
		if (lc <= k || (BY[j] <= C[k]))
		{
			A[i++] = BY[j++];
			if (k < lc)
				num += lc - k;
		}
		if ((k < lc) && C[k] <= BY[j])
			A[i++] = C[k++];
	}
	//delete[] B;
	return num;
}