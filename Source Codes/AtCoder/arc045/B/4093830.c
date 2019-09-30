#include<stdio.h>
#include<stdlib.h>

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int *s=(int *)calloc(m,sizeof(int));
  int *t=(int *)calloc(m,sizeof(int));
  int *cnt=(int *)calloc(n+2,sizeof(int));
  int i;
  for(i=0;i<m;i++){
    scanf("%d%d",s+i,t+i);
    cnt[s[i]]++;
    cnt[t[i]+1]--;
  }
  for(i=1;i<=n;i++) cnt[i]+=cnt[i-1];
  for(i=1;i<=n;i++) cnt[i]=(cnt[i]>1?0:1);
  for(i=1;i<=n;i++) cnt[i]+=cnt[i-1];
  int ans=0;
  for(i=0;i<m;i++) if(cnt[t[i]]-cnt[s[i]-1]==0) ans++;
  printf("%d\n",ans);
  for(i=0;i<m;i++) if(cnt[t[i]]-cnt[s[i]-1]==0) printf("%d\n",i+1);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",s+i,t+i);
     ^