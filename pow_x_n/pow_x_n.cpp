class Solution {
public:
	static double myPow(double x, int n) {
		if (n == 0 || x == 0)
			return 1.0;

		if (n == -2147483648)
			return myPow(x, n + 1) / x;

		if (n < 0)
			return 1.0 / myPow(x, -n);

		double temp = myPow(x, n / 2);
		return n % 2 == 0 ? temp * temp : x * temp * temp;
	}
};
