#include <iostream>
#include <cstdio>
using namespace std;
int a[100005];
int main() {
	int k;
	cin >> k;
	for (int i = 1; i <= k; i++) 	{
		cin >> a[i];
	}
	long long mmax = 2, mmin = 2;
	for (int i = k; i >= 1 && mmax >= mmin; i--)	{
		if (mmin%a[i] != 0)			mmin = mmin / a[i] * a[i] + a[i];
		mmax = (mmax / a[i] + 1)*a[i] - 1;
	}
	if (mmax >= mmin)		cout << mmin << ' ' << mmax << endl;
	else		cout << -1 << endl;
	return 0;
}