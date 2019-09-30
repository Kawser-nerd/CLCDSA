#include<iostream>
#include<cmath>
using namespace std;
double f(double x1, double y1, double x2, double y2) {
	return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}
double sx, sy, gx, gy, t, v, x, y;
bool f1() {
	return (f(sx, sy, x, y) + f(x, y, gx, gy)) <= t*v;
}
int main() {
	cin >> sx >> sy >> gx >> gy >> t >> v;
	bool b = false;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if (f1())b = true;
	}
	cout << (b ? "YES\n" : "NO\n");
	return 0;
}