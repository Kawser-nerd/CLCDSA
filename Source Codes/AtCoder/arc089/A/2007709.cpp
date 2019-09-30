#include<iostream>
#include<algorithm>
using namespace std;

int abs_x(int x) {
	if (x < 0) {
		x = -x;
	}
	return x;
}

int main() {
	int N;
	int ct,cx,cy, nt, nx, ny, dd, dt;
	bool ans = true;
	cin >> N;
	ct = cx = cy = 0;
	for (int i = 0; i < N; i++) {
		cin >> nt >> nx >> ny;
		dd = abs_x(nx - cx) + abs_x(ny - cy);
		dt = nt - ct;
		if (dt < dd || (dd-dt)%2!=0) {
			ans = false;
			break;
		}
		else {
			ct = nt;
			cx = nx;
			cy = ny;
		}
	}
	if (ans) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}