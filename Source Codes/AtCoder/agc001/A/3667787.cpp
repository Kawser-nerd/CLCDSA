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
const int MXN = 10010;

int n,
	a[MXN];

int main() {
	//freopen("template.in", "r", stdin);
	//freopen("template.out", "w", stdout);
	REG int i, ans1=0, ans2=0;
	
	scanf("%d", &n); n <<= 1;
	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	std::sort(a+1, a+n+1);
	for(i = 1; i <= n; i += 2)
	    ans1 += std::min(a[i], a[i+1]);
	for(i = 2; i < n; i += 2)
		ans2 += std::min(a[i], a[i+1]);
	ans2 += a[1];
	printf("%d\n", std::max(ans1, ans2));
	
	return 0;
} ./Main.cpp:20:2: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        REG int i, ans1=0, ans2=0;
        ^~~~
./Main.cpp:7:13: note: expanded from macro 'REG'
#define REG register
            ^
./Main.cpp:20:2: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        REG int i, ans1=0, ans2=0;
        ^~~~
./Main.cpp:7:13: note: expanded from macro 'REG'
#define REG register
            ^
./Main.cpp:20:2: warning: 'register' storage class specifier is deprecated and incompatible with C++1z [-Wdeprecated-register]
        REG int i, ans1=0, ans2=0;
        ^~~~
./Main.cpp:7:13: note: expanded from macro 'REG'
#define REG register
            ^
3 warnings generated.