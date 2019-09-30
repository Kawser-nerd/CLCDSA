#include <stdio.h>
#include <string.h>
int main(){
  char s[11],t[11],same=0,len;
  scanf("%s\n%s",s,t);
  len=strlen(s);
  for (int i=0;i<len;i++){
    if (s[i]=='@'){
      if (t[i]=='@' || t[i]=='a' || t[i]=='t' 
          || t[i]=='c' || t[i]=='o' || t[i]=='d' || t[i]=='e' || t[i]=='r'){
        same++;
      }
    }
    else if (t[i]=='@'){
      if (s[i]=='@' || s[i]=='a' || s[i]=='t' 
          || s[i]=='c' || s[i]=='o' || s[i]=='d' || s[i]=='e' || s[i]=='r'){
        same++;
      }
    }
    else if (s[i]==t[i]) same++;
  }
  if (same==len) printf("You can win\n");
  else printf("You will lose\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s\n%s",s,t);
   ^