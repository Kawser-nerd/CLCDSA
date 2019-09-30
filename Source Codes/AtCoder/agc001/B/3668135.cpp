#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#define REG register
#define LLI long long
#define DBL double
#define CHR char 
#define BOL bool
const int MOD = 1000000007;
const int MXN = 100010;


int main() {
	//freopen("template.in", "r", stdin);
	//freopen("template.out", "w", stdout);
	REG int i; REG LLI a, b, n, x, ans=0;
	
	scanf("%lld%lld", &n, &x);
	//if(x > n - x) x = n - x;
	if(n % x == 0) {
		ans += 3 * (n - x);
		printf("%lld\n", ans);
		return 0;
	}
	ans = n;
	a = n - x, b = x;
	
	while(a != 0 && b != 0 && a != b) { 
		//printf("%lld %lld\n", a, b);
		if(a < b) std::swap(a, b);
		if(a / b > 1)
			ans += 2 * (a / b - 1) * b, a = a % b + b;
		else
			ans += 2 * b, a -= b;
	}
	if(a == b) ans += a;
	printf("%lld\n", ans);
	
	
	
	return 0;
} ./Main.cpp:19:2: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        REG int i; REG LLI a, b, n, x, ans=0;
        ^~~~
./Main.cpp:7:13: note: expanded from macro 'REG'
#define REG register
            ^
./Main.cpp:19:13: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        REG int i; REG LLI a, b, n, x, ans=0;
                   ^~~~
./Main.cpp:7:13: note: expanded from macro 'REG'
#define REG register
            ^
./Main.cpp:19:13: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        REG int i; REG LLI a, b, n, x, ans=0;
                   ^~~~
./Main.cpp:7:13: note: expanded from macro 'REG'
#define REG register
            ^
./Main.cpp:19:13: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        REG int i; REG LLI a, b, n, x, ans=0;
                ...