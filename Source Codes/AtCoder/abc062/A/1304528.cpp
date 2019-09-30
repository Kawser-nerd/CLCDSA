#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> g1{1,3,5,7,8,10,12}, g2{4,6,9,11}, g3{2};
	vector<vector<int>> group{g1, g2, g3};
	int x, y;
	cin >> x >> y;
	for(auto g : group) {
		bool include_x = find(g.begin(), g.end(), x) != g.end();
		bool include_y = find(g.begin(), g.end(), y) != g.end();
		if(include_x && include_y) {
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}