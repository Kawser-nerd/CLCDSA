#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <functional>
#include <algorithm>

using namespace std;

#define rep(i,j) REP((i), 0, (j))
#define REP(i,j,k) for(int i=(j);(i)<(k);++i)
#define BW(a,x,b) ((a)<=(x)&&(x)<=(b))
#define ALL(v) (v).begin(), (v).end()
#define LENGTHOF(x) (sizeof(x) / sizeof(*(x)))
#define AFILL(a, b) fill((int*)a, (int*)(a + LENGTHOF(a)), b)
#define SQ(x) ((x)*(x))
#define Mod(x, mod) (((x)+(mod)%(mod))
#define MP make_pair
#define PB push_back
#define Fi first
#define Se second
#define INF (1LL<<62)
#define EPS 1e-10
#define MOD 1000000007

typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef vector<int> vi;
typedef queue<int> qi;
typedef long long ll;

const int MAX_N = 1<<17;

int n;
ll dat[2 * MAX_N - 1];

void init(int n_){
  n = 1;
  while(n < n_) n *= 2;
  for (int i=0;i< 2 * n -1; i++) dat[i] = -INF;
}

void update(int k, ll a){
  k += n - 1;
  dat[k] = a;
  while(k > 0){
    k = (k - 1) / 2;
    dat[k] = max(dat[k*2+1], dat[k*2+2]);
  }
}

ll query(int a, int b, int k, int l, int r){
  if (r <= a || b <= l) return -INF;
  if (a <=  l && r <= b) return dat[k];
  else{
    ll vl = query(a, b, k*2+1, l, (l + r) / 2);
    ll vr = query(a, b, k*2+2, (l + r) / 2, r);
    return max(vl, vr);
  }
}

int N;
ll C;
ll x[100005];
ll v[100005];

int main()
{
  cin >> N >> C;

  rep(i, N){
    cin >> x[i] >> v[i];
  }

  ll res = 0;
  init(N);
  ll sv = 0;
  
  rep(i, N){
    sv += v[i];
    update(i, sv - x[i]);
  }
  sv = 0;
  rep(i, N){
    sv += v[N - i - 1];
    ll d = C - x[N-i-1];
    res = max(res, max(query(0, N - i - 1, 0, 0, n)- d, 0LL) + sv - d);
    //    cout << i << " " << max(query(0, N - i - 1, 0, 0, n) - d, 0LL) << " " << sv << " " <<  d << endl;
  }

  sv = 0;  
  rep(i, N){
    sv += v[N-i-1];
    update(i, sv - (C - x[N-i-1]));
  }
  sv = 0;
  rep(i, N){
    sv += v[i];
    ll d = x[i];
    res = max(res, max(query(0, N - i - 1, 0, 0, n) - d, 0LL) + sv - d);
    //    cout << i << " " << max(query(0, N - i - 1, 0, 0, n) - d, 0LL) << " " << sv << " " <<  d << endl;
  }

  cout << res << endl;
  return 0;
}