#include <stdio.h>
#include <cstdio>
#include <vector>
#include <iostream>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
	int a, b, k;
	cin >> a >> b >> k;
	if ((b - a + 1) < 2 * k){
		FOR(i, a, b+1) cout << i << "\n";
	}else{
		FOR(i, a, a + k) cout << i << "\n";
		FOR(i, b - k + 1, b + 1) cout << i << "\n";
	}
}