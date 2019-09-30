#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> X(M);
	for (int i = 0; i < M; ++i) cin >> X[i];
	sort(X.begin(), X.end());
	vector<int> L;
	for (int i = 1; i < M; ++i) L.push_back(X[i] - X[i - 1]);
	sort(L.begin(), L.end());
	int ans = 0;
	for (int i = 0; i < M - N; ++i) ans += L[i];
	cout << ans << endl;
	return 0;
}