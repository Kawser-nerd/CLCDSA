#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const long long inf = (long long)1.1e15;

long long gcd(long long a, long long b) {
  while (a > 0 && b > 0)
    if (a > b) a %= b;
    else b %= a;
  return a + b;
}

long long comb(long long cnt_a, long long cnt_b) {
  long long n = cnt_a + cnt_b;
  long long k = (cnt_a < cnt_b ? cnt_a : cnt_b);
  if (k >= 30) {
    return inf;
  }
  long long res = 1;
  for (long long u = 1; u <= k; u++) {
    // res = res * (n - u + 1) / u
    long long x = gcd(res, u);
    res /= x;
    long long mul = (n - u + 1) / (u / x);
    if (1.0 * res * mul > 2 * inf) {
      res = inf;
      break;
    }
    res *= mul;
    if (res >= inf) {
      break;
    }
  }
  return res;
}

long long get_sum_slow(long long from, long long to, long long cnt_b) {
  long long sum = 0;
  for (long long cnt_a = to; cnt_a >= from; cnt_a--) {
    sum += comb(cnt_a, cnt_b);
    if (sum >= inf) {
      break;
    }
  }
  return sum;
}

long long get_sum_wrong(long long from, long long to, long long cnt_b) {
  long long mid = (from + to) / 2;
  long long bound = comb(mid, cnt_b);
  if (1.0 * bound * (to - from + 1) > 2 * inf) {
    return inf;
  }
  bound *= to - from + 1;
  if (bound >= inf) {
    return inf;
  }
  return comb(to, cnt_b + 1) - (from > 0 ? comb(from - 1, cnt_b + 1) : 0);
}

long long get_sum(long long from, long long to, long long cnt_b) {
  long long part = comb(to, cnt_b + 1);
  if (part >= inf) {
    return get_sum_slow(from, to, cnt_b);
  }
  return part - (from > 0 ? comb(from - 1, cnt_b + 1) : 0);
}

int main(int argc, char* argv[]) {
  int TEST_FROM = 0;
  int TEST_TO = 123456789;
  if (argc == 3) {
    sscanf(argv[1], "%d", &TEST_FROM);
    sscanf(argv[2], "%d", &TEST_TO);
  }
  freopen("in", "r", stdin);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    long long n, a, b;
    cin >> n >> a >> b;
    if (qq < TEST_FROM || qq > TEST_TO) {
      continue;
    }
    printf("Case #%d: ", qq);
    fflush(stdout);
    long long low = 0, high = inf;
    while (low < high) {
      long long mid = (low + high) / 2;
      cerr << "test " << qq << ", mid = " << mid << endl;
      long long res = 0;
      if (mid < a) {
        res = 1;
      } else {
        long long have = mid - a;
        long long max_b = have / b;
        for (long long cnt_b = max_b; cnt_b >= 0; cnt_b--) {
          long long left = have - b * cnt_b;
          long long from, to;
          from = left - a + 1;
          to = left;
          if (from < 0) {
            from = 0;
          } else {
            from = (from + a - 1) / a;
          }
          to = to / a;
          if (from <= to) {
            res += get_sum(from, to, cnt_b);
          }
          from = left - b + 1;
          to = left;
          if (from < 0) {
            from = 0;
          } else {
            from = (from + a - 1) / a;
          }
          to = to / a;
          if (from <= to) {
            res += get_sum(from, to, cnt_b);
          }
          if (res >= n) {
            break;
          }
        }
      }
      if (res >= n) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    cout << low << endl;
    fflush(stdout);
    fprintf(stderr, "test %d solved\n", qq);
  }
  return 0;
}
