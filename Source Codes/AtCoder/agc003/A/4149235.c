#include <stdio.h>

int main(){
  char s[1001];
  int i,N,W,E,S;
  scanf("%s",s);
  i=0;N=0;W=0;E=0;S=0;
  while(s[i]!=NULL){
	if(s[i]=='N')N=1;
    if(s[i]=='W')W=-1;
    if(s[i]=='E')E=1;
    if(s[i]=='S')S=-1;
    i++;
  }
  if((N+S)==0 && (W+E)==0)printf("Yes\n");
  else printf("No\n");
} ./Main.c: In function ‘main’:
./Main.c:8:13: warning: comparison between pointer and integer
   while(s[i]!=NULL){
             ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^