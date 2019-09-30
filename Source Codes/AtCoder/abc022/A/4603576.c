#include <stdio.h>
int main(void){
int n,s,t;
  int w;
  int count;
  int po[10000];
  int nissu=0;
  scanf("%d %d %d",&n,&s,&t);
  scanf("%d",&w);
  for(count=0;n-1>=count;count++){
  scanf("%d",&po[count]);
  }
  if(s<=w&&w<=t){nissu++;}
  
  
  for(count=0;n-2>=count;count++){
  w=w+po[count];
    if(s<=w&&w<=t){nissu++;}
  }
  
  
  printf("%d\n",nissu);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&n,&s,&t);
   ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&w);
   ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&po[count]);
   ^