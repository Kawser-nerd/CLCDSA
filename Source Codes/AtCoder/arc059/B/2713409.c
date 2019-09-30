#include<stdio.h>
#include<string.h>

int main(){
  int i,n;
  char s[100001];
  scanf("%s",s);
  n=strlen(s);
  for(i=0;i<n-2;i++){
    if(s[i]==s[i+1]){
      printf("%d %d\n",i+1,i+2);
      return 0;
    }
    else if(s[i]==s[i+2]){
      printf("%d %d\n",i+1,i+3);
      return 0;
    }
  }
  if(s[n-2]==s[n-1]){
    printf("%d %d\n",n-1,n);
    return 0;
  }
  printf("-1 -1\n");
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^