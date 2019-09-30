#include <stdio.h>
#define H_MAX 200
#define W_MAX 200
#define INF 9999
#define N 10

int main(void){
  int h,w;
  int i,j,k;
  int c[N][N];
  int a;
  int mp;
  
  scanf("%d %d",&h,&w);
  
  for( i=0; i<N; i++) for( j=0; j<N; j++){
    scanf("%d",&c[i][j]);
  }
  
  for( k=0; k<N; k++){
    for( j=0; j<N; j++){
      for( i=0; i<N; i++){
        if( c[i][j] > c[i][k] + c[k][j] ) c[i][j] = c[i][k] + c[k][j];
      }
    }
  }
  
  for( i=0, mp=0; i<h; i++) for( j=0; j<w; j++){
    scanf("%d",&a);
    if( a >= 0 ) mp += c[a][1];
  }
  
  printf("%d\n",mp);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&h,&w);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&c[i][j]);
     ^
./Main.c:29:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^