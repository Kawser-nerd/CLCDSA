#include <iostream>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <stack>
#ifndef WIN32
#define Auto "%lld"
#else
#define Auto "%I64d"
#endif
using namespace std;
typedef bool boolean;
const signed int inf = (signed)((1u << 31) - 1);
const signed long long llf = (signed long long)((1ull << 61) - 1);
const double eps = 1e-6;
const int binary_limit = 128;
#define smin(a, b) a = min(a, b)
#define smax(a, b) a = max(a, b)
#define max3(a, b, c) max(a, max(b, c))
#define min3(a, b, c) min(a, min(b, c))
template<typename T>
inline boolean readInteger(T& u){
    char x;
    int aFlag = 1;
    while(!isdigit((x = getchar())) && x != '-' && x != -1);
    if(x == -1) {
        ungetc(x, stdin);    
        return false;
    }
    if(x == '-'){
        x = getchar();
        aFlag = -1;
    }
    for(u = x - '0'; isdigit((x = getchar())); u = (u << 1) + (u << 3) + x - '0');
    ungetc(x, stdin);
    u *= aFlag;
    return true;
}

#define LL long long

int n;
LL a[55];
inline void init() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf(Auto, a + i);
}

LL K = 0;
int id = 0;
LL check() {
	LL ret = 0;
	for(int i = 1; i <= n; i++)
		if(a[i] + K > ret)
			ret = a[i] + K, id = i;
	return ret;
}

inline void solve() {
	LL c;
	while((c = check()) >= n) {
		K += c / n;
		a[id] -= (c / n) * (n + 1);
	}
	printf(Auto, K);
}

int main() {
	init();
	solve();
	return 0;
}