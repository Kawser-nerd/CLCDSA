#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MOD 1000002013LL

long long dist(long long a, long long b, long long N) {
  return (b-a) * (N + (N-(b-a-1))) / 2;
}

main() {
  long long T, N, M, o, e, p, prob = 1;
  for (cin >> T; T--;) {
    long long tot = 0;
    vector<pair<long long, long long> > event;
    cin >> N >> M;
    for (long long i = 0; i < M; i++) {
      cin >> o >> e >> p;
      tot = (tot + p * (dist(o, e, N) % MOD)) % MOD;
      event.push_back(make_pair(o, -p));
      event.push_back(make_pair(e, p));
    }
    sort(event.begin(), event.end());

    vector<pair<long long, long long> > q;
    for (long long i = 0; i < event.size(); i++) {
      if (event[i].second < 0) {
        q.push_back(make_pair(event[i].first, -event[i].second));
      } else {
        long long n = event[i].second;
        while (n) {
          long long m = min(n, q.back().second);
          long long d = dist(q.back().first, event[i].first, N);
          tot = (tot - m * (d % MOD)) % MOD;
          n -= m;
          q.back().second -= m;
          if (q.back().second == 0) q.pop_back();
        }
      }
    }
    if (tot < 0) tot += MOD;
    cout << "Case #" << prob++ << ": " << tot << endl;
  }
}
