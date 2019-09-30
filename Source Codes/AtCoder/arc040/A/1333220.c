#include<stdio.h>
int main(){
  int b, c,N, x=0, y=0;
  char s[256][256]={};
  scanf("%d", &N);
  for(c=0;c<N;c++){
     scanf("%s", &s[c]);
  }
  for(c=0;c<N;c++){
    for(b=0;b<N;b++){
    if(s[c][b]=='R')x++;
    else if(s[c][b]=='B')y++;
  }
  }
  if(x>y)printf("TAKAHASHI\n");
  else if(y>x)printf("AOKI\n");
  else if(x==y)printf("DRAW\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:12: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[256]’ [-Wformat=]
      scanf("%s", &s[c]);
            ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:7:6: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
      scanf("%s", &s[c]);
      ^