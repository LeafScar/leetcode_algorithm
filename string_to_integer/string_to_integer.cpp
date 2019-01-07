#include <string>
#include <iostream>
#include <cassert>
using namespace std;
class Solution {
public:
	int myAtoi(string str) 
	{
		int rel = 0;
		int flag = 1;
		bool addFlag = false;
		bool subFlag = false;
		bool whiteFlag = false;
		bool numFlag = false;

		for (size_t i = 0; i < str.length(); ++i)
		{
			if (str[i] == ' ')
			{
				if (whiteFlag || numFlag)
					return rel;

				continue;
			}

			if (str[i] == '+')
			{
				if (subFlag || numFlag)
					return rel;

				addFlag = true;
				whiteFlag = true;
				continue;
			}

			if (str[i] == '-')
			{
				if (addFlag || numFlag)
					return rel;

				flag = -flag;
				subFlag = true;
				whiteFlag = true;
				continue;
			}

			if (str[i] < '0' || str[i] > '9')
				break;

			whiteFlag = true;

			if (flag == -1 && rel > 0)
				rel = -rel;

			numFlag = true;

			if (rel > 2147483647 / 10 || (rel == 2147483647 / 10 && str[i] - '0' > 7))
			{
				rel = 2147483647;
				break;
			}

			if (rel < (-2147483647 - 1) / 10 || (rel == (-2147483647 - 1) / 10 && str[i] - '0' > 8))
			{
				rel = -2147483647 - 1;
				break;
			}

			rel = rel * 10 + (str[i] - '0') * flag;
		}
		return rel;
	}
};

string stringToString(string input) {
	assert(input.length() >= 2);
	string result;
	for (int i = 1; i < input.length() - 1; i++) {
		char currentChar = input[i];
		if (input[i] == '\\') {
			char nextChar = input[i + 1];
			switch (nextChar) {
			case '\"': result.push_back('\"'); break;
			case '/': result.push_back('/'); break;
			case '\\': result.push_back('\\'); break;
			case 'b': result.push_back('\b'); break;
			case 'f': result.push_back('\f'); break;
			case 'r': result.push_back('\r'); break;
			case 'n': result.push_back('\n'); break;
			case 't': result.push_back('\t'); break;
			default: break;
			}
			i++;
		}
		else {
			result.push_back(currentChar);
		}
	}
	return result;
}

int main() {
	string line;
	while (getline(cin, line)) {
		string str = stringToString(line);

		int ret = Solution().myAtoi(str);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}
