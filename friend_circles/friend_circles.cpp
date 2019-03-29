#include <vector>
using namespace std;

class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		vector<int> visited(M.size(), 0);
		int res = 0;
		for (int i = 0; i < M.size(); ++i)
		{
			if (visited[i] == 0)
			{
				res += 1;
				dfs(M, i, visited);
			}
		}
		return res;
	}

	void dfs(vector<vector<int>>& M, int i, vector<int>& visited)
	{
		visited[i] = 1;
		for (int j = 0;j < M.size(); ++j)
		{
			if (M[i][j] != 0 && visited[j] == 0)
				dfs(M, j, visited);
		}
	}
};
