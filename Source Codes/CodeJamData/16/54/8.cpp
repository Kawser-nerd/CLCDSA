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
const int MAXN = 105;
const int P = 1e9+7;

string s1, s2;
char g[MAXN][MAXN];
char b[MAXN];

int main(){
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int T, i0;
	scanf("%d", &T);
	for(i0 = 1; i0 <= T; i0++){
		int n, l;
		int i, j, k;
		scanf("%d%d", &n, &l);
		for(i = 0; i < n; i++)
			scanf("%s", g[i]);
		scanf("%s", b);
		for(i = 0; i < n; i++)
			if(strcmp(b, g[i]) == 0)
				break;
		if(i < n){
			printf("Case #%d: IMPOSSIBLE\n", i0);
			continue;
		}
		s1.clear();
		s2.clear();
		for(i = 0; i < l; i++){
			if(b[i] == '0'){
				s1.pb('1');
			}
			else{
				s1.pb('0');
			}
			s1.pb('?');
		}
		for(i = 0; i < l-1; i++){
			if(b[i] == '0'){
				s2.pb('1');
			}
			s2.pb('0');
			if(b[i] == '1'){
				s2.pb('1');
			}
		}
		if(l == 1){
			s2.pb(g[0][0]);
		}
		printf("Case #%d: %s %s\n", i0, s1.c_str(), s2.c_str());
	}
	return 0;
}
