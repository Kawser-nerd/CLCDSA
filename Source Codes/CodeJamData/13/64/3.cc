#include <iostream>
#include <utility>
#include <vector>
using namespace std;

template<typename T, typename U> inline void makemax(T &res, const U &x) {
  if (x > res) {
    res = x;
  }
}

int N, D, k;
struct RollSet {
  int val[4];
  int next_without[4];

  int where(int x) const {
    for (int i=0; i<D; ++i) {
      if (val[i] == x) {
        return i;
      }
    }
    return -1;
  }
};
vector<RollSet> rolls;

vector<int> xs;
vector<pair<int, int> > num_pos;

void rek(int pos, int &farthest) {
  // debug(pos);
  // debug(xs);

  if ((int)xs.size() == k || pos == N) {
    makemax(farthest, pos-1);
    return;
  }

  for (int j=0; j<D; ++j) {
    xs.push_back(rolls[pos].val[j]);
    int next = pos+1;

    if (next < N) {
      bool progress = true;
      while (progress) {
        progress = false;
        for (int x : xs) {
          int w = rolls[next].where(x);
          if (w != -1) {
            next = rolls[next].next_without[w];
            if (next == N) {
              progress = false;
              break;
            }
            progress = true;
          }
        }
      }
    }
    rek(next, farthest);
    xs.pop_back();
  }
}

void solve1() {
  cin >> N >> D >> k;

  rolls.resize(N);
  num_pos.clear();

  for (int i=0; i<N; ++i) {
    for (int j=0; j<D; ++j) {
      int x;
      cin >> x;
      rolls[i].val[j] = x;
      num_pos.push_back(make_pair(x, i));
    }
  }

  for (int j=0; j<D; ++j) {
    rolls[N-1].next_without[j] = N;
  }

  for (int i=N-2; i>=0; --i) {
    for (int j=0; j<D; ++j) {
      int x = rolls[i].val[j];
      int rv = rolls[i+1].where(x);
      if (rv != -1) {
        rolls[i].next_without[j] = rolls[i+1].next_without[rv];
      } else {
        rolls[i].next_without[j] = i+1;
      }
    }
  }

  pair<int, int> ans(0, 0);
  for (int a=0; a<N; ++a) {
    // debug(a);
    int b = a;
    rek(a, b);
    if (b - a > ans.second - ans.first) {
      ans = make_pair(a, b);
    }
  }
  cout << ans.first << ' ' << ans.second << '\n';
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
