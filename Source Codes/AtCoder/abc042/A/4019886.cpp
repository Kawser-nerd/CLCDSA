#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a, b, c;
	int flag[10];
	memset(flag, 0, sizeof(flag));
	cin >> a >> b >> c;
	flag[a]++;
	flag[b]++;
	flag[c]++;
	if (flag[5] == 2 && flag[7] == 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}