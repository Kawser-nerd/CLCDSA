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

bool A[2100][2100];
int ans, C[2100], Deg[2100], B[2100][2];
bool u[2100];

void solve (vector <int> V)
{
  int i, j, c;
  bool fl;
  vector <int> tmp;

  /*printf("\n\n");
  printf("%d\n", ans);
  for (i=0; i<(int)V.size(); i++)
    printf("%d ", V[i]);
  printf("\n\n");  */

  for (i=0; i<(int)V.size(); i++)
    if (Deg[V[i]]>0)
    {
      //printf("   %d\n", V[i]);
      for (fl=0, j=i+1; ; j++, j%=(int)V.size())
      {
        //printf("%d %d\n", V[j], Deg[V[j]]);
        if (A[V[i]][V[j]] && j!=(i+1)%((int)V.size()))
          break;
        if (Deg[V[j]]>0)
        {
          //printf("????\n");
          fl=1;
          break;
        }
      }
      if (fl)
        continue;
      tmp.clear();
      for (j=i; j<(int)V.size(); j++)
        tmp.pb(V[j]);
      for (j=0; j<i; j++)
        tmp.pb(V[j]);
      V.clear();
      V=tmp;
      break;
    }


 /* printf("\n\n");
  printf("%d\n", ans);
  for (i=0; i<(int)V.size(); i++)
    printf("%d ", V[i]);
  printf("\n\n");  */
  //cerr<<A[V[0]][V[1]]<<endl;

  for (i=2; i<((int)V.size()-1); i++)
    if (A[V[0]][V[i]])
    {
      //cerr<<V[0]<<" "<<V[i]<<endl;
      tmp.clear();
      tmp.pb(V[0]);
      for (j=i; j<(int)V.size(); j++)
        tmp.pb(V[j]);
      ans=min(ans,i+1);
      Deg[V[0]]--, Deg[V[i]]--;
      solve(tmp);
      memset(u,0,sizeof(u));
      u[C[V[0]]]=1, u[C[V[i]]]=1;
      for (c=C[V[0]], j=1; j<i; j++)
      {
        c++;
        if (c==ans+1)
          c=1;
        while (u[c])
        {
          c++;
          if (c==ans+1)
            c=1;
        }
        C[V[j]]=c;
      }
      if (ans==3)
      {
        C[V[1]]=6-C[V[0]]-C[V[i]];
        for (j=i-1; j>1; j--)
          C[V[j]]=6-C[V[1]]-C[V[j+1]];
      }
      return;
    }
  /*for (i=0; i<(int)V.size(); i++)
    if (Deg[V[i]]>0)
      cerr<<"!!!!!!!!!!!!!!!!!"<<endl;  */
  ans=min(ans,(int)V.size());
  for (i=0; i<(int)V.size(); i++)
    C[V[i]]=i%ans+1;
  while (C[V[0]]==C[V[(int)V.size()-1]] || C[V[0]]==C[V[1]])
    C[V[0]]++;  
}

int main()
{
  int t, cnt, i, n, m;
  vector <int> tmp;
  freopen(".in", "r", stdin);
  freopen(".out", "w", stdout);
  scanf("%d", &t);
  for (cnt=1; cnt<=t; cnt++)
  {
    cerr<<cnt<<endl;
    memset(A,0,sizeof(A));
    memset(C,0,sizeof(C));
    memset(Deg,0,sizeof(Deg));
    tmp.clear();
    ans=inf;
    scanf("%d%d", &n, &m);
    for (i=0; i<m; i++)
      scanf("%d", &B[i][0]), B[i][0]--;
    for (i=0; i<m; i++)
      scanf("%d", &B[i][1]), B[i][1]--;
    for (i=0; i<m; i++)
      Deg[B[i][0]]++, Deg[B[i][1]]++, A[B[i][0]][B[i][1]]=1, A[B[i][1]][B[i][0]]=1;
    //cerr<<A[0][3]<<endl;
    for (i=0; i<n; i++)
      tmp.pb(i);  
    solve(tmp);
    printf("Case #%d: %d\n", cnt, ans);
    for (i=0; i<n; i++)
      printf("%d ", C[i]);
    printf("\n"); 
  }
  return 0;
}
