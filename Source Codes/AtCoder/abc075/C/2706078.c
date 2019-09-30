#include<stdio.h>
#define M 50
int main(){
  int hoge=0,fuga=0,ans=0;
  int n,m;
  int i,j;
  int a[M],b[M],c[M]={};
  scanf("%d %d", &n,&m);
  for(i=0;i<m;i++)
    scanf("%d %d", &a[i],&b[i]);
  int count=1;
  while(count!=0){
    count=0;
    for(i=0;i<m;i++){
      if(c[i]==0){
        for(j=0;j<m;j++){
          if((i!=j)&&(c[j]==0)){
            if(a[i]==a[j]||a[i]==b[j])hoge++;
            if(b[i]==a[j]||b[i]==b[j])fuga++;
          }
        }
        if(hoge==0||fuga==0){
          ans++;
          c[i]=1;
          count++;
        }
        hoge=0;fuga=0;
      }
    }
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &n,&m);
   ^
./Main.c:10:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &a[i],&b[i]);
     ^