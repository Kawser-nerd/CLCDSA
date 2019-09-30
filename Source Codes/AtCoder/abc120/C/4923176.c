#include <stdio.h>
#include <string.h>

int main(void)
{
  int n,i,j,k;
  char s[100000];

  scanf("%s",s);
  n=strlen(s);
  j=0;
  k=0;
  for(i=0;i<n;i++){
        if(s[i]=='0') j++;
        else if(s[i]=='1') k++;
        }
  if(j<k) printf("%d\n",j*2);
  else if(j>k) printf("%d\n",k*2);
  else printf("%d\n",j*2);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^