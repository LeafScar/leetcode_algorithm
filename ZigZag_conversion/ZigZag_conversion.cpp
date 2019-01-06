
#include <string>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (s.empty())
			return "";

		if (numRows == 1)
			return s;
		// 每个Z是3 * numRows - 2
		// 可以将Z看成是V排序，每个V的长度是，2 * numRows - 1
		const int VLen = 2 * numRows - 2;
		const int size = s.length();
		const int numV = size / VLen + 1;
		// 第一行始终是i * VLen;
		// 第numRows行始终是i * VLen + numRows - 1
		// 中间的就是
		int spaceNum = VLen * numV - size;
		vector<string> zstr(numRows, "");
		for (int j = 0; j < numV; ++j)
		{
			int LBIndex = j * VLen;
			if (LBIndex < size)
				zstr[0].push_back(s[LBIndex]);

			int LEIndex = j * VLen + numRows - 1;
			if (LEIndex < size)
				zstr[numRows - 1].push_back(s[j * VLen + numRows - 1]);

			// 基准点为最后一行
			for (int i = 1; i <= numRows - 2; ++i)
			{
				// 第j * VLen + numRows - 1行
				if (LEIndex - i < size)
					zstr[numRows - 1 - i].push_back(s[LEIndex - i]);
				if (LEIndex + i < size)
					zstr[numRows - 1 - i].push_back(s[LEIndex + i]);
			}
		}

		string rel;
		for (int i = 0; i < numRows; ++i)
			rel += zstr[i];

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

int stringToInteger(string input) {
	return stoi(input);
}

int main() {
	string line;
	while (getline(cin, line)) {
		string s = stringToString(line);
		getline(cin, line);
		int numRows = stringToInteger(line);

		string ret = Solution().convert(s, numRows);

		string out = (ret);
		cout << out << endl;
	}
	return 0;
}