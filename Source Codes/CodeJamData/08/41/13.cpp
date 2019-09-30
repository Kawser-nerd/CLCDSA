
  #include <cstdio>
  #include <cstring>
  #include <cmath>
  #include <algorithm>

  using namespace std;

  const int maxn  =  100000 + 5;

  int n, Const;
  int a[maxn];
  long long S[maxn];
  
  void init()
    {
       scanf("%d", &n);
       S[0] = 0;
       for (int k = 1; k <= n; k ++) 
         {
           scanf("%d", &a[k]);
           S[k] = S[k - 1] + a[k];
         }
       scanf("%d", &Const);
    }

  void work()
    {
       int ret = n;
       int j = 1;
       for (int i = 1; i <= n; i ++)
         {
            j >?= i;
            while (j <= n && (S[j] - S[i - 1] < Const)) ++ j;
            if (j > n) break;
            ret <?= j - i;
         }
       printf("%d\n", ret);
    }

  int main()
    {
       //freopen("input.txt", "r", stdin);
         init();
         work();
       return 0;
    }
