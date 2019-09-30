#include <iostream>
#include <vector>
using namespace std;

template<typename T>
inline T modp(const T a, const T b) {
  T result = a % b;
  if (result < 0) {
    result += b;
  }
  return result;
}
template<typename T, typename U> inline void makemax(T &res, const U &x) {
  if (x > res) {
    res = x;
  }
}

int C, X, N;

struct Car {
  int startpos, tstart, tend;
  Car(int s, int e, int t) {
    startpos = s;
    tstart = t;
    tend = tstart + modp(e-s, N);
  }

  int pos_at(int tnow) const {
    if (tnow < tstart || tnow > tend) {
      return -1;
    }
    return modp(startpos + tnow - tstart, N);
  }
};

int calc(int tstart, int startpos, const vector<Car> &cars) {
  for (const Car& car : cars) {
    if (car.pos_at(tstart) == startpos) {
      return 0;
    }
  }

  int t = tstart, pos = startpos;
  for (; t<X; ++t) {
    int nextpos = modp(pos-1, N);
    bool ok = true;
    for (const Car& car : cars) {
      if ((car.pos_at(t) == nextpos && t != car.tend) ||
          car.pos_at(t+1) == nextpos) {
        ok = false;
      }
    }
    if (!ok) {
      break;
    }
    pos = nextpos;
  }
  return t - tstart;
}

void solve1() {
  cin >> C >> X >> N;
  vector<Car> cars;
  for (int i=0; i<C; ++i) {
    int s, e, t;
    cin >> s >> e >> t;
    cars.push_back(Car(s-1, e-1, t));
  }
  int ans = 0;
  for (int tstart=0; tstart<X; ++tstart) {
    for (int startpos=0; startpos<N; ++startpos) {
      makemax(ans, calc(tstart, startpos, cars));
    }
  }
  cout << ans << '\n';
}

int main() {
  cin.sync_with_stdio(0);

  int T; cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    cout << "Case #" << tt << ": ";
    solve1();
  }

  return 0;
}
