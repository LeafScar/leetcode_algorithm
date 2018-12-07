class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		
		int temp = x;
		int num = 0;
		while (temp > 0)
		{
			temp /= 10;
			num++;
		}

		for (int i = 1; i <= num / 2; ++i)
		{
			if (getNum(x, i) != getNum(x, num - i + 1))
				return false;
		}
		return true;
	}

	int getNum(int x, int num)
	{
		for (int i = 1; i < num; ++i)
			x /= 10;

		return x % 10;
	}
};
