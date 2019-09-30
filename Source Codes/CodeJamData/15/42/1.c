const int maxp = 100000;
#include <pe>

int64 ReadNumber()
{
  int64 x = Rint();
  int64 y = Rint();
  return x * 10000 + y;
}
int main()
{
  init_primes();
  const int T = Rint();
  for (int id = 1; id <= T; ++id)
  {
    int n = Rint();
    int64 v = ReadNumber(), x = ReadNumber();
    map<int64, int64> mem;
    for (int i = 0; i < n; ++i)
    {
      int64 r = ReadNumber();
      int64 c = ReadNumber();
      mem[c] += r;
    }
    vector<pair<int64, int64> > vec;
    for (auto& iter: mem) vec.pb(iter);
    
    
    double l = 0, r = 1e9;
    for (int i = 0; i < 500; ++i)
    {
      if (fabs(r-l) < 1e-16) break;
      double mid = (l + r) * 0.5;
      double min_v = 0, min_t = 0;
      double max_v = 0, max_t = 0;
      for (auto& iter: vec)
      {
        double can = mid * iter.second;
        if (can + min_v > v)
        {
          double av = v - min_v;
          double u = min_v * min_t + av * iter.first;
          min_v = v;
          min_t = u / v;
          break;
        }
        else
        {
          double av = can;
          double u = min_v * min_t + av * iter.first;
          min_v = min_v + av;
          min_t = u / min_v;
        }
      }
      for (int i = vec.size() - 1; i >= 0; --i)
      {
        auto iter = vec[i];
        double can = mid * iter.second;
        if (can + max_v > v)
        {
          double av = v - max_v;
          double u = max_v * max_t + av * iter.first;
          max_v = v;
          max_t = u / v;
          break;
        }
        else
        {
          double av = can;
          double u = max_v * max_t + av * iter.first;
          max_v = max_v + av;
          max_t = u / max_v;
        }
      }
      int ok = 1;
      if (min_v < v-1e-6 || max_v < v-1e-6)
      {
        ok = 0;
      }
      else if (min_t > x || max_t < x) ok = 0;
      if (ok) r = mid; else l = mid;
    }
    double ans = (l + r) * 0.5;
    if (ans > 1e8) printf("Case #%d: IMPOSSIBLE\n", id);
    else printf("Case #%d: %.16f\n", id, ans);
  }
  return 0;
}