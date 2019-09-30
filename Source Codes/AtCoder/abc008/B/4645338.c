#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(void){
  int n;
  scanf("%d",&n);
  int a[n],i,j,max=0;
  char s[n][51];
  for(i=0;i<n;i++){
    scanf("%s",s[i]);
    a[i]=0;
  }
  for(i=0;i<n;i++){
    for(j=i;j<n;j++){
      if(strcmp(s[i],s[j])==0) a[i]++;
    }
  }
  for(i=0;i<n;i++){
    if(max<a[i]){
      max=a[i];
      j=i;
    }
  }
  printf("%s\n",s[j]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s[i]);
     ^