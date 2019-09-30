#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX_CX 100
#define MAX_CY 100

int max(int a,int b){
  if(a>b) return a;
  return b;
}

int main(void){
  int n,i,CY,CX,H,flag=0;
  scanf("%d",&n);
  int x[n],y[n],h[n];
  for(i=0;i<n;i++) scanf("%d %d %d",&x[i],&y[i],&h[i]);
  for(CX=0;CX<=MAX_CX;CX++){
    for(CY=0;CY<=MAX_CY;CY++){
      for(i=0;i<n;i++) if(h[i]) break;
      H = h[i] + abs(x[i]-CX) + abs(y[i]-CY);
      for(i=0;i<n;i++){
        if(h[i]!=max(H-abs(x[i]-CX)-abs(y[i]-CY),0)) break;
      }
      if(i==n) flag=1;
      if(flag) break;
    }
    if(flag) break;
  }
  printf("%d %d %d\n",CX,CY,H);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:17:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d %d %d",&x[i],&y[i],&h[i]);
                    ^