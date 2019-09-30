const int maxp = 100000;
#include <pe>
static inline int Rint()
{
    struct X{ int dig[256]; X(){
    for(int i = '0'; i <= '9'; ++i) dig[i] = 1; dig['-'] = 1;
    }};
    static     X fuck;int s = 1, v = 0, c;
    for (;!fuck.dig[c = getchar()];);
    if (c == '-') s = 0; else if (fuck.dig[c]) v = c ^ 48;
    for (;fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48));
    return s ? v : -v;
}

int64 data[1005];
struct Pt
{
  int64 av_time;
  int id;
  int operator < (const Pt& other) const
  {
    if (av_time != other.av_time) return av_time < other.av_time;
    return id < other.id;
  }
};
int main()
{
  const int T = Rint();
  for (int id = 1; id <= T; ++id)
  {
    const int m = Rint();
    const int64 n = Rint();
    for (int i = 1; i <= m; ++i)
    data[i] = Rint();
    int64 l = 0, r = n * 100000 + 5;
    while (l <= r)
    {
      int64 mid = l + r >> 1;
      int64 serve = 0;
      for (int i = 1; i <= m; ++i)
      serve += (mid + data[i] - 1) / data[i];
      if (serve >= n) r = mid - 1; else l = mid + 1;
    }
    int64 serve = 0;
    for (int i = 1; i <= m; ++i)
      serve += (r + data[i] - 1) / data[i];
    assert(serve < n);
    vector<Pt> vec;
    for (int i = 1; i <= m; ++i)
    {
      int64 temp = (r + data[i] - 1) / data[i];
      temp *= data[i];
      vec.push_back({temp, i});
    }
    sort(vec.begin(), vec.end());
    int where = n - serve - 1;
    assert(where >= 0 && where < m);
    int ans = vec[n-serve-1].id;
    printf("Case #%d: %d\n", id, ans);
  }
  return 0;
}