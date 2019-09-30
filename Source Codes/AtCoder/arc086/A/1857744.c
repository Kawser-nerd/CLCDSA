#include <stdio.h>
#include <stdlib.h>

/* ????? */
int int_sort( const void * a , const void * b ) {
  /* ???void*???????????int??cast?? */
  if( *( int * )a < *( int * )b ) {
    return -1;
  }
  else
  if( *( int * )a == *( int * )b ) {
    return 0;
  }
  return 1;
}

int main(void){
    int N,K;
    scanf("%d %d",&N,&K);
    int buri[200001]={};
    for(int i=0;i<N;i++){
        int kari;
        scanf("%d",&kari);
        buri[kari]++;
    }
      qsort(( void * )buri , 200001 , sizeof( buri[0] ), int_sort );
      int ans=0;
    for(int i=0;i<200001-K;i++){
        ans+=buri[i];
    }
    printf("%d",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&N,&K);
     ^
./Main.c:23:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&kari);
         ^