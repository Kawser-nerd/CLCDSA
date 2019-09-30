#include<stdio.h>
int main()
{
  int a, b, i;
  scanf("%d %d", &a, &b);
  char s[a+b+2];
  scanf("%s", s);
  for(i=0;i<a;i++){
    if(s[i]=='-'){
      printf("No\n");
      return 0;
    }else{}
    for(i=a+1;i<a+b+1;i++){
      if(s[i]=='-'){
        printf("No\n");
        return 0;
      }else{}
    }
  }
  if(s[a]!='-'){
    printf("No\n");
  }else{
    printf("Yes\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &a, &b);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^