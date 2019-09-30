#include <stdio.h>
int maxf(int a,int b,int c);
int minf(int a,int b,int c);
int main(void){
int a,b,c;
int max,min;
  scanf("%d",&a);
  scanf("%d",&b);
  scanf("%d",&c);
  max=maxf(a,b,c);
  min=minf(a,b,c);
  if((b==max&&c==min)||(c==max&&b==min)){printf("2\n");}
  else if(a==max){printf("1\n");}
  else if(a==min){printf("3\n");}


 if((a==max&&c==min)||(c==max&&a==min)){printf("2\n");}
  else if(b==max){printf("1\n");}
  else if(b==min){printf("3\n");}

if((b==max&&a==min)||(a==max&&b==min)){printf("2\n");}
  else if(c==max){printf("1\n");}
  else if(c==min){printf("3\n");}


return 0;
}

int maxf(int a,int b,int c){
int maxa;
maxa=a;
if(maxa<=b){maxa=b;}
if(maxa<=c){maxa=c;}
    return maxa;
}
int minf(int a,int b,int c){
int mina;
mina=a;
if(mina>=b){mina=b;}
if(mina>=c){mina=c;}
    return mina;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&b);
   ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&c);
   ^