#include <iostream>
#include <set>

using namespace std;

int main()
{
	int N;
	set<int> l;
	int legend = 0;

	cin >> N;
	for(int i = 0 ; i < N ; ++i) {
		int c;
		cin >> c;
		if(c >= 3200) {
			++legend;
		} else {
			l.insert(c / 400);
		}
	}

	cout << (l.empty() ? 1 : l.size()) << " " << (l.size() + legend) << endl;
}