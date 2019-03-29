#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Solution {
public:
	int thirdMax(vector<int>& nums) {
		int index = -1;
		map<int, int> temp;
		for (size_t i = 0; i < nums.size(); i++)
		{
			temp[nums[i]] = 0;
			if (temp.size() == 3)
			{
				index = i + 1;
				break;
			}
		}
		if (temp.size() < 3)
			return (*--temp.end()).first;

		int first = (*--temp.end()).first;
		int second = (*(----temp.end())).first;
		int third = (*(temp.begin())).first;
		for (int i = index; i < nums.size(); ++i)
		{
			if (nums[i] < third)
				continue;

			if (nums[i] > third &&  nums[i] < second)
				third = nums[i];

			if (nums[i] > second &&  nums[i] < first)
			{
				third = second;
				second = nums[i];
			}

			if (nums[i] > first)
			{
				third = second;
				second = first;
				first = nums[i];
			}
		}
		return third;
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
		vector<int> nums = stringToIntegerVector(line);

		int ret = Solution().thirdMax(nums);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}