#include<stdio.h>
int main(){
  int i,j,max=0,min=1e9,c;
  char s[100010];
  scanf("%s",s);
  for(i=0;i<26;i++){
    max=0;
    c=0;
    for(j=0;s[j];j++){
      if(s[j]=='a'+i){
	if(max<c)max=c;
	c=0;
      }
      else c++;
    }//printf("%c:%d\n",i+'a',max);
    if(max<c)max=c;
    if(min>max)min=max;
  }
  printf("%d\n",min);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^