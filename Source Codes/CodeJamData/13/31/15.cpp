#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
bool is[256] = { };

typedef long long int64;
const int MAX_N = int(1e6) + 10;
int cnt[MAX_N];
int n, L;

string s;

int64 work() {
	cin >> s >> L;
	n = s.size();
	cnt[n] = 0;
	for (int i = n - 1; i >= 0; --i) {
		cnt[i] = is[s[i]] ? (cnt[i + 1] + 1) : 0;
	}
	int next = n;
	long long ans = 1LL * n * (n + 1) / 2;
	for (int i = n - 1; i >= 0; --i) {
		if (cnt[i] >= L) {
			next = i + L - 1;
		}
		//[i,next)
		ans -= next - i;
	}
	return ans;
}

int main() {
	fill(is, is + 256, true);
	is['a'] = is['i'] = is['o'] = is['u'] = is['e'] = false;
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		cout << work() << endl;
	}
}
