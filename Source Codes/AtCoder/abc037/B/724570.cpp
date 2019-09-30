#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, Q;
	cin >> N >> Q;
	vector<int> a(N, 0);

	int L, R, T;
	for (int q = 0; q < Q; ++q) {
		cin >> L >> R >> T;
		--L;
		--R;
		for (int i = L; i <= R; ++i) {
			a[i] = T;
		}
	}
	for (auto x : a) {
		cout << x << endl;
	}
}