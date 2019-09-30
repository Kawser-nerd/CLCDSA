#include <stdio.h>
#define MAX 100000
#define TRUE 1
#define FALSE 0

int main(void){
  
  int i,j,n,q;
  int Is_Prime[MAX+1];
  int cs[MAX+1];
  
  Is_Prime[0] = FALSE;
  Is_Prime[1] = FALSE;
  for( i=2; i<=MAX; i++){
    Is_Prime[i] = TRUE;
  }
  
  for( i=2; i<=MAX/2; i++){
    if( Is_Prime[i] == TRUE ){
      //printf("%d is PRIME\n",i);
      for( j=i+1; j<=MAX; j++){
        if( j % i == 0){
          Is_Prime[j] = FALSE;
        }
      }
    }
  }
    
  for( i=1,cs[0]=0; i<=MAX; i++){
    if( Is_Prime[i] == TRUE && Is_Prime[(i+1)/2] ){
      cs[i] = cs[i-1] + 1;
    }
    else cs[i] = cs[i-1];
  }
  
  scanf("%d",&n);
  for( q=0; q<n; q++){
    scanf("%d %d",&i,&j);
    printf("%d\n",cs[j]-cs[i-1]);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:36:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:38:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&i,&j);
     ^