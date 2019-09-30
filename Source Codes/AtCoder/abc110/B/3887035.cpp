#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m, x, y; cin >> n >> m >> x >> y;
	
	int max_x = -101;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		max_x = max(max_x, x);
	}

	max_x++;
	bool war_flag = false;
	if(!(x < max_x && max_x <= y)) {
		war_flag = true;
	}

	for(int i = 0; i < m; i++) {
		int y; cin >> y;
		if(y < max_x) {
			war_flag = true;
		}
	}
	if(war_flag) {
		cout << "War\n";
	} else {
		cout << "No War\n";
	}
}