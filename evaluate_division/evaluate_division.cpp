#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
		set<string> points;
		map<pair<string, string>, double> mapKeyValues;
		for (int i = 0; i < equations.size(); ++i)
		{
			points.insert(equations[i].first);
			points.insert(equations[i].second);
			mapKeyValues[equations[i]] = values[i];
			mapKeyValues[{equations[i].second, equations[i].first}] = 1 / values[i];
		}

		vector<double> result;
		for (int i = 0; i < queries.size(); ++i)
		{
			set<string> visits;
			visits.insert(queries[i].first);
			result.push_back(dfs(queries[i], queries[i].first, points, visits, mapKeyValues));
			mapKeyValues[queries[i]] = result[result.size() - 1];
		}
		return result;
	}

	double dfs(pair<string, string>& query, string nowPosition, set<string>& points, set<string>& visits, map<pair<string, string>, double>& mapKeyValues)
	{
		if (points.find(query.first) == points.end() || points.find(query.second) == points.end())
			return -1.0;
		else if (query.first == query.second || query.second == nowPosition)
			return 1.0;

		for (string nextPoint : points)
		{
			if (mapKeyValues.find({ nowPosition , nextPoint}) != mapKeyValues.end() && visits.find(nextPoint) == visits.end())
			{
				visits.insert(nextPoint);
				double temp = dfs(query, nextPoint, points, visits, mapKeyValues);
				if (temp == -1.0)
					visits.erase(nextPoint);
				else
					return mapKeyValues[{nowPosition, nextPoint}] * temp;
			}
		}

		return -1.0;
	}
};
