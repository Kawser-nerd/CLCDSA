#include <stdio.h>
#include <stdlib.h>
 
/* ????? */
int int_sort( const void * a , const void * b ) {
  /* ???void*???????????int??cast?? */
  if( *( int * )a < *( int * )b ) {
    return 1;
  }
  else
  if( *( int * )a == *( int * )b ) {
    return 0;
  }
  return -1;
}
 
int main(void){
    int N;
    scanf("%d",&N);
    int a[N];
    for(int i=0;i<N;i++){
        scanf("%d",&a[i]);
    }
    qsort((void*)a,N,sizeof(a[0]),int_sort);
    long long int ans1=0;
    long long int ans2=0;
    for(int i=1;i<N;i++){
        if(a[i]==a[i-1]&&ans1==0){ans1=a[i];if(i!=N-1)i++;}
        else if(a[i]==a[i-1])ans2=a[i];
        if(ans2!=0)break;
    }
    long long int po=ans1*ans2;
    printf("%lld",po);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&N);
     ^
./Main.c:22:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^