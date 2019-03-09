#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
	int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
		vector<pair<int, int>> store;
		for (int i = 0; i < Profits.size(); ++i)
			store.push_back(make_pair(Capital[i], Profits[i]));

		sort(store.begin(), store.end(), [](pair<int, int>& a, pair<int, int>& b) {return (a.first < b.first || (a.first == b.first && a.second < b.second)); });

		vector<pair<int, int>>::iterator it = store.begin();
		priority_queue<int> profit_queue;
		for (int i = 0; i < k; ++i)
		{
			while (it != store.end() && it->first <= W)
			{
				profit_queue.push(it->second);
				++it;
			}

			if (!profit_queue.empty())
			{
				W += profit_queue.top();
				profit_queue.pop();
			}
		}
		return W;
	}
};