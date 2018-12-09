#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	static vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> rel;
		unordered_map<int, int> hashMap;
		for (int i = 0 ; i < nums.size(); ++i)
			hashMap[nums[i]] = i;

		for (int i = 0; i < nums.size(); ++i)
		{
			int r = target - nums[i];
			if (hashMap.count(r) > 0 && hashMap[r] != i)
			{
				rel.push_back(i);
				rel.push_back(hashMap[r]);
				return rel;
			}
		}
		return rel;
	}
};

