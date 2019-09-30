#include<stdio.h>

#define SQ(x) ((x)*(x))
#define MIN(x,y) (((x)<(y))?(x):(y))

int main(void){
  int sum,a[100],N,ave;
  int i,j,k,c1,c2,c3;
  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d",a+i);
  sum=0;
  for(i=0;i<N;i++) sum+=a[i];

  c1=0;
  ave=sum/N;
  for(i=0;i<N;i++) c1+=SQ(ave-a[i]);
  ave++;
  c2=0;
  for(i=0;i<N;i++) c2+=SQ(ave-a[i]);
  ave-=2;
  c3=0;
  for(i=0;i<N;i++) c3+=SQ(ave-a[i]);


  printf("%d\n",MIN(MIN(c1,c2),c3));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:10:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<N;i++) scanf("%d",a+i);
                    ^