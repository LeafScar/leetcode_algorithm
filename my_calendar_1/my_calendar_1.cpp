#include <vector>

using namespace std;

class MyCalendar {
public:
    MyCalendar() {
    }

	vector<pair<int, int>> books;
    
    bool book(int start, int end) 
	{
		for (size_t i = 0; i < books.size(); i++)
		{
			if (!(start >= this->books[i].second || end <= this->books[i].first))
				return false;
		}
		this->books.push_back(pair<int, int>(start, end));
		return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */