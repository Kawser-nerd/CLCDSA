# include <stdio.h>

int main(){
double i,j;
  scanf("%lf",&i);
  
  j = i/1000;
    
  if(j<0.1) printf("00\n");
  else if(j>=0.1 && j<=5) printf("%02.0f\n",j*10);
  else if(j>=6 && j<=30) printf("%2.0f\n",j+50);
  else if(j>=35 && j<=70)printf("%2.0f\n",(j-30)/5+80);
  else if(j > 70) printf("89\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf",&i);
   ^