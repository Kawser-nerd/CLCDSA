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
char data[102400];
int main()
{
  const int T = Rint();
  for (int id = 1; id <= T; ++id)
  {
    const int n = Rint();
    scanf("%s", data);
    int ans = 0;
    int s = 0;
    for (int i = 0; i <= n; ++i)
    {
      const int dig = data[i] - '0';
      if (i > 0 && s < i) ans += i - s, s = i;
      s += dig;
    }
    printf("Case #%d: %d\n", id, ans);
  }
  return 0;
}