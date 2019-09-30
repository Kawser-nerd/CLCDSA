#include<set>
#include<map>
#include<cmath>
#include<ctime>
#include<queue>
#include<cstdio>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define pb push_back
#define lowbit(x) x&(-x)
#define PII  pair<int, int> 
#define all(x) x.begin(), x.end()
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int mod = (int)1e9 + 7;
const int maxn = (int)150000 + 5;
using namespace std;

int s[505][505];

int main()
{
	int n, m, q; scanf("%d %d %d", &n, &m, &q);
	int l, r;
	for(int i = 1; i <= m; i++){
		scanf("%d %d", &l, &r);
		s[l][r]++;
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			s[i][j] += s[i-1][j] + s[i][j-1] - s[i-1][j-1];
		}
	}
	while(q--){
		scanf("%d %d", &l, &r);
		printf("%d\n", s[r][r] - s[r][l-1] - s[l-1][r] + s[l-1][l-1]);
	}
	return 0;
}