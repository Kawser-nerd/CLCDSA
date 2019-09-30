#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

const int maxm = 500000 + 10;
const int maxN = 500000 + 10;
const int size = 1000000007;
const int infinite = 1 << 30;

long long a[maxm];
long long Max[maxN * 4];
int b[maxN], c[maxN];
int N, n, m, data, len;
long long X, Y, Z, ans;

void getinf()
{
  cin >> N >> m >> X >> Y >> Z;
  for (int i = 0; i < m; i++) cin >> a[i];
}

void gen()
{
  n = 0;
  c[n++] = -infinite;
  for (int i = 0; i <= N - 1; i++)
    {
      b[i + 1] = a[i % m];
      c[n++] = b[i + 1];
      //      cout << b[i + 1] << endl;
      a[i % m] = (X * a[i % m] + Y * (i + 1)) % Z;
    }
  sort(c, c + n);
  n = unique(c, c + n) - c;
  //  for (int i = 0; i < n; i++) cout << c[i] << endl;
}

void ins(int p, int l, int r, int x, int val)
{
  if (l == r && l == x)
    {
      Max[p] = (Max[p] + val) % size;
      return;
    }
  int mid = (l + r) / 2;
  if (x <= mid) ins(p * 2, l, mid, x, val); else ins(p * 2 + 1, mid + 1, r, x, val);
  Max[p] = (Max[p * 2] + Max[p * 2 + 1]) % size;
}

int getMax(int p, int l, int r, int x, int y)
{
  if (l > r) return 0;
  if (x <= l && r <= y)
    {
      return Max[p];
    }
  long long t1 = 0, t2 = 0;
  int mid = (l + r) / 2;
  if (x <= mid) t1 = getMax(p * 2, l, mid, x, y);
  if (y > mid) t2 = getMax(p * 2 + 1, mid + 1, r, x, y);
  t1 = (t1 + t2) % size;
  return t1; 
}


void solve()
{
  memset(Max, 0, sizeof(Max));
  ans = 0;
  int x, F;
  for (int i = 1; i <= N; i++) 
    {
      x = lower_bound(c, c + n, b[i]) - c;
      //      cout << c[x] << ' ' << b[i] << endl;
      F = 1;
      if (x > 1) F += getMax(1, 1, n, 1, x - 1);
      ins(1, 1, n, x, F);
      //      cout << x << ' ' << F << endl;
    }
  ans = Max[1];
}

int main()
{
  scanf("%d", &data);
  for (int tot = 1; tot <= data; tot++)
    {
      getinf();
      gen();
      solve();
      cout << "Case #" << tot << ": " << ans << endl;
    }
}
