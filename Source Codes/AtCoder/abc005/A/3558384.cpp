#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define FOR(i, m, k) for(int i = m; i < k; ++i)
#define REP(i, k) for(int i = 0; i < k; ++i)

int main() {
	int x, y;
	cin >> x >> y;

	cout << floor(y / x) << endl;


	system("pause");
	return 0;
}