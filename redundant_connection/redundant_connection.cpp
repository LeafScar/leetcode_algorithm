#include <vector>
using namespace std;
class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		vector<int> parent;
		for (int i = 0; i <= edges.size(); ++i)
			parent.push_back(i);

		for (int i = 0; i < edges.size(); ++i)
		{
			int p1 = find(edges[i][0], parent);
			int p2 = find(edges[i][1], parent);
			if (p1 == p2)
				return edges[i];
			else
				join(p1, p2, parent);
		}
		return vector<int>();
	}

	void join(int x, int y, vector<int>& parent)
	{
		if (x > y)
			parent[y] = parent[x];
		else
			parent[x] = parent[y];
	}

	int find(int num, vector<int>& parent)
	{
		while (num != parent[num])
			num = parent[num];

		return num;
	}
};
