#include <iostream>
#include <algorithm>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, l;
	cin >> n >> l;
	string s[120];
	for (int i = 0; i < n; i++)
		cin >> s[i];
	stable_sort(s, s + n);
	for (int i = 0; i < n; i++)
		cout << s[i];
	cout << endl;
	return 0;
}