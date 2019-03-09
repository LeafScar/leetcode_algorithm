#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minMoves2(vector<int>& nums) {
		int mid = nums.size() / 2;
		int result = 0;
		nth_element(nums.begin(), nums.begin() + mid, nums.end());
		for (size_t i = 0; i < nums.size(); ++i)
			result += abs(nums[i] - nums[mid]);

		return result;
	}
};
