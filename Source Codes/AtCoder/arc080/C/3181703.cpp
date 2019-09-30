#include<cstring>
#include<string>
#include<vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<list>
#include<set>
#include<map>
#include<complex>
#include<sstream>
#include<climits>

#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int MAX_N = 1 << 17;

int n;
pii dat[2*MAX_N-1], dat2[2*MAX_N-1];

void init(int n_) {
  n = 1;
  while (n < n_) n *= 2;
  for (int i = 0; i < 2*n-1; ++i) dat[i] = pii(INT_MAX, INT_MAX);
  for (int i = 0; i < 2*n-1; ++i) dat2[i] = pii(INT_MAX, INT_MAX);
}

void update(int k, int a) {
  k += n-1;
  dat[k].fi = a;
  dat[k].sc = (k-n+1)*2;
  while (k > 0) {
    k = (k-1)/2;
    dat[k] = min(dat[k*2+1], dat[k*2+2]);
  }
}

void update2(int k, int a) {
  k += n-1;
  dat2[k].fi = a;
  dat2[k].sc = (k-n+1)*2 + 1;
  while (k > 0) {
    k = (k-1)/2;
    dat2[k] = min(dat2[k*2+1], dat2[k*2+2]);
  }
}

//range = [a,b), node number = k, node range = [l, r) 
//?????? query(a, b, 0, 0, n);
pii query(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) return pii(INT_MAX, INT_MAX);

  if (a <= l && r <= b) return dat[k];
  else {
    pii v1 = query(a, b, 2*k+1, l, (l+r)/2);
    pii v2 = query(a, b, 2*k+2, (l+r)/2, r);
    return min(v1, v2);
  }
}


pii query2(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) return pii(INT_MAX, INT_MAX);

  if (a <= l && r <= b) return dat2[k];
  else {
    pii v1 = query2(a, b, 2*k+1, l, (l+r)/2);
    pii v2 = query2(a, b, 2*k+2, (l+r)/2, r);
    return min(v1, v2);
  }
}


pii rap_query(int lb, int ub) {
  pii res;
  if (lb%2 == 0 && (ub-lb)%2 == 0) {
    res = query(lb/2, ub/2, 0, 0, n);
  } else if (lb%2 == 0 && (ub-lb)%2 == 1) {
    res = query(lb/2, (ub+1)/2, 0, 0, n);
  } else if (lb%2 == 1 && (ub-lb)%2 == 0) {
    res = query2((lb-1)/2, (ub-1)/2, 0, 0, n);
  } else {
    res = query2((lb-1)/2, ub/2, 0, 0, n);
  }
  return res;
}

int main() {
  int N;
  vector<int> p;
  cin >> N;
  rep(i,N) {
    int tmp;
    cin >> tmp;
    p.push_back(tmp);
  }

  init(N/2);
  for (int i = 0; i < N; i += 2) update(i/2, p[i]);
  for (int i = 1; i < N; i += 2) update2((i-1)/2, p[i]); 

  vector<int> ans;
  map<int, pii> segmap;
  priority_queue<pii, vector<pii> ,greater<pii> > pque;
  pii fmi = query(0, N/2, 0, 0, n);
  pque.push(fmi);
  segmap[fmi.fi] = pii(0, N);
  cerr << "start while loop" << endl;
  cerr << fmi.fi << ' ' << fmi.sc << endl;
  while (!pque.empty()) {
    pii mi1 = pque.top();  pque.pop();
    int lb = segmap[mi1.fi].fi, ub = segmap[mi1.fi].sc;
    pii mi2 = rap_query(mi1.sc+1, ub);

    ans.push_back(mi1.fi); ans.push_back(mi2.fi);
    if (lb != mi1.sc)  {
      pii np = rap_query(lb, mi1.sc);
      pque.push(np); segmap[np.fi] = pii(lb, mi1.sc);
    }
    if (mi1.sc+1 != mi2.sc) {
      pii np = rap_query(mi1.sc+1, mi2.sc);
      pque.push(np); segmap[np.fi] = pii(mi1.sc+1, mi2.sc);
    }
    if (mi2.sc+1 != ub) {
      pii np = rap_query(mi2.sc+1, ub);
      pque.push(np); segmap[np.fi] = pii(mi2.sc+1, ub);
    }

    cerr << mi1.fi << ' ' << mi2.fi << endl;
  }


  for (int i = 0; i < N; ++i) printf("%d%c", ans[i], i+1 != N ? ' ' : '\n');

  return 0;
}