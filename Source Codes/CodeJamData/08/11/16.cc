#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
	int n;
	cin >> n;
	vector<long long> a(n), b(n);
	for (int j = 0; j < n; ++j)
	    cin >> a[j];
	for (int j = 0; j < n; ++j)
	    cin >> b[j];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	long long s = 0;
	for (int j = 0; j < n; ++j)
	    s += a[j] * b[n-1-j];
	cout << "Case #" << i << ": " << s << endl;
    }
}
