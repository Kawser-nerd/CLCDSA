
  #include <cstdio>
  #include <cstring>
  #include <cmath>
  #include <algorithm>

  using namespace std;

  #define sqr(x) ((x) * (x))

  const int tot    =  20;
  const int Rand   =  20;
  const int maxn   =  50 + 5;
  const double EPS =  1e-5;
  const double PI  =  3.141592653589793238462643383279502884197169399375105820974944592;

  struct node
    {
      double x, y, r;
    }a[maxn], cand[tot];

  int n, l, w;
  double delta;
  
  double getdist(double x, double y)
    {
       if (x < 0 || x > l || y < 0 || y > w) return 0;
       double ret;
       for (int k = 0; k < n; k ++)
         {
           double tmp = sqrt(sqr(a[k].x - x) + sqr(a[k].y - y)) / a[k].r;
           if (!k) ret = tmp; else ret <?= tmp;
         }
       return ret;
    }

  void init()
    {
       scanf("%d %d %d", &n, &l, &w);
       for (int k = 0; k < n; k ++) 
         scanf("%lf %lf %lf", &a[k].x, &a[k].y, &a[k].r);

       for (int k = 0; k < tot; k ++)
         {
           cand[k].x = rand() % (l + 1);
           cand[k].y = rand() % (w + 1);
           cand[k].r = getdist(cand[k].x, cand[k].y);
         }
    }

  void calc(int i)
    {
       double tmp = rand();
       tmp -= int(tmp / PI / 2) * PI * 2;
       double x = cand[i].x + delta * cos(tmp);
       double y = cand[i].y + delta * sin(tmp);
       double temp = getdist(x, y);
       if (temp > cand[i].r)
         {
            cand[i].x = x;
            cand[i].y = y;
            cand[i].r = temp;
         }
    }

  void work()
    {
       delta = max(l, w) / sqrt(tot);
       while (delta > EPS)
         {
            for (int i = 0; i < tot; i ++)
               for (int j = 0; j < Rand; j ++) calc(i);
            delta *= 0.9;
         }
       double ret = 0;
       for (int k = 0; k < tot; k ++) ret >?= cand[k].r;
       printf("%.3lf\n", ret);
    }

  int main()
    {
       //freopen("p4.in", "r", stdin);
         init();
         work();
       return 0;
    }
