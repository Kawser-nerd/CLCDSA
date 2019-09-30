#include <stdio.h>
#include <ctype.h>
#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <vector>

//#define M_PI 3.141592653589793238462643
#define eps 1e-8
#define inf ((int)1e9)
#define pb push_back

using namespace std;

vector <long long> pr;
bool u[1100000];

int main()
{
  int t, cnt, i, j;
  long long n, m, res;
  freopen("in", "r", stdin);
  freopen(".out", "w", stdout);
  for (i=2; i<1100000; i++)
    if (!u[i])
    {
      pr.pb((long long)i);
      if (i<2000)
        for (j=i*i; j<1100000; j+=i)
          u[j]=1;
    }
  scanf("%d", &t);
  for (cnt=1; cnt<=t; cnt++)
  {
    cerr<<"test #"<<cnt<<endl;
    scanf("%I64d", &n);
    res=1ll;
    for (i=0; i<(int)pr.size(); i++)
    {
      m=pr[i]*pr[i];
      while (m<=n)
        res++, m*=pr[i];
    }
    if (n==1)
      res=0ll;
    printf("Case #%d: %I64d\n", cnt, res);
  }
  return 0;
}
