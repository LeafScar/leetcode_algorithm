
#include <map>
#include <algorithm>
using namespace std;

class MyCalendarThree {
public:
	map<int, int> m;
	MyCalendarThree() {
	}

	int book(int start, int end) {
		m[start]++;
		m[end]--;
		int maximum = 0; int sum = 0;
		for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
			sum += it->second;
			maximum = max(maximum, sum);
		}
		return maximum;
	}
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree obj = new MyCalendarThree();
 * int param_1 = obj.book(start,end);
 */