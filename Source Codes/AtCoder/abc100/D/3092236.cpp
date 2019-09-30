#include <iostream>
#include <math.h>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int M, N;
	long long x[1000], y[1000], z[1000];
	long long ans[8][1000];
	long long tmp[8] = { 0 };
	long long max = 0;
	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> x[i] >> y[i] >> z[i];
	}

	for (int i = 0; i < N; i++)
	{
		ans[0][i] = (x[i] + y[i] + z[i]);
	}
	for (int i = 0; i < N; i++)
	{
		ans[1][i] = (x[i] + y[i] - z[i]);
	}
	for (int i = 0; i < N; i++)
	{
		ans[2][i] = (x[i] - y[i] + z[i]);
	}
	for (int i = 0; i < N; i++)
	{
		ans[3][i] = (x[i] - y[i] - z[i]);
	}
	for (int i = 0; i < N; i++)
	{
		ans[4][i] = (-x[i] + y[i] + z[i]);
	}
	for (int i = 0; i < N; i++)
	{
		ans[5][i] = (-x[i] + y[i] - z[i]);
	}
	for (int i = 0; i < N; i++)
	{
		ans[6][i] = (-x[i] - y[i] + z[i]);
	}
	for (int i = 0; i < N; i++)
	{
		ans[7][i] = (-x[i] - y[i] - z[i]);
	}
	
	for (int i = 0; i < 8; i++)
	{
		sort(ans[i], ans[i] + N, greater<long long>());
		//cout <<"p"<< ans[i] << " " << ans[i] + N << ans[i]-(ans[i] + N) << endl;
		for (int j = 0; j < M; j++)
		{
			tmp[i] += ans[i][j];
		}
	}

	for (int i = 0; i < 8; i++)
	{
		if (max < tmp[i])
			max = tmp[i];
	}

	cout << max << endl;

	return 0;
}