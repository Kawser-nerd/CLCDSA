#include<stdio.h>
#include<string.h>
int main(){
  int n,i,j,k,ans=0;
  char s[1010][1010];
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%s",s[i]);
  for(i=0;i<n;i++)strcpy(s[i+n],s[i]);
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      for(k=0;k<n;k++){
	if(s[i+j][k]-s[i+k][j])goto END;
      }
    }
    ans+=n;
  END:;
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:7:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%s",s[i]);
                   ^