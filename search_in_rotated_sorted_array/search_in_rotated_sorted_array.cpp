#include <vector>

class Solution {
public:
	int search(std::vector<int>& nums, int target) {
		int lo = 0;
		int hi = nums.size() - 1;
		int mid = (lo + hi) / 2;

		while (lo <= hi)
		{
			if (nums[mid] == target)
				return mid;

			else if (nums[mid] >= nums[lo])
			{
				if (nums[mid] >= target && target >= nums[lo])
					hi = mid - 1;
				else
					lo = mid + 1;
			}
			else if (nums[mid] < nums[lo])
			{
				if (nums[mid] <= target && target <= nums[hi])
					lo = mid + 1;
				else
					hi = mid - 1;
			}
			mid = (lo + hi) / 2;
		}
		return -1;
	}
};
