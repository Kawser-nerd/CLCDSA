#include <stdio.h>
#include <string.h> 

int main(void){
  char s[2000001];
  scanf("%s", s);

  int len = strlen(s);
  long long num=len,lap=0,a,b=0;
  
    for(int i=len-1;i>=0;i-=1){
   	 if(s[i]=='W'){
      a=(num-i-1)*lap;
      b+=a;
      lap++;
      num=i;
     }
    }
  
  	printf("%lld", b+num*lap);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^