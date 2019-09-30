
  #include <cstdio>
  #include <cstring>
  #include <cmath>
  #include <algorithm>

  using namespace std;
 
  const int maxn  =  100000 + 5;

  int n, m, tot, SIZE;
  int st[maxn], en[maxn], pos[maxn];
  int a[maxn], sor[maxn];

  inline void init()
    {
       scanf("%d %d", &n, &m);
       for (int k = 1; k <= n; k ++) scanf("%d", &a[k]);

       SIZE = 500;
       tot = 0, en[0] = 0;
       while (en[tot] < n)
         {
            ++tot;
            st[tot] = en[tot - 1] + 1;
            en[tot] = st[tot] + SIZE - 1;
            if (en[tot] > n) en[tot] = n;
            for (int k = st[tot]; k <= en[tot]; k ++) 
              {
                sor[k] = a[k], pos[k] = tot;
              }
            sort(sor + st[tot], sor + en[tot] + 1);
         }
    }

  inline void update(int x, int v)
    {
       int grp = pos[x];
       for (int i = st[grp]; i <= en[grp]; i ++)
         if (sor[i] == a[x])
           {
              sor[i] = v;
              int j = i;
              while (j > st[grp] && sor[j] < sor[j - 1]) { swap(sor[j], sor[j - 1]); --j; }
              while (j < en[grp] && sor[j] > sor[j + 1]) { swap(sor[j], sor[j + 1]); ++j; }
              break;
           }
       a[x] = v;
    }

  inline int get(int x, int y, int v)
    {
       int ret = 0;
       for (int k = x; k <= y; k ++)
         if (a[k] <= v && a[k] > ret) ret = a[k];
       return ret;
    }

  inline void makequery(int x, int y, int v)
    {
       if (pos[x] == pos[y])
         {
            printf("%d\n", get(x, y, v));
            return;
         }
       int ret = get(x, en[pos[x]], v);
       ret >?= get(st[pos[y]], y, v);

       for (int k = pos[x] + 1; k < pos[y]; k ++)
         {
            if (sor[st[k]] > v) continue;
            if (sor[en[k]] <= ret) continue;
            int L = st[k], R = en[k];
            while (L < R)
              {
                int mid = (L + R + 1) / 2;
                if (sor[mid] <= v) L = mid; else R = mid - 1;
              }
            ret >?= sor[L];
         } 
       printf("%d\n", ret);
    }

  inline void work()
    {
       for (int k = 0; k < m; k ++)
         {
            int cmd;
            scanf("%d", &cmd);
            if (cmd == 0)
              {
                 int x, y;
                 scanf("%d %d", &x, &y);
                 update(x, y);
              } else
              {
                 int x, y, v;
                 scanf("%d %d %d", &x, &y, &v);
                 makequery(x, y, v);
              }
         }
    }

  int main()
    {
       //freopen("P3.in", "r", stdin);
       //freopen("P3.out", "w", stdout);
         init();
         work();
       return 0;
    }
