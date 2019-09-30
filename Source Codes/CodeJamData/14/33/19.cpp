#include <cstdio>
#include <algorithm>
using namespace std;
int t,tt,i,ii,j,k,p,n,m,e,r,nj,ni,f[2020][2020];
int main() {
  freopen("Cl.in","r",stdin);
  freopen("Cl.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d%d%d",&n,&m,&e);
    r=3*(n+m);
    for (i=1; i<=m; i++) f[i][i-1]=i;
    for (j=1; j<=2*(n+m); j++) for (ii=0; ii<n*m; ii++) if (f[j][ii]>0) {
      k=ii%m+1;
      i=ii/m+1;
      //printf("%d %d %d = %d\n",i,j,k,f[j][ii]);
      if (f[j][ii]>=e) r=min(r,j+(i==1?0:max(0,k-2)));
      //printf("%d\n",r);
      if (i<n) for (p=k-2; p<=k+2; p++) if (p>=1 && p<=m) {
        nj=j+min(p,2);
        ni=i*m+p-1;
        f[nj][ni]=max(f[nj][ni],f[j][ii]+p);
      }
      f[j][ii]=0;
    }
    printf("Case #%d: %d\n",t,r);
  }
  return 0;
}
