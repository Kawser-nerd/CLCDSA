#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

const R PI = acos(-1);
const int MAXN = 35;
const int P = 1e9+7;
const int E = 10; //epsilon transfer

char rex[MAXN];
int Next[MAXN][11];
int cnt;

void parse(int head, int tail, char *rex, int len){
//	{
//		char temp = '\0';
//		swap(rex[len], temp);
//		printf("%d %d %s\n", head, tail, rex);
//		swap(rex[len], temp);
//	}
	if(len == 1){
		Next[head][rex[0]-'0'] |= 1<<tail;
	}
	else{
		int pcnt = 0;
		for(int i = 0; i < len; i++){
			if(i != 0 && pcnt == 0 && rex[i] != '*'){
				int mid = cnt++;
				parse(head, mid, rex, i);
				parse(mid, tail, rex+i, len-i);
				return;
			}
			if(rex[i] == '(')
				pcnt++;
			else if(rex[i] == ')')
				pcnt--;
		}
		if(rex[len-1] == '*'){
			int mid = cnt++;
			Next[head][E] |= 1<<tail | 1<<mid;
			parse(mid, head, rex+1, len-3);
		}
		else{
			int pre = 1;
			pcnt = 0;
			for(int i = 1; i < len-1; i++){
				if(rex[i] == '(')
					pcnt++;
				else if(rex[i] == ')')
					pcnt--;
				else if(rex[i] == '|' && pcnt == 0){
					parse(head, tail, rex+pre, i-pre);
					pre = i+1;
				}
			}
			parse(head, tail, rex+pre, len-1-pre);
		}
	}
}

int dig[20];
vector<pair<int, ll> > f[20];

int findNext(int mask, int d){
	int ret = 0;
	for(int i = 0; i < cnt; i++)
		if(1<<i & mask)
			ret |= Next[i][d];
	return ret;
}

ll getAns(ll A, int head, int tail){
	if(A <= 1)
		return 0;
	int i, j, k;
	int cur;
	int n;

	for(i = 0; i < 20; i++){
		dig[i] = A%10;
		A /= 10;
	}
	n = 19;
	while(dig[n] == 0)
		n--;
	n++;

	for(i = 0; i < 20; i++){
		f[i].clear();
	}

	cur = Next[head][E];
	for(i = n-1; i >= 0; i--){
		if(i == n-1){
			for(j = 1; j < dig[i]; j++)
				f[i].pb(mp(findNext(cur, j), 1LL));
		}
		else{
			for(j = 0; j < dig[i]; j++)
				f[i].pb(mp(findNext(cur, j), 1LL));
			for(j = 1; j < 10; j++)
				f[i].pb(mp(findNext(Next[head][E], j), 1LL));
		}
		cur = findNext(cur, dig[i]);
		for(k = 0; k < f[i+1].size(); k++)
			for(j = 0; j < 10; j++)
				f[i].pb(mp(findNext(f[i+1][k].fi, j), f[i+1][k].se));
		sort(f[i].begin(), f[i].end());
		j = 0;
		for(k = 1; k < f[i].size(); k++){
			if(f[i][k].fi != f[i][j].fi){
				j++;
				f[i][j] = f[i][k];
			}
			else
				f[i][j].se += f[i][k].se;
		}
		f[i].resize(j+1);
	}

	ll ret = 0;
	i = 0;
	for(k = 0; k < f[i].size(); k++)
		if(f[i][k].fi & 1<<tail)
			ret += f[i][k].se;
	return ret;
}

int main(){
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int T, i0;
	int n, m;
	int i, j, k;
	int head, tail;

	ll A, B;
	scanf("%d", &T);
	for(i0 = 1; i0 <= T; i0++){

		scanf("%lld%lld%s", &A, &B, rex);
		m = strlen(rex);
		cnt = 0;
		memset(Next, 0, sizeof Next);
		head = cnt++;
		tail = cnt++;

		parse(head, tail, rex, m);

//		printf("%d\n", cnt);
//		for(i = 0; i < cnt; i++){
//			for(j = 0; j < 11; j++)
//				if(Next[i][j] != 0){
//					printf("%2d %2d:", i, j);
//					for(k = 0; k < cnt; k++)
//						if(1<<k & Next[i][j])
//							printf(" %d", k);
//					printf("\n");
//				}
//
//		}

		for(i = 0; i < cnt; i++)
			Next[i][E] |= 1<<i;
		for(int ii = 0; ii < cnt; ii++)
			for(i = 0; i < cnt; i++)
				for(j = 0; j < 11; j++)
					for(k = 0; k < cnt; k++)
						if(1<<k & Next[i][j])
							Next[i][j] |= Next[k][E];
		ll x = getAns(B+1, head, tail);
		ll y = getAns(A, head, tail);
		//printf("%lld %lld\n", x, y);
		ll ans = x - y;

		printf("Case #%d: %lld\n", i0, ans);
	}
	return 0;
}
