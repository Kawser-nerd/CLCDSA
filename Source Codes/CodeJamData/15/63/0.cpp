#include <bits/stdc++.h>

using namespace std;

struct Fraction {
  long long a;
  long long b;

  inline bool operator <(const Fraction &other) const {
    return a * other.b < b * other.a;
  }
};

const int inf = 1000000;
const int N = 1000010;

char foo[N];
int a[N];
long long s[N];
pair <long long, long long> p[N];
int n;

bool at_most(long long num, long long den) {
  for (int i = 0; i <= n; i++) {
    long long x =  s[i] * den + i * num;
    long long y = -s[i] * den + i * num;
    p[i] = make_pair(x, y);
  }
  sort(p, p + n + 1);
  for (int i = 0; i < n; i++) {
    if (p[i].second <= p[i + 1].second) {
      return true;
    }
  }
  return false;
}

pair < pair <long long, long long>, int > q[N];

int main(int argc, char* argv[]) {
  int TEST_FROM = 0;
  int TEST_TO = 123456789;
  if (argc == 3) {
    sscanf(argv[1], "%d", &TEST_FROM);
    sscanf(argv[2], "%d", &TEST_TO);
  }
  freopen("in", "r", stdin);
//  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    // input data starts
    int f;
    double _f;
    scanf("%d %lf", &n, &_f);
    f = (int)(_f * inf + 0.5);
    scanf("%s", foo);
    for (int i = 0; i < n; i++) {
      a[i] = foo[i] - '0';
    }
    // input data ends
    if (qq < TEST_FROM || qq > TEST_TO) {
      continue;
    }
    printf("Case #%d: ", qq);
    fflush(stdout);
    // solution starts
    s[0] = 0;
    for (int i = 0; i < n; i++) {
      s[i + 1] = s[i] + (a[i] == 0 ? (-f) : (inf - f));
    }
    long long low = -1, high = inf * 1LL * inf + 1;
    while (low + 1 < high) {
      long long num = (low + high) / 2;
      long long den = inf;
      if (at_most(num, den)) {
        high = num;
      } else {
        low = num;
      }
    }
    vector < Fraction > u;
    if (low == -1) {
      u.push_back(Fraction {0, 1});
    } else {
      for (int den = 1; den <= inf; den++) {
        long long num = (low * den / inf + 1);
        u.push_back(Fraction {num, den});
      }
    }
    sort(u.begin(), u.end());
    int from = 0, to = (int)u.size() - 1;
    while (from < to) {
      int mid = (from + to) >> 1;
      long long num = u[mid].a;
      long long den = u[mid].b;
      if (at_most(num, den)) {
        to = mid;
      } else {
        from = mid + 1;
      }
    }
    long long num = u[from].a;
    long long den = u[to].b;
    for (int i = 0; i <= n; i++) {
      long long x =  s[i] * den + i * num;
      long long y = -s[i] * den + i * num;
      q[i] = make_pair(make_pair(x, y), i);
    }
    sort(q, q + n + 1);
    int ans = n + 1;
    long long mx = -(long long)6e18;
    for (int i = n; i >= 0; i--) {
      if (q[i].first.second > mx || i == n) {
        mx = q[i].first.second;
      } else {
        if (q[i].second < ans) {
          ans = q[i].second;
        }
      }
    }
    printf("%d\n", ans);
    // solution ends
    fflush(stdout);
    fprintf(stderr, "test %d solved, time = %d ms\n", qq, (int)clock());
  }
  return 0;
}
