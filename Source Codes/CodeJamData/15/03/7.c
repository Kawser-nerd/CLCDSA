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

char data[100000];
int table[5][5] =
{
{0},
{0,1,2,3,4},
{0,2,-1,4,-3},
{0,3,-4,-1,2},
{0,4,3,-2,-1},
};
int mul(int a, int b)
{
  if (a < 0 && b < 0) a = -a, b = -b;
  int sgn = 1;
  if (a < 0 || b < 0) sgn = -1;
  a = abs(a), b = abs(b);
  return sgn * table[a][b];
}
int val(int c)
{
  if (c == '1') return 1;
  if (c == 'i') return 2;
  if (c == 'j') return 3;
  if (c == 'k') return 4;
  return 0;
}
int pre[2][100000];

int cal_power(int x, int64 n)
{
  int ret = 1;
  for (; n; n >>= 1)
  {
    if (n&1) ret = mul(x, ret);
    x = mul(x, x);
  }
  return ret;
}
int solve(int64 L, int64 X)
{
  pre[0][0] = val(data[0]);
  for (int i = 1; i < L; ++i)
  {
    pre[0][i] = mul(pre[0][i-1], val(data[i]));
  }
  pre[1][L-1] = val(data[L-1]);
  for (int i = L-2; i >= 0; --i)
  {
    pre[1][i] = mul(pre[1][i+1], val(data[i]));
  }
  {
    int t = cal_power(pre[0][L-1], X);
    if (t != -1) return 0;
  }
  for (int i = 0; i <= 32; ++i)
  for (int j = 0; j <= 32; ++j)
  {
    if (i + j > X) continue;
    int u = cal_power(pre[0][L-1], i);
    int v = cal_power(pre[0][L-1], j);
    int a = 0, b = L-1;
    while (u != 2)
    {
      if (a < L) u = mul(u, val(data[a]));
      else {a = -1; break;}
      ++a;
    }
    if (u != 2) continue;
    while (v != 4)
    {
      if (b >= 0) v = mul(val(data[b]), v);
      else {b = L; break;}
      --b;
    }
    if (v != 4) continue;
    int64 need = i * L + a + j * L + L-1-b;
    if (need <= L*X) return 1;
  }
  return 0;
}
int main()
{
  //cerr << mul(2, mul(3, 4)) << endl;
  //cerr << mul(mul(2, 3), 4) << endl;
  const int T = Rint();
  for (int id = 1; id <= T; ++id)
  {
    int64 L, X;
    scanf("%lld%lld", &L, &X);
    scanf("%s", data);
    int ok = solve(L, X);
    if (ok) printf("Case #%d: YES\n", id);
    else printf("Case #%d: NO\n", id);
  }
  return 0;
}