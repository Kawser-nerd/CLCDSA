#include<stdio.h>

int main(void)
{
  int m;
  scanf("%d",&m);
  if(m<100) {
      m=0;
  }else if(m<=5000){
    m=m/100;
  }else if(m<=30000){
    m=m/1000+50;
  }else if(m<=70000){
    m=(m/1000-30)/5+80;
  }else{
    m=89;
  }

  printf("%02d\n",m);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&m);
   ^