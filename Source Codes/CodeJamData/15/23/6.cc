#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>
using namespace std;

template<typename T> T Gcd(const T& a, const T& b) {
  return b != T() ? Gcd(b, a%b) : abs(a);
}

template<typename T = long long> struct Fract {
  T n, d;
  Fract(const T& n=0) : n(n), d(1) {}
  Fract(const T& n, const T& d, bool reduce=true) : n(n), d(d) {if (reduce) Reduce();}
  void Reduce() {if (d < 0) {n = -n; d = -d;} T g = Gcd(n, d); if (g != 1) {n /= g; d /= g;}}
  Fract operator+(const Fract& f) const {return Fract(n*f.d+f.n*d, d*f.d);}
  Fract& operator+=(const Fract& f) {n = n*f.d+f.n*d; d *= f.d; Reduce(); return *this;}
  Fract operator-(const Fract& f) const {return Fract(n*f.d-f.n*d, d*f.d);}
  Fract& operator-=(const Fract& f) {n = n*f.d-f.n*d; d *= f.d; Reduce(); return *this;}
  Fract operator-() const {return Fract(-n, d, false);}
  Fract operator*(const Fract& f) const {return Fract(n*f.n, d*f.d);}
  Fract& operator*=(const Fract& f) {n *= f.n; d *= f.d; Reduce(); return *this;}
  Fract operator/(const Fract& f) const {return Fract(n*f.d, d*f.n);}
  Fract& operator/=(const Fract& f) {n *= f.d; d *= f.n; Reduce(); return *this;}
  bool operator<(const Fract& f) const {return n*f.d < d*f.n;}
  bool operator<=(const Fract& f) const {return n*f.d <= d*f.n;}
  bool operator>(const Fract& f) const {return n*f.d > d*f.n;}
  bool operator>=(const Fract& f) const {return n*f.d >= d*f.n;}
  bool operator==(const Fract& f) const {return n == f.n && d == f.d;}
  bool operator!=(const Fract& f) const {return n != f.n || d != f.d;}
  double todouble() const {return (double)n/(double)d;}
  friend Fract abs(const Fract& f) {return Fract(abs(f.n), f.d, false);}
  friend ostream& operator<<(ostream& out, const Fract& f) {out << f.n; if (f.d != 1) out << '/' << f.d; return out;}
};

main() {
  int T, N, D, H, M, prob=1;
  for (cin >> T; T--;) {
    int tot = 0;
    cin >> N;
    priority_queue<pair<Fract<>, pair<int, int> > > q;
    for (int i = 0; i < N; i++) {
      cin >> D >> H >> M;
      tot += H;
      for (int j = 0; j < H; j++) {
        q.push(make_pair(-Fract<>((360LL-D)*(M+j), 360LL), make_pair(-1, M+j)));
      }
    }
    int ret = tot, cur = tot;
    while (cur < 2*tot) {
      Fract<> f = -q.top().first;
      cur += q.top().second.first;
      M = q.top().second.second;
//cout << f << "  " << cur << ' ' << M << endl;
      q.pop();
      q.push(make_pair(-f - M, make_pair(1, M)));
      if (-f != q.top().first) ret = min(ret, cur);
    }
    cout << "Case #" << prob++ << ": " << ret << endl;
  }
}
