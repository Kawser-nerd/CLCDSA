#include <iostream>
#include <utility>
#include <list>
#include <tuple>

using namespace std;

typedef pair<int, int> Way; // minutes, to where.
typedef tuple<int, int, int> Path;  // minutes, current town, highest prize

int N, M, T;
int PRIZES[100001];
list<Way> WAYS[100001], R_WAYS[100001];

int MINUTES[100001];
int R_MINUTES[100001];

void calcMinutes() {

  list<int>* updated = new list<int>;

  updated->push_back(1);

  for (const auto town : *updated) {
    int minutes = MINUTES[town];

    for (const auto& w : WAYS[town]) {
      int t = w.second;
      if (t == 1)
        continue;

      int m = w.first;
      if (T <= m)
        continue;

      if (MINUTES[t] == 0 || minutes + m < MINUTES[t]) {
        MINUTES[t] = minutes + m;
        updated->push_back(t);
      }
    }
  }

  delete updated;
}


void calcRMinutes() {

  list<int>* updated = new list<int>;

  updated->push_back(1);

  for (const auto town : *updated) {
    int minutes = R_MINUTES[town];

    for (const auto& w : R_WAYS[town]) {
      int t = w.second;
      if (t == 1)
        continue;

      int m = w.first + minutes;
      if (T <= m + MINUTES[t])
        continue;

      if (R_MINUTES[t] == 0 || m < R_MINUTES[t]) {
        R_MINUTES[t] = m;
        updated->push_back(t);
      }
    }
  }

  delete updated;
}


uint64_t calcPrize() {

  uint64_t highest = T * PRIZES[1];

  for (int i=1; i<=N; ++i) {
    int minutes = MINUTES[i] + R_MINUTES[i];

    if (T <= minutes || MINUTES[i] == 0 || R_MINUTES[i] == 0)
      continue;

    uint64_t prize = (T - minutes) * PRIZES[i];
    if (highest < prize)
      highest = prize;
  }

  return highest;
}

int main() {

  cin >> N >> M >> T;

  int a;
  for (int i=1; i<=N; ++i) {
    cin >> a;
    PRIZES[i] = a;
  }

  int f, t, m;
  for (int i=1; i<=M; ++i) {
    cin >> f >> t >> m;
    WAYS[f].push_back(make_pair(m, t));
    R_WAYS[t].push_back(make_pair(m, f));
  }

  calcMinutes();
  calcRMinutes();

  cout << calcPrize() << endl;

  return 0;

}