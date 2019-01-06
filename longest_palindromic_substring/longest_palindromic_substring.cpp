#include <string>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty())
			return "";
		int maxLen = 0;
		int centerIndex = -1;
		for (int i = 0; i < s.length(); ++i)
		{
			int len1 = CenterExtension(s, i, i);
			int len2 = CenterExtension(s, i, i + 1);
			int tempMaxLen = max(len1, len2);
			if (centerIndex == -1 || maxLen < tempMaxLen)
			{
				maxLen = tempMaxLen;
				centerIndex = i;
			}
		}
		return s.substr(centerIndex - (maxLen - 1) / 2, maxLen);
	}

	int CenterExtension(string s, int left, int right)
	{
		while (left >= 0 && right < s.length() && s[left] == s[right])
		{
			left--;
			right++;
		}
		return right - left - 1;
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
	//while (getline(cin, line)) {
		string s = "cbbd";

		string ret = Solution().longestPalindrome(s);

		string out = (ret);
		cout << out << endl;
	//}
	return 0;
}