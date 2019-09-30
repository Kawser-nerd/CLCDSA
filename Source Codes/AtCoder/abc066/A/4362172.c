# include <stdio.h>

int min(int a,int b, int c){
  int m=a+b;
  if(m>b+c) m=b+c;
  if(m>c+a) m=c+a;
  return m;
}
int main(){
  int a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  printf("%d\n",min(a,b,c));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&a,&b,&c);
   ^