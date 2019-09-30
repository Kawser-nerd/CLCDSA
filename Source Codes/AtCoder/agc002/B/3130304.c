#include<stdio.h>

int main(){
  int n,m,x,y,f[100010]={},cnt[100010],ans=0;
  scanf("%d %d",&n,&m);
  f[1]=1;
  for(int i=1;i<=n;i++)
    cnt[i]=1;
  for(int i=0;i<m;i++){
    scanf("%d %d",&x,&y);
    if(f[x]==1)
      f[y]=1;
    if(cnt[x]==1)
      f[x]=0;
    cnt[x]--;
    cnt[y]++;
  }
  for(int i=1;i<=n;i++)
    ans+=f[i];
  printf("%d\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&x,&y);
     ^