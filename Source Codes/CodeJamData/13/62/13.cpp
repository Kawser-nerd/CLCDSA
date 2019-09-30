#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <thread>
using namespace std;
vector<long long> T;
double inv[100000];
pair<double, double> d(int x, int y, double E) {
  double dd = T[y] - T[x];
  double dl = inv[y-x];
  //double a = (dd - 2*E) * dl;
  //double b = (dd + 2*E) * dl;
  //if(a > b)
  //  swap(a, b);
  double v = dd * dl;
  double e = 2 * E * dl;
  //cerr << a << "  "<< (v-e) << " " << b << " " << (v+e) << endl;
  return make_pair(v-e, v+e);
}

void f(unsigned i, double E, pair<double, double>* m) {
  for(unsigned j = i; j < i + 100 && j < T.size(); ++j) {
      for(unsigned k = j+1; k < T.size(); ++k) {
        pair<double, double> i = d(j, k, E);
        m->first = max(m->first, i.first);
        m->second = min(m->second, i.second);
        //cerr << j << " " << k << " " << m.first << " " << m.second << endl;
        //if(m.second < m.first - 1e-9) return;
      }
  }
}
bool  mag(double E) {
    pair<double, double> m = make_pair(0.0, INFINITY);
    unsigned cnt = (T.size() + 99) / 100;
    vector<pair<double, double> > r(cnt, make_pair(0, INFINITY));
    vector<thread> v;
    for(unsigned i = 0; i *100 < T.size(); i ++) {
      v.push_back(thread(f, i*100, E, &r[i]));
      
    }
    /*for(unsigned j = 0; j < T.size(); ++j) 
      for(unsigned k = j+1; k < T.size(); ++k) {
        pair<double, double> i = d(j, k, E);
        m.first = max(m.first, i.first);
        m.second = min(m.second, i.second);
        if(m.second < m.first - 1e-9) return false;
      }*/
    for(unsigned i = 0; i < cnt; ++i) {
      v[i].join();
      //cerr << " " << r[i].first << " " << r[i].second << endl;
      m.first = max(m.first, r[i].first);
      m.second = min(m.second, r[i].second);
      
    }
    //cerr << m.first << " " << m.second << endl;
    return m.first <= m.second + 1e-9;
}

void doit(int casenum) {
  int N;
  cin >> N;
  T.resize(N);
  for(unsigned i = 0; i < N; ++i)
    cin >> T[i];
  double r = (T.back() - T.front())/ (T.size() - 1);
  
  double lo = 0.0;
  double hi = 0;
  for(unsigned i = 0; i < N; ++i)
    hi = max(hi, abs(T[i] - (T[0] + i * r)));
  unsigned cnt = 0;
  while(hi - lo > 5e-7) {
    double mid = (lo + hi) / 2;
    (mag(mid) ? hi : lo) = mid;
    ++cnt;
    //cerr << "iter " << cnt << " " << (hi-lo) <<  endl;
  }
  cout.precision(8);
  cout << "Case #" << casenum << ": " << hi << endl;
}
int main(int argc, char **argv) {
  for(unsigned i = 1; i < 100000; ++i)
    inv[i] = 1.0/i;
    int T;
    cin >> T;
    for(int i = 1; i <= T; ++i)
      doit(i);
    return 0;
}
