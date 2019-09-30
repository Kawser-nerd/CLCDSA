#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
ll a[114514], b[114514];
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) { cin >> a[i]; b[i] = a[i]; }
	sort(b, b + n);
	map<ll, int> m;
	for (int i = 0; i < n; i++)m[b[i]] = i;
	int ans = 0;
	for (int i = 0; i < n; i++) 
		if (i % 2 != m[a[i]] % 2)ans++;
	cout << ans/2 << endl;
	return 0;
}