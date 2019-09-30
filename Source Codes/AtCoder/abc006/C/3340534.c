#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
  int k;
  int l=0;
  int i,j;
  int n,m;

  scanf("%d %d",&n,&m);

  k = m/3;

  if(m<2*n || m>4*n){
    l=0;
  }else{
    for(i=0; i<=k; i++){
      if(l>0){
        break;
      }
      if((m-3*i)%2==0){
        //printf("t\n");
        if((m-3*i)>2*(n-i) || (m-3*i)<4*(n-i)){
          //ssprintf("y\n");
          for(j=0; j<=n-i; j++){
            if(2*j+4*(n-i-j)==(m-3*i)){
              l++;
              printf("%d %d %d\n",j,i,n-i-j);
              break;
            }
          }
        }
      }
    }
  }

  if(l==0){
    printf("-1 -1 -1\n");
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^