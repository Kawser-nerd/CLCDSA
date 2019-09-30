#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

#define rep(i,x,y) for (int i=x;i<=y;i++)
#define dep(i,y,x) for (int i=y;i>=x;i--)
#define sz(x) (int)(x.size())

using namespace std;

typedef long long LL; 
typedef unsigned long long uLL;

const int maxn=500+7;

int n,m;
char a[maxn][maxn],b[maxn][maxn],M[maxn][maxn];

int main()
{
 scanf("%d%d",&n,&m);
 rep(i,1,n)
 {
  scanf("%s",M[i]+1);
  rep(j,1,m) a[i][j]=M[i][j],b[i][j]=M[i][j];
 }
 
 rep(i,1,n) a[i][1]='#',b[i][m]='#';
 
 for (int i=1;i<=n;i+=2) rep(j,1,m-1) a[i][j]='#';
 for (int i=2;i<=n;i+=2) dep(j,m,2) b[i][j]='#';

 rep(i,1,n) printf("%s\n",a[i]+1);
 printf("\n");
 rep(i,1,n) printf("%s\n",b[i]+1);

 // system("pause");
 return 0;
}