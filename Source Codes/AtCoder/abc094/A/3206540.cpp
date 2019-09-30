#include <stdio.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string.h>
#include <cstring>
#include <algorithm>
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
	int a, b, x;
	cin >> a >> b >> x;
	if (x >= a && (x - a) <= b) cout << "YES" << "\n";
	else cout << "NO" << "\n";
}