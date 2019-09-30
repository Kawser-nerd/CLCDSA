#include <stdio.h>
#include <string.h>
int a[1024],n;
double dp[1024];
int v[1024];

void precalc() {
  int i;
  for(i=0;i<1024;i++) dp[i]=-1;
  dp[1]=0;
  dp[2]=2;
  for(i=3;i<1001;i++) dp[i]=i;
}

int main() {
  double r;
  int cases,caseno=1,i,z,e;
  precalc();
  scanf("%d",&cases);
  while(cases--) {
    scanf("%d",&n);
    for(i=0;i<n;i++) scanf("%d",&a[i]),a[i]--;
    memset(v,0,sizeof(int)*n);
    r=0;
    for(i=0;i<n;i++) if(!v[i]) {
      z=0; e=i;
      while(!v[e]) {
        v[e]=1;
        z++;
        e=a[e];
      }
      r+=dp[z];
    }
    printf("Case #%d: %.10f\n",caseno++,r);
  }
  return 0;
}
