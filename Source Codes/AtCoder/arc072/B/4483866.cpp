#include <iostream>
#include <cmath>
#define int long long
using namespace std;
signed main() {
	int x, y; cin >> x >> y;
	cout << (abs(x - y) <= 1 ? "Brown\n" : "Alice\n");
}