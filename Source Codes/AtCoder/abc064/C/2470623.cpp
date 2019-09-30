// ABC64-C-cpp.cpp : ????????????? ???????????
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> a = vector<int>(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	bool c[8];
	for (size_t i = 0; i < 8; i++)
	{
		c[i] = false;
	}
	int count = 0;
	for (size_t i = 0; i < n; i++)
	{
		if (a[i] < 400) c[0] = true;
		if (400 <= a[i] && a[i] < 800) c[1] = true;
		if (800 <= a[i] && a[i]< 1200) c[2] = true;
		if (1200 <= a[i] && a[i]< 1600) c[3] = true;
		if (1600 <= a[i] && a[i]< 2000) c[4] = true;
		if (2000 <= a[i] && a[i]< 2400) c[5] = true;
		if (2400 <= a[i] && a[i]< 2800) c[6] = true;
		if (2800 <= a[i] && a[i]< 3200) c[7] = true;
		if (3200 <= a[i]) count++;
	}
	int m = 0;
	for (size_t i = 0; i < 8; i++)
	{
		if (c[i]) m++;
	}
	cout << (m > 0 ? m : 1) << " " << m + count << endl;
    return 0;
}