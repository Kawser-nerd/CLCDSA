#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define ll long long

int tn, nt, n;
long long a[1005];
int next[1005];
long long b[1005];

int main(void)
{
   //freopen("C-small-attempt0.in", "r", stdin);
   //freopen("C-small-attempt0.out", "w", stdout);
   freopen("C-large.in", "r", stdin);
   freopen("C-large.out", "w", stdout);

   scanf("%d\n", &nt);
   for (tn=0; tn<nt; tn++)
   {
      fprintf(stderr, "Case #%d: \n", tn+1);

      long long r, k, sum=0;
      cin >> r >> k >> n;
      for (int i=0; i<n; i++)
      {
        cin >> a[i];
        sum+=a[i];
      }
      ll res=0;
      if (sum<=k) 
      {
        res=r*sum;
      }
      else
      {
        for (int i=0; i<n; i++)
        {
          ll cur=0;
          int j=i;
          while (cur+a[j]<=k)
          {
            cur+=a[j];
            j=(j+1)%n;
          }
          next[i]=j;
          b[i]=cur;
        }
        int t=0;
        for (int i=0; i<r; i++, t=next[t])
          res+=b[t];
      }

      printf("Case #%d: %I64d\n", tn+1, res);
   }
   return 0;
}
