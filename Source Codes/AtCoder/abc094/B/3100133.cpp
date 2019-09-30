#include <iostream>
#include <numeric>
using namespace std;
int main() {
	int N, M, X;
	int A[101] = { 0 };

	cin >> N >> M >> X;

	for (int i = 1; i <= M; i++)
	{
		int tmp;
		cin >> tmp;
		A[tmp] = 1;
	}

	int ans1 = accumulate(A, A + X, 0);
	int ans2 = accumulate(A + X, A + N, 0);

	cout << ((ans1 > ans2) ? ans2 : ans1) << endl;

	return 0;
}