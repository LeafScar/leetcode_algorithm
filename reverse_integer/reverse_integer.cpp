#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
	int reverse(int x) {
		//int x = x < 0 ? -x : x;
		int rel = 0;
		while (x!= 0)
		{
			int temp = x % 10;
			x = x / 10;
			if (rel > 2147483647 / 10 || (rel == 2147483647 / 10 && temp > 7))
				return 0;
			if (rel < (-2147483647 - 1) / 10 || (rel == (-2147483647 - 1) / 10 && temp < -8))
				return 0;

			rel = rel * 10 + temp;
		}
		return rel;
	}
};

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		int x = stringToInteger(line);

		int ret = Solution().reverse(x);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}