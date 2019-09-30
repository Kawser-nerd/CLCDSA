#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <unordered_map>
#include <cassert>
#include <unordered_set>
#include <cmath>
#include <cstring>
#include <deque>
#include <math.h>
#include <stack>
#include <iomanip>
 
using namespace std;
 
#define ll long long
#define ld long double


int a[100100];


int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}


int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	int g = a[1];
	int maxim = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		g = gcd(g, a[i]);
		maxim = max(maxim, a[i]);
	}
	if (k % g == 0 && k <= maxim) {
		puts("POSSIBLE");
	} else {
		puts("IMPOSSIBLE");
	}
    return 0;
}