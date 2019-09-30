#include <stdio.h>
int abs(int x);

int main(){
  int a,b,c,d,e,f;
  double area;
  scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
  c-=a;
  d-=b;
  e-=a;
  f-=b;
  area=abs(c*f-e*d)/2.0;
  printf("%f\n",area);
  return 0;
}

int abs(int x){
  if (x<0) x=-x;
  return x;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
   ^