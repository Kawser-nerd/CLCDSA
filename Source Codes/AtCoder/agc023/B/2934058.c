#include<stdio.h>

int main(){
  int n;
  long ans=0,flag;
  char s[310][310];
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    scanf("%s",s[i]);
  for(int k=0;k<n;k++){
    flag=1;
    for(int i=0;i<n;i++)
      for(int j=i+1;j<n;j++)
        if(s[(i+k)%n][j]!=s[(j+k)%n][i]){
          flag=0;
          break;
        }
    ans+=(long)flag*n;
  }
  printf("%ld\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s[i]);
     ^