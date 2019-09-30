#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
  int i,j;
  int l;
  double c = 0.0;
  int n,k;

  scanf("%d %d",&n,&k);

  int r[n];

  for(i=0; i<=n-1; i++){
    scanf("%d ",&r[i]);
  }

  for(i=0; i<=n-1; i++){
    for(j=i+1; j<=n-1; j++){
      if(r[j]<r[i]){
        l = r[i];
        r[i] = r[j];
        r[j] = l;
      }
    }
  }

  for(i=1; i<=k; i++){
    c = (double)(c + r[n-k+i-1])/2;
  }
  printf("%f\n",c);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&k);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d ",&r[i]);
     ^