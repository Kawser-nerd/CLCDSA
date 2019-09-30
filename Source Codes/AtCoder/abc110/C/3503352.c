#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main(void){
  int i,l;
  char s[200002],t[200002];
  char R1[30],R2[30];
  for(i=0;i<30;i++){
    R1[i]=-1;R2[i]=-1;
  }
  scanf("%s",s);
  scanf("%s",t);
  l=strlen(s);
  for(i=0;i<l;i++){
    if(R1[s[i]-'a']>0){
      if(t[i]!=R1[s[i]-'a']){
	printf("No\n");
	return 0;
      }
    }
    if(R2[t[i]-'a']>0){
      if(R2[t[i]-'a']!=s[i]){
	printf("No\n");
	return 0;
      }
    }
    if(R1[s[i]-'a']<0)
      R1[s[i]-'a']=t[i];
    if(R2[t[i]-'a']<0)
      R2[t[i]-'a']=s[i];
  } 
  printf("Yes\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",t);
   ^