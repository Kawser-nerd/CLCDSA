#include <stdio.h>
#include <algorithm>
#include <queue>
#include <cctype>
using namespace std; 
#define Maxn 500009
#define rep(i, a, b) for(register int i = (a), i##_end_ = (b); i <= i##_end_ ; ++i)
#define drep(i, a, b) for(register int i = (a), i##_end_ = (b); i >= i##_end_ ; --i)
typedef long long LL;
int read() {
	int x = 0;
	char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) {
		x = x * 0xA + ch - 0x30;
		ch = getchar();
	}
	return x;
}

struct node {
	int a, b, c;
	int operator < (const node &x) const {
		return (a - b) < (x.a - x.b);
	}
}f[Maxn];
priority_queue<LL, vector<LL>, greater<LL> >q; 
LL ans, sum, base, lef[Maxn<<2];
int X, Y, Z, n;
int main() {
	X = read(); Y = read(); Z = read(); n = X + Y + Z;
	rep(i, 1, n) {
		f[i].a = read();
		f[i].b = read();
		f[i].c = read();
		base += f[i].c;
	}
	sort(f + 1, f + n + 1); 
	rep(i, 1, Y) {
		sum += f[i].b - f[i].c;
		q.push(f[i].b - f[i].c);
	}
	rep(i, Y + 1, n - X + 1) {
		lef[i] = sum;
		sum += f[i].b - f[i].c;
		q.push(f[i].b - f[i].c);
		sum -= q.top();
		q.pop();
	}

	while(!q.empty()) q.pop(); 
	sum = 0;
	drep(i, n, n - X + 1) {
		sum += f[i].a - f[i].c;
		q.push(f[i].a - f[i].c);
	}
	drep(i, n - X, Y) {
		ans = max(ans, base + lef[i + 1] + sum);
		sum += f[i].a - f[i].c;
		q.push(f[i].a - f[i].c);
		sum-= q.top();
		q.pop();
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.cpp:32:2: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        rep(i, 1, n) {
        ^
./Main.cpp:7:26: note: expanded from macro 'rep'
#define rep(i, a, b) for(register int i = (a), i##_end_ = (b); i <= i##_end_ ; ++i)
                         ^
./Main.cpp:32:2: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
./Main.cpp:7:26: note: expanded from macro 'rep'
#define rep(i, a, b) for(register int i = (a), i##_end_ = (b); i <= i##_end_ ; ++i)
                         ^
./Main.cpp:39:2: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        rep(i, 1, Y) {
        ^
./Main.cpp:7:26: note: expanded from macro 'rep'
#define rep(i, a, b) for(register int i = (a), i##_end_ = (b); i <= i##_end_ ; ++i)
                         ^
./Main.cpp:39:2: warning: 'register' storage class specifier is deprecated and incompatible with ...