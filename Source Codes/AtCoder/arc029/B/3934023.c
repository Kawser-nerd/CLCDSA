#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<math.h>
#define inf 1072114514
#define llinf 4154118101919364364
#define mod 1000000007
#define pi 3.1415926535897932384

bool jud(int a,int b,int c,int d){
  int i;
  double st,fi,te,len,w,dc=c,dd=d;
  if(a<=c && b<=d){
    return true;
  }
  st=0.0;fi=pi/2.0;
  for(i=0;i<100;i++){
    te=(st+fi)/2;
    len=0.0;
    w=b;
    w*=cos(te);
    len+=w;
    w=a;
    w*=cos((pi/2.0)+te);
    len-=w;
    if(len<=dc){
      fi=te;
    }
    else{
      st=te;
    }
  }
  len=0.0;
  w=b;
  w*=cos(te);
  len+=w;
  w=a;
  w*=cos((pi/2.0)+te);
  len-=w;
  if(len>dc+((double)1e-9)){
    return false;
  }
  len=0.0;
  w=b;
  w*=sin(te);
  len+=w;
  w=a;
  w*=sin((pi/2.0)+te);
  len+=w;
  if(len<=dd){
    return true;
  }
  return false;
}

int main(void){
    int i,j,n,a,b,c,d,e;
    scanf("%d%d%d",&a,&b,&n);
    for(i=0;i<n;i++){
      scanf("%d%d",&c,&d);
      if(jud(a,b,c,d) || jud(b,a,c,d) || jud(a,b,d,c) || jud(b,a,d,c)){
        printf("YES\n");
      }
      else{
        printf("NO\n");
      }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:60:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&a,&b,&n);
     ^
./Main.c:62:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d%d",&c,&d);
       ^