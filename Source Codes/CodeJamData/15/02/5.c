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

int data[1024];
int main()
{
  const int T = Rint();
  for (int id = 1; id <= T; ++id)
  {
    const int N = Rint();
    for (int i = 0; i < N; ++i)
    data[i] = Rint();
    sort(data, data+N);
    int ans = data[N-1];
    for (int eat = 1; eat <= data[N-1]; ++eat)
    {
      int s = 0;
      for (int i = 0; i < N; ++i)
      {
        int t = (data[i] + eat - 1) / eat;
        if (t > 1) s += t - 1;
      }
      const int t = s + eat;
      if (t < ans) ans = t;
    }
    printf("Case #%d: %d\n", id, ans);
  }
  return 0;
}