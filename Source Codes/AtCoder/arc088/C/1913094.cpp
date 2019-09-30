#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MaxN 300000

int t[MaxN];

int read(int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += t[idx];
    idx -= idx & -idx;
  }
  return sum;
}

void write(int idx, int v) {
  while (idx < MaxN) {
    t[idx] += v;
    idx += idx & -idx;
  }
}

int main(void) {
  string s;
  cin >> s;
  
  vector<int> freq(26);
  for (char c : s) {
    freq[c-'a']++;
  }
  
  int odd = 0;
  for (int i = 0; i < 26; i++) {
    if (freq[i] % 2) {
      odd++;
    }
  }
  
  if (odd > 1) {
    cout << "-1" << endl;
    return 0;
  }

  vector<vector<int>> positions(26);
  int pos = 0;
  for (char c : s) {
    positions[c - 'a'].push_back(pos);
    pos++;
  }

  long long ans = 0;
  if (odd) {
    for (auto p : positions) {
      if (p.size() % 2) {
        int m = int(p.size()) / 2;
        int mid = p[m];
        for (auto q : positions) {
          int sz = int(q.size());
          for (int i = 0; i < int(q.size()) / 2; i++) {
            if (q[i] > mid) ans++;
            if (q[sz - i - 1] < mid) ans++;
          }
        }
        break;
      }
    }
  }

  vector<pair<int, int>> events;
  for (auto p : positions) {
    int m = int(p.size());
    for (int i = 0; i < m / 2; i++) {
      events.push_back(make_pair(p[i], p[m - i - 1]));
    }
  }

  sort(begin(events), end(events));

  for (auto e : events) {
    ans += 2 * read(e.first+1) + (read(e.second+1) - read(e.first+1));
    write(e.second+1, 1);
  }

  cout << ans << endl;

  return 0;
}