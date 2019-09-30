#include <stdio.h>
int main(void){
char s[200005];
  int count,fin,start,max=0;
  scanf("%s",s);
  for(count=0;;count++){
  if(s[count]=='A'){start=count;break;}
  }
    for(count=0;;count++){
  if(s[count]=='Z'){fin=count;}
      if(s[count]=='\0'){break;}
  }
  printf("%d",fin-start+1);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^