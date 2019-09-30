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

int n, m, Head[500], Next[5000], Dest[5000], ee, b, e;
int R[500], Q[500];
bool A[500][500];
int N[500][500];
vector <pair<int,int> > Z;
vector <int> D;

void add (int v1, int v2)
{
  Next[ee]=Head[v1];
  Head[v1]=ee;
  Dest[ee]=v2;
  ee++;
}

int main()
{
  int t, cnt, i, v1, v2, res, j, tmp;
  freopen("in", "r", stdin);
  freopen(".out", "w", stdout);
  scanf("%d", &t);
  for (cnt=1; cnt<=t; cnt++)
  {
    cerr<<"test #"<<cnt<<endl;
    scanf("%d%d", &n, &m);
    memset(Head,-1,sizeof(Head));
    memset(A,0,sizeof(A));
    memset(R,-1,sizeof(R));
    memset(N,-1,sizeof(N));
    res=0, ee=0, b=0, e=1, Q[0]=0, R[0]=0;
    D.clear(), Z.clear();
    for (i=0; i<m; i++)
      scanf("%d,%d", &v1, &v2), add(v1,v2), add(v2,v1), A[v1][v2]=1, A[v2][v1]=1;
    while (b<e)
    {
      for (i=Head[Q[b]]; i!=-1; i=Next[i])
        if (R[Dest[i]]==-1)
          R[Dest[i]]=R[Q[b]]+1, Q[e]=Dest[i], e++;
      b++;
    }
    for (i=Head[0]; i!=-1; i=Next[i])
    {
      Z.pb(make_pair(0,Dest[i])), D.pb(0);
      for (j=1; j<n; j++)
        if (j!=Dest[i] && (A[0][j] || A[Dest[i]][j]))
          D[D.size()-1]++;
      if (Dest[i]==1)
      {
         for (j=1; j<n; j++)
           if (A[0][j])
             res++;
      }
      N[0][Dest[i]]=(int)D.size()-1;
    }
    b=0;
    while (b<(int)Z.size())
    {
      for (i=Head[Z[b].second]; i!=-1; i=Next[i])
        if (R[Dest[i]]==R[Z[b].second]+1)
        {
          if (N[Z[b].second][Dest[i]]==-1)
            N[Z[b].second][Dest[i]]=(int)Z.size(), Z.pb(make_pair(Z[b].second,Dest[i])), D.pb(0);
          tmp=D[b]-1;
          for (j=0; j<n; j++)
            if (j!=Dest[i] && j!=Z[b].second && j!=Z[b].first && A[Dest[i]][j] && (!A[Z[b].first][j]) && (!A[Z[b].second][j]))
              tmp++;
          D[N[Z[b].second][Dest[i]]]=max(D[N[Z[b].second][Dest[i]]],tmp);
          if (Dest[i]==1)
            res=max(res,D[N[Z[b].first][Z[b].second]]);
        }
      b++;
    }
    printf("Case #%d: %d %d\n", cnt, R[1]-1, res);
  }
  return 0;
}
