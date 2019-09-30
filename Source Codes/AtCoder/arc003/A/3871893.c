#include <stdio.h>
#include <string.h>
int main(){
  int n,sum=0;
  scanf("%d",&n);
  char s[n+1];
  scanf("%s",s);
  for(int i=0;i<strlen(s);i++){
    if(s[i]=='A')sum+=4;
    if(s[i]=='B')sum+=3;
    if(s[i]=='C')sum+=2;
    if(s[i]=='D')sum+=1;
    if(s[i]=='F')sum+=0;
  }
  //printf("%d\n",sum);
      double GPA=(((double)sum)/((double)n));
      printf("%1.15lf\n",GPA);
      return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^