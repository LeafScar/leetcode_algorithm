#include <string>
#include <set>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		set<char> rel;
		int maxLen = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			if (rel.find(s[i]) == rel.end())
				rel.insert(s[i]);
			else
			{
				if (maxLen < rel.size())
					maxLen = rel.size();

				rel.clear();
				rel.insert(s[i]);
			}
		}
		return maxLen;
	}
};
