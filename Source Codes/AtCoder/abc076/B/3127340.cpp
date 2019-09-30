#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N, K, ans;
	ans = 1;

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		ans = min(ans * 2, ans + K);
	}

	cout << ans << endl;

	return 0;
}