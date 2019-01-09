#include <string>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
public:
bool isMatch(string s, string p) {
	int s_i = 0;
	int p_i = 0;

	vector<int> backNums;
	vector<int> backP_is;
	vector<int> backS_is;
	while (p_i < p.length())
	{
		int num = 0;
		if (p_i + 1 < p.length() && p[p_i + 1] == '*')
		{
			num = isDoubleMatch(s, s_i, p, p_i);
			p_i = p_i + 2;
			if (num > 0)
			{
				backNums.push_back(num);
				backP_is.push_back(p_i);
				backS_is.push_back(s_i);
			}
		}
		else
		{
			num = isSimpleMatch(s, s_i, p, p_i);
			p_i++;
		}
		if (num < 0)
		{
			if (backNums.empty())
				return false;

			if (backNums.empty())
				return false;

			backNums[backNums.size() - 1]--;
			p_i = backP_is[backNums.size() - 1];
			s_i = backS_is[backNums.size() - 1] + backNums[backNums.size() - 1];

			if (backNums[backNums.size() - 1] == 0)
			{
				backNums.pop_back();
				backP_is.pop_back();
				backS_is.pop_back();
			}
		}
		else
			s_i = s_i + num;
	}
	return  s_i >= s.length();
}

	// ����ƥ��ĸ�����ƥ����󷵻�-1
	/* 
	 * 1.���ַ��������'.'��'*'�ַ�
	 * 2.���ַ���'.'
	 * 3.˫�ַ��������'.'�ַ�+'*'
	 * 4.˫�ַ���".*"
	 */ 
	int isSimpleMatch(string& s, int s_i, string& p, int p_i)
	{
		if (s_i >= s.length())
			return -1;

		// ���1
		if (p[p_i] != '.')
			return s[s_i] == p[p_i] ? 1 : -1;
		// ���2
		else
			return 1;
	}

	int isDoubleMatch(string& s, int s_i, string& p, int p_i)
	{
		// ���3
		if (p[p_i] != '.')
		{
			int num = 0;
			for (int i = s_i; i < s.length(); ++i)
			{
				if (s[i] == p[p_i])
					num++;
				else
					break;
			}
			return num;
		}
		// ���4����Ϊ".*"
		else
			return s.length() - s_i;
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

string boolToString(bool input) {
	return input ? "True" : "False";
}

int main() {
	string line;
	while (getline(cin, line)) {
		string s = stringToString(line);
		getline(cin, line);
		string p = stringToString(line);

		bool ret = Solution().isMatch(s, p);

		string out = boolToString(ret);
		cout << out << endl;
	}
	return 0;
}