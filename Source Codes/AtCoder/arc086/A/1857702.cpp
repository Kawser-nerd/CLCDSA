#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int CNT[200001];

int main()
{
	int N, K; cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int a; cin >> a;
		CNT[a]++;
	}

	vector<int>kind;
	for (int i = 0; i < 200001; i++) {
		if (CNT[i])kind.push_back(CNT[i]);
	}

	sort(kind.begin(), kind.end());

	int ans = 0;
	int i = 0;
	while (kind.size()-i > K) {
		ans += kind[i++];
	}
	cout << ans << endl;

    return 0;
}