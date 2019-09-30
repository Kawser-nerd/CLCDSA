#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 5555;

long long a[maxn][maxn];

const long long inf = -100000000;

int main() {
	int N, M, n, m;
	cin >> N >> M >> n >> m;
	long long nm = n * m;
	long long NM = N * M;
	long long k = (N / n) * (M / m);
	long long opt_l = -1;
	long long opt_x = -1;
	for (long long l = 1; l <= (long long)(1e8); l++) {
		long long X = -l * (nm - 1) - 1;
		if (X < inf)
			break;
		if (k * X + (NM - k) * l > 0) {
			opt_l = l;
			opt_x = X;
			break;
		}
	}
	long long all_sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (i % n == 0 && j % m == 0)
				a[i][j] = opt_x;
			else
				a[i][j] = opt_l;
			all_sum += a[i][j];
		}
	}
	if (opt_l == -1) {
		cout << "No\n";
		return 0;
	}
	if (all_sum > 0) {
		cout << "Yes\n";
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= M; j++) {
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
		return 0;
	}
	cout << "No";
	return 0;
}