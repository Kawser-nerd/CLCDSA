#include<stdio.h>

int main(){
  long n,i,j,k,flag;
  long cnt=0;
  char s[310][310];
  scanf("%ld",&n);
  for(i=0;i<n;i++)
    scanf("%s",s[i]);
  for(k=0;k<n;k++){
    flag=1;
    for(i=0;i<n-1;i++){
      for(j=i+1;j<n;j++){
        if(s[(i+k)%n][j]!=s[(j+k)%n][i]){
          flag=0;
          break;
        }
      }
      if(!flag) break;
    }
    cnt+=n*flag;
  }
  printf("%ld\n",cnt);
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld",&n);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s[i]);
     ^