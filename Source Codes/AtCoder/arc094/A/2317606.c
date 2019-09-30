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
    int a[3];
    scanf("%d %d %d",&a[0],&a[1],&a[2]);
      qsort(( void * )a , 3 , sizeof( a[0] ) , int_sort );
    int ans=0;
    while(a[2]-a[0]>1){a[0]+=2;ans++;}
    while(a[2]-a[1]>1){a[1]+=2;ans++;}
    if(a[0]==a[1]&&a[1]!=a[2])ans++;
    else if(a[0]!=a[1])ans+=2;
    printf("%d",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d",&a[0],&a[1],&a[2]);
     ^