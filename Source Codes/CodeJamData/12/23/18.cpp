#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <iostream>

using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

#define maxn 510

int T;
int n;
ll a[maxn];

pll reserva[100000000];

map <ll, ll> mlast;
vector <pll> last;

void out(vector <ll> seq) {
	for (int i = 0; i < sz(seq); i++) {
		printf("%lld%c", seq[i], " \n"[i + 1 == sz(seq)]);
	}
}
void out(ll x) {
	vector <ll> seq;
	while (x) {
		seq.pb(mlast[x]);
		x -= mlast[x];
	}
	out(seq);
}
void out(ll x, ll a) {
	vector <ll> seq;
	seq.pb(a);
	while (x) {
		seq.pb(mlast[x]);
		x -= mlast[x];
	}
	out(seq);
}

const int QQ = 1000000;

void merge(int K) {
  int n = sz(last);
  for (int i = 0; i < n; i++) {
    reserva[i] = last[i];
  }
  int i = 0, j = K;
  while (i < K || j < n) {
    if (i < K && (j == n || reserva[i].x <= reserva[j].x)) {
      last[i + j - K] = reserva[i];
      i++;
    } else {
      last[i + j - K] = reserva[j];
      j++;
    }
  }
}

void prepare(ll b) {
  for (int i = 0; i < sz(last); i++) {
    if (last[i].y != b)
      mlast[last[i].x] = last[i].y;
  }
}

int main() {
  scanf("%d", &T);
  for (int q = 1; q <= T; q++) {
  	scanf("%d", &n);
  	for (int i = 0; i < n; i++) {
  		scanf("%lld", &a[i]);
  	}

  	random_shuffle(a, a + n);
  	last.pb(pll(0, 0));

  	printf("Case #%d:\n", q);
  	int f = 0;
  	for (int i = 0; !f && i < n; i++) {
      debug("iteration %d, size %d\n", i + 1, sz(last));

      int K = sz(last);
      for (int j = 0; j < K; j++) {
        last.pb(pll(last[j].x + a[i], a[i]));
      }
      merge(K);
      if (sz(last) > QQ) last.resize(QQ);
      // sort(all(last));
      for (int j = 1; j < sz(last); j++) {
        if (last[j - 1].x == last[j].x) {
          debug("FOUND\n");
          prepare(a[i]);
          // if (last[j].y == a[i]) {
          //   swap(last[j], last[j - 1]);
          // }
          out(last[j].x);
          out(last[j].x - a[i], a[i]);

          f = 1;
          break;
        }
      }
  	}
  	last.clear();
    mlast.clear();
  }

  return 0;
}
