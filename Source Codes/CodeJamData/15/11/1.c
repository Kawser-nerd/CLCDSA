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

int data[1005];
int main()
{
  const int T = Rint();
  for (int id = 1; id <= T; ++id)
  {
    const int n = Rint();
    for (int i = 0; i < n; ++i)
    data[i] = Rint();
    
    int ans1 = 0, ans2 = 0;
    for (int i = 1; i < n; ++i)
    if (data[i] < data[i-1]) ans1 += data[i-1] - data[i];
    
    int speed = 0;
    for (int i = 1; i < n; ++i)
    if (data[i] < data[i-1])
    {
      int t = data[i-1] - data[i];
      //if (speed > t) t = speed;
      if (t > speed) speed = t;
    }
    //cerr << speed << endl;
    int have = 0;
    for (int i = 0; i < n - 1; ++i)
    {
      have = data[i];
      int temp = min(speed, have);
      ans2 += temp;
      //have -= temp;
      //cerr << have << " " << temp << endl;
    }
    
    printf("Case #%d: %d %d\n", id, ans1, ans2);
  }
  return 0;
}