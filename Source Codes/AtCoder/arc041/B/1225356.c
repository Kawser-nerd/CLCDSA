#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
  int N,M,NM,m,t;
  char *a,*b,*p,*q,*n,*e,*w,*s;
  scanf("%d%d\n",&N,&M);
  NM=N*-~M;
  b=malloc(NM);
  a=malloc(NM);
  fread(b,1,NM,stdin);
  memset(a,48,NM);
  a[M]=10;
  p=b;
  q=&a[M+1];
  n=b;
  w=&b[M];
  e=&b[M+2];
  s=&b[M+M+2];
  while(--N){
    for(m=M-2;m;--m){
      
      ++p;++q;++n;++e;++w;++s;
      if(*p^48){
	t=(*q=*p)-48;
	*n-=t;*w-=t;*e-=t;*s-=t;
      }
    }
    *(q+2)=10;
    p+=3;q+=3;n+=3;e+=3;w+=3;s+=3; 

  }
  fwrite(a,1,NM,stdout);
  free(b);free(a);
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d\n",&N,&M);
   ^
./Main.c:12:3: warning: ignoring return value of ‘fread’, declared with attribute warn_unused_result [-Wunused-result]
   fread(b,1,NM,stdin);
   ^