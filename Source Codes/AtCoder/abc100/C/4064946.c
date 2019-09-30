#include<stdio.h>
inline int getint(){
  int ret = 0,f = 1;
  char c = getchar();
  while(c<'0'||c>'9'){
    if(c=='-')f=-1;
    c = getchar();
  }
  while(c>='0'&&c<='9')
    ret=ret*10+c-'0',c=getchar();
  return ret*f;
}
int N,a,t,s=0;
int main(){
  N=getint();
  while(N--){
    a=getint();
    asm volatile(
      "bsf %0,%1\n\t"
      :"=r"(t)
      :"r"(a)
    );
    s+=t;
  }
  printf("%d\n",s);
}