#include <stdio.h>
#include <stdlib.h>
 
int comp( const void *c1, const void *c2 );
 
int main(){
  int n, a[100001]={0}, i, c, m, t;

  scanf("%d", &n);
  for( i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  qsort(a, n, sizeof(int), comp);
  c = 0;
  m = a[0];
  t = 1;
  for( i = 1; i <= n; i++){
     if(a[i] == a[i-1]){
       t++;
     }else{ 
        if(t > m){
            c += t - m;
        }else if(t < m){
            c += t;
        }
        t = 1;
        m = a[i];
    }
  }
  printf("%d\n", c);

  return 0;
}

int comp( const void *c1, const void *c2 )
{
  int tmp1 = *(int *)c1;
  int tmp2 = *(int *)c2;
 
  if( tmp1 > tmp2 )  return -1;
  if( tmp1 == tmp2 ) return  0;
  if( tmp1 < tmp2 )  return  1;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a[i]);
     ^