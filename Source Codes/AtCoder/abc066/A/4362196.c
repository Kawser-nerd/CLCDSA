# include <stdio.h>

int max(int a,int b,int c){
  int m=a;
  if(m<b) m=b;
  if(m<c) m=c;
  return m;
}
int main(){
  int a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  printf("%d\n",a+b+c-max(a,b,c));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&a,&b,&c);
   ^