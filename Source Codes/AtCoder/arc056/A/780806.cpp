#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>

static const int INF = 1001001001;

using namespace std;

int main() {
 	long long a, b, k, l;
	cin >> a >> b >> k >> l;
	long long res = (k/l)*b + min(b, (k%l)*a);
	cout << res << endl;
	return 0;
}