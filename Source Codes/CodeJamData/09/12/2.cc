/* GCJ'09 Template v.1e-9
 * Per Austrin
 */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cassert>
#include <cctype>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
const ll inf = 0x1f1f1f1f1f1f1f1fLL;

int cases;

void init() {
  scanf("%d", &cases);
}

const int dr[4] = {-1,0,1,0};
const int dc[4] = {0,-1,0,1};

int N, M;
ll best[100][100];
ll S[100][100], W[100][100], T[100][100];

void solve(int P) {
  scanf("%d%d", &N, &M);

  for (int i = 0; i < N; ++i)
    for (int j = 0; j < M; ++j)
      scanf("%lld%lld%lld", S[i]+j, W[i]+j, T[i]+j);

  memset(best, 0x1f, sizeof(best));
  best[2*N][1] = 0;
  set< pair<ll, int> > q;
  q.insert(make_pair(0, ((2*N)<<8)|1));
  while (!q.empty()) {
    ll t = q.begin()->first;
    int r = q.begin()->second >> 8;
    int c = q.begin()->second & 0xFF;
    q.erase(q.begin());
    for (int d = 0; d < 4; ++d) {
      int nr = r + dr[d];
      int nc = c + dc[d];
      ll nt = 0;
      if (nr < 1 || nc < 1 || nr > 2*N || nc > 2*M) continue;
      if ((nr/2) == (r/2) && (nc/2) == (c/2)) nt = t + 2;
      else {
	ll s = S[(r-1)/2][(c-1)/2], w = W[(r-1)/2][(c-1)/2];
	ll shift = T[(r-1)/2][(c-1)/2];
	ll period = s+w;
	ll len = s;
	if (d % 2) shift += s, len = w;
	shift = shift % period;
	shift = shift - period;
	ll k = (t - shift + period-1) / period;
	assert(t > shift + (k-1)*period);
	assert(t <= shift + k*period);
	if (t < shift + (k-1)*period + len) nt = t+1;
	else nt = shift+k*period+1;
      }
      if (best[nr][nc] > nt) {
	q.erase(make_pair(best[nr][nc], (nr<<8)|nc));
	q.insert(make_pair(best[nr][nc] = nt, (nr<<8)|nc));
      }
    }
  }

  printf("Case #%d: %lld\n", P, best[1][2*M]);
}

int main(void) {
  init();
  for (int i = 1; i <= cases; ++i) solve(i);
  return 0;
}
