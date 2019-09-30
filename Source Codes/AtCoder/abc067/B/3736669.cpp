#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N, K;
	int L[60];
	int res = 0;

	cin >> N >> K;
	for  (int i = 0; i < N; ++i) cin >> L[i];

	sort(L, L + N, greater<int>());

	for (int i = 0; i < K; ++i) res += L[i];
	
	cout << res << endl;
}