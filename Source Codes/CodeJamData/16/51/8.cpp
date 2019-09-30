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
const int MAXN = 1<<20;
const int P = 1e9+7;

char s[MAXN];
char t[MAXN];

int main(){
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int T, i0;
	scanf("%d", &T);
	for(i0 = 1; i0 <= T; i0++){
		int n;
		int m;
		int i, j, k;
		scanf("%s", s);
		n = strlen(s);
		int ans = 0;
		m = 0;
		for(i = 0; i < n; i++){
			if(m && s[i] == t[m-1]){
				ans += 10;
				m--;
			}
			else
				t[m++] = s[i];
		}
		ans += 5 * (m/2);
		printf("Case #%d: %d\n", i0, ans);
	}
	return 0;
}
