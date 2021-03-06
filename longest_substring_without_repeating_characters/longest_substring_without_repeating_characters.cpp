#include <string>
#include <map>
#include <iostream>
#include <cassert>

using namespace std;
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (s.empty())
			return 0;

		map<char, int> rel;
		for (int i = 0; i < s.length(); ++i)
			rel[s[i]] = -1;

		int maxLen = 0;
		// 记录单词开始位置,重复时，删除第一个继续运算
		int start = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			if (rel[s[i]] >= start)
			{
				int len = i - start;
				start = rel[s[i]] + 1;
				if (maxLen < len)
					maxLen = len;
			}
			rel[s[i]] = i;
		}

		// 记录扫描到末尾的最后一段长度，与maxLen比较
		int len = s.length() - start;

		if (maxLen < len)
			maxLen = len;

		return maxLen;
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
		//string s = stringToString(line);
		string s = "cdd";
		int ret = Solution().lengthOfLongestSubstring(s);

		string out = to_string(ret);
		cout << out << endl;
	}
	return 0;
}
