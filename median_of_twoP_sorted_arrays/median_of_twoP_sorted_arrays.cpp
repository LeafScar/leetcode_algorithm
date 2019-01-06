#include <vector>
#include <algorithm>
#include <locale>
#include <sstream>
#include <iostream>
using namespace std;
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

		// 找两向量中最中间的一个或两个数
		int k = (nums1.size() + nums2.size() + 1) / 2;
		double fMid = getKth(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, k);
		if ((nums1.size() + nums2.size()) % 2 == 1)
			return fMid;
		else
			return (fMid + getKth(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, k + 1)) / 2;
	}

	double getKth(vector<int>& nums1, int l1, int r1, vector<int>& nums2, int l2,int r2, int k)
	{
		if (l1 > r1)
			return nums2[l2 + k - 1];
		if (l2 > r2)
			return nums1[l1 + k - 1];

		int m1 = l1 + (r1 - l1) / 2;
		int m2 = l2 + (r2 - l2) / 2;

		int halfLen = m1 - l1 + m2 - l2 + 2;
		if (nums1[m1] < nums2[m2])
			if (halfLen > k)
				return getKth(nums1, l1, r1, nums2, l2, m2 - 1, k);
			else
				return getKth(nums1, m1 + 1, r1, nums2, l2, r2, k - (m1 - l1 + 1));
		else
			if (halfLen > k)
				return getKth(nums1, l1, m1 - 1, nums2, l2, r2, k);
			else
				return getKth(nums1, l1, r1, nums2, m2 + 1, r2, k - (m2 - l2 + 1));
	}
};

void trimLeftTrailingSpaces(string &input) {
	input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
		return !isspace(ch);
		}));
}

void trimRightTrailingSpaces(string &input) {
	input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
		return !isspace(ch);
		}).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
	vector<int> output;
	trimLeftTrailingSpaces(input);
	trimRightTrailingSpaces(input);
	input = input.substr(1, input.length() - 2);
	stringstream ss;
	ss.str(input);
	string item;
	char delim = ',';
	while (getline(ss, item, delim)) {
		output.push_back(stoi(item));
	}
	return output;
}

int main() {
	string line;
	while (getline(cin, line)) {
		vector<int> nums1 = stringToIntegerVector(line);
		getline(cin, line);
		vector<int> nums2 = stringToIntegerVector(line);

		double ret = Solution().findMedianSortedArrays(nums1, nums2);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}