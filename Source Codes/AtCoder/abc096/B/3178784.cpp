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
	int k;
	vector<int> m(3);
	REP(i, 3){
		cin >> m[i];
	}
	cin >> k;
	sort(m.begin(), m.end());
	REP(i, k){
		m[2] *= 2;
	}
	cout << m[0] + m[1] + m[2] << endl;
}