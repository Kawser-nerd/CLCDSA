#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long long M, F, N;
vector<pair<long long, long long> > PS;

long double costld(long long nd) {
  long double ret = F;
  for (long long d = 0, i = 0; d < nd && ret <= M; i++) {
    if (i >= PS.size()) {
      ret += (long double)(nd-d)*(M+1);
      d = nd;
    } else if (PS[i].second >= d) {
      long long d2 = min(PS[i].second+1, nd);
      ret += (long double)(d2-d)*PS[i].first;
      d = d2;
    }
  }
  return ret;
}

long long cost(long long nd) {
  long long ret = F;
  for (long long d = 0, i = 0; d < nd && ret <= M; i++) {
    if (i >= PS.size()) {
      ret += (nd-d)*(M+1);
      d = nd;
    } else if (PS[i].second >= d) {
      long long d2 = min(PS[i].second+1, nd);
      ret += (d2-d)*PS[i].first;
      d = d2;
    }
  }
  return ret;
}

main() {
  long long T, prob=1;
  for (cin >> T; T--;) {
    cin >> M >> F >> N;
    PS.resize(N);
    for (int i = 0; i < N; i++) cin >> PS[i].first >> PS[i].second;
    sort(PS.begin(), PS.end());
    long long dlo = 0, dhi = M;
    while (dlo < dhi) {
      long long d = (dlo+dhi+1)/2;
      long long tlo = 1, thi = d;
      while (tlo < thi) {
        long long t1 = (2*tlo+thi)/3;
        long long t2 = (tlo+2*thi+1)/3;
        long double c1 = costld(d/t1)*(t1-d%t1) + costld(d/t1+1)*(d%t1);
        long double c2 = costld(d/t2)*(t2-d%t2) + costld(d/t2+1)*(d%t2);
//cout << "tlo=" << tlo << " thi=" << thi << endl;
//cout << d << ' ' << t1 << ' ' << c1 << endl;
//cout << d << ' ' << t2 << ' ' << c2 << endl;
        if (c1 < 2*M && c2 < 2*M) {
          long long cc1 = cost(d/t1)*(t1-d%t1) + cost(d/t1+1)*(d%t1);
          long long cc2 = cost(d/t2)*(t2-d%t2) + cost(d/t2+1)*(d%t2);
          if (cc1 < cc2) thi = t2-1; else tlo = t1+1;
        } else {
          if (c1 < c2) thi = t2-1; else tlo = t1+1;
        }
      }
      long double cd = costld(d/tlo)*(tlo-d%tlo) + costld(d/tlo+1)*(d%tlo);
//cout << "tlo=" << tlo << " thi=" << thi << endl;
//cout << "cost for " << d << ": " << cd << endl;
      if (cd < 2*M) {
        long long c = cost(d/tlo)*(tlo-d%tlo) + cost(d/tlo+1)*(d%tlo);
        if (c <= M) {
          dlo = d;
        } else {
          dhi = d-1;
        }
      } else {
        dhi = d-1;
      }
    }
    cout << "Case #" << prob++ << ": " << dlo << endl;
  }
}
