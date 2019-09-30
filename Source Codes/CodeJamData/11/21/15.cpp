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

char A[110][110];
long double B[110][3];
long double G[110];

int main()
{
  int t, cnt, n, i, j;
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  scanf("%d", &t);
  for (cnt=1; cnt<=t; cnt++)
  {
    cerr<<cnt<<endl;
    scanf("%d", &n);
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
    memset(G,0,sizeof(G));
    for (i=0; i<n; i++)
      scanf(" %s", &A[i]);
    for (i=0; i<n; i++)
       for (j=0; j<n; j++)
         if (A[i][j]!='.')
         {
           G[i]++;
           if (A[i][j]=='1')
             B[i][0]++;  
         }
    for (i=0; i<n; i++)
      for (j=0; j<n; j++)
        if (A[i][j]!='.')  
          B[i][1]+=((B[j][0]-((long double)(A[j][i]=='1')))/(G[j]-((long double)1.0)));
    for (i=0; i<n; i++)
      for (j=0; j<n; j++)
        if (A[i][j]!='.')
          B[i][2]+=B[j][1]/G[j];
    printf("Case #%d:\n", cnt);
    for (i=0; i<n; i++)
      printf("%.8lf\n", (double)((B[i][0]/4.0+B[i][1]/2.0+B[i][2]/4.0)/G[i]));
  }
  return 0;
}
