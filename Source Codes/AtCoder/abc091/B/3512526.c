#include <stdio.h>
#include <string.h>
int main(){
  int n,m,i,j;
  char s[101][101],t[101][101];
  scanf("%d",&n);
  for(i=0;i<n;i++){
      scanf("%s",s[i]);
  }
  scanf("%d",&m);
  for(i=0;i<m;i++){
      scanf("%s",t[i]);
  }
  int ans=0;
  for(i=0;i<n;i++){
      int cnt=0;
      for(j=0;j<n;j++){
          if(strcmp(s[i],s[j])==0){
              cnt++;
          }
      }
      for(j=0;j<m;j++){
          if(strcmp(s[i],t[j])==0){
              cnt--;
          }
      }
      if(cnt>ans){
          ans=cnt;
      }
  }
  printf("%d",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:8:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%s",s[i]);
       ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&m);
   ^
./Main.c:12:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%s",t[i]);
       ^