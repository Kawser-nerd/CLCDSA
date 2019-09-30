#include <stdio.h>
#define abs(x) (x>0) ? x : -x
#define TRUE 1
#define FALSE 0

long long int psum( int pattern, long long int x, long long int y, long long int z){
  long long int sum=0;
  
  sum += ( pattern % 2 < 1 ) ? x : -x;
  sum += ( pattern % 4 < 2 ) ? y : -y;
  sum += ( pattern % 8 < 4 ) ? z : -z;
  
  return sum;
}

int main(void){
  
  int Is_swaped,h,i,j,p,n,m;
  long long int ans[8],x[1000],y[1000],z[1000],w[1000],temp[3];
  
  scanf("%d %d",&n,&m);
  for( i=0; i<n; i++) scanf("%lld %lld %lld",&x[i],&y[i],&z[i]);
  
  for( p=0; p<8; p++){
    h = n;
    Is_swaped = FALSE;
    
    while( h>1 || Is_swaped == TRUE ){
      if( h>1 ){
        h = ( h * 10 ) / 13;
      }
      
      Is_swaped = FALSE;
      for( i=0; i<n-h; i++){
        if( psum(p,x[i],y[i],z[i]) < psum(p,x[i+h],y[i+h],z[i+h]) ){
          // swap
            temp[0] = x[i];   temp[1] = y[i];   temp[2] = z[i];
             x[i] = x[i+h];    y[i] = y[i+h];    z[i] = z[i+h];
          x[i+h] = temp[0]; y[i+h] = temp[1]; z[i+h] = temp[2];
          Is_swaped = TRUE;
        }
      }
    }
    
    for( ans[p]=0, i=0; i<m; i++) ans[p] += psum(p, x[i], y[i], z[i]);
  }
  
  h = 8;
  Is_swaped = FALSE;
  while( h>1 || Is_swaped == TRUE ){
    if( h>1 ){
      h = ( h * 10 ) / 13;
    }
    
    Is_swaped = FALSE;
    for( i=0; i<8-h; i++){
      if( ans[i] < ans[i+h] ){
        // swap
        p = ans[i];
        ans[i] = ans[i+h];
        ans[i+h] = p;
        Is_swaped = TRUE;
      }
    }
  }
  
  printf("%lld\n",ans[0]);
    
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:22:23: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for( i=0; i<n; i++) scanf("%lld %lld %lld",&x[i],&y[i],&z[i]);
                       ^