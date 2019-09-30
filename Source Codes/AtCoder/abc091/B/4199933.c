#include<stdio.h>
#include<string.h>

int main(void){
  int i,j,n,m,max=0,ans;
  scanf("%d",&n);
  char s[n][10];
  for(i=0;i<n;i++){
    scanf("%s",s[i]);
  }
  scanf("%d",&m);
  char t[m][10];
  for(i=0;i<m;i++){
    scanf("%s",t[i]);
  }
  for(i=0;i<n;i++){
    ans=0;
    for(j=0;j<n;j++){
      if(strcmp(s[i],s[j])==0) ans++;
    }
    for(j=0;j<m;j++){
      if(strcmp(s[i],t[j])==0) ans--;
    }
    if(max<ans) max = ans;
  }
  printf("%d\n",max);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s[i]);
     ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&m);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",t[i]);
     ^