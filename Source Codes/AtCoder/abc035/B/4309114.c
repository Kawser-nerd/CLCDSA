#include<stdio.h>
#include<string.h>

int main(){
  int t,x=0,y=0,z=0;
  char s[111111];
  scanf("%s%d",s,&t);
  for(int i=0;i<strlen(s);i++){
    if(s[i]=='L') x--;
    else if(s[i]=='R') x++;
    else if(s[i]=='U') y++;
    else if(s[i]=='D') y--;
    else z++;
  }
  x=abs(x)+abs(y);
  if(t-1){
    if(x<z) x=(z-x)%2;
    else x-=z;
  }
  else x+=z;
  printf("%d\n",x);
} ./Main.c: In function ‘main’:
./Main.c:15:5: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
   x=abs(x)+abs(y);
     ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%d",s,&t);
   ^