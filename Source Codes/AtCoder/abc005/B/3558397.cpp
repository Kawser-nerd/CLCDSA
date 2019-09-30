#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define FOR(i, m, k) for(int i = m; i < k; ++i)
#define REP(i, k) for(int i = 0; i < k; ++i)

int main() {
	int N;
	cin >> N;
	vector<int> t;
	t.resize(N);
	REP(i, N)cin >> t[i];

	sort(t.begin(), t.end());

	cout << t[0] << endl;



	system("pause");
	return 0;
}