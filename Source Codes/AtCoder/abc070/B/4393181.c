#include<stdio.h>

int mini(int a,int b){
  if(a>b) return b;
  return a;
}

int max(int a,int b){
  if(a>b) return a;
  return b;
}

int main(void){
  int a,b,c,d,start,end;
  scanf("%d %d %d %d",&a,&b,&c,&d);
  start=max(a,c);
  end=mini(b,d);
  printf("%d\n",max(end-start,0));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d",&a,&b,&c,&d);
   ^