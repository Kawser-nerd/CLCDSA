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

char F[600][600];
int A[600][600][3];   //x, y, w;

inline int cell (int i, int j, int k)
{
   if (k==0)
     return i*((int)(F[i-1][j-1]-'0'));
   if (k==1)
     return j*((int)(F[i-1][j-1]-'0'));
   return (int)(F[i-1][j-1]-'0');
}

inline int mass (int i, int j, int l, int k)
{
  return A[i+l][j+l][k]+A[i-1][j-1][k]-A[i+l][j-1][k]-A[i-1][j+l][k]-cell(i,j,k)-cell(i,j+l,k)-cell(i+l,j,k)-cell(i+l,j+l,k);
}

int main()
{
  int t, cnt, i, j, r, c, d, l, res;
  freopen("in", "r", stdin);
  freopen(".out", "w", stdout);
  scanf("%d", &t);
  for (cnt=1; cnt<=t; cnt++)
  {
    cerr<<"test #"<<cnt<<endl;
    memset(A,0,sizeof(A));
    memset(F,0,sizeof(F));
    res=-1;
    scanf("%d%d%d ", &r, &c, &d);
    for (i=0; i<r; i++)
      gets(F[i]);
    for (i=1; i<=r; i++)
      for (j=1; j<=c; j++)
      {
        A[i][j][0]=A[i][j-1][0]+A[i-1][j][0]-A[i-1][j-1][0]+i*((int)(F[i-1][j-1]-'0'));
        A[i][j][1]=A[i][j-1][1]+A[i-1][j][1]-A[i-1][j-1][1]+j*((int)(F[i-1][j-1]-'0'));
        A[i][j][2]=A[i][j-1][2]+A[i-1][j][2]-A[i-1][j-1][2]+((int)(F[i-1][j-1]-'0'));
      }  
    for (i=1; i<=r; i++)
      for (j=1; j<=c; j++)
        for (l=2; l<=min(r-i,c-j); l++)
          if (mass(i,j,l,2)*(2*i+l)==2*mass(i,j,l,0) && mass(i,j,l,2)*(2*j+l)==2*mass(i,j,l,1))
            res=max(res,l+1);
    if (res>0)
      printf("Case #%d: %d\n", cnt, res);
    else
      printf("Case #%d: IMPOSSIBLE\n", cnt);
  }
  return 0;
}
