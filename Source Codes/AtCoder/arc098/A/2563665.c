#include<stdio.h>

int main(){
  int n,i,min=300000,j,cnt=0;
  char s[300010];
  scanf("%d",&n);
  scanf("%s",s);
  for(i=1;i<n;i++){
    if(s[i]=='E') cnt++;
  }
  min=cnt;
  for(i=1;i<n;i++){
    if(s[i]=='E') cnt--;
    if(s[i-1]=='W') cnt++;
    if(min>cnt) min=cnt;
  }
  printf("%d\n",min);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^