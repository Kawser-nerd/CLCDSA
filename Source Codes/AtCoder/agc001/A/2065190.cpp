#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
 
using namespace std;
 
typedef long long ll;
const int Maxn = 1e9 + 10;
const int N = 1e5 + 10;
const int INF=(0x7fffffff)/2;
int a[210];
 
int main(){
	int n;
	while(~scanf("%d", &n)){
		for(int i = 0; i < 2 * n; i++)
			cin >> a[i];
		sort(a, a + 2 * n);
		ll sum = 0;
		for(int i = 0; i < 2 * n; i = i + 2)
			sum += a[i];
		printf("%lld\n", sum);
		}
}