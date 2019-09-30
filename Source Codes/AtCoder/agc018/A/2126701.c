#include <stdio.h>

int main(){
  int i,j,n,k,min,max;

  scanf("%d %d",&n,&k);
  int a[n];
  scanf("%d",&a[0]);
  min=a[0];
  max=a[0];
  for(i=1;i<n;i++){
    scanf(" %d",&a[i]);
    if(min>a[i]) min=a[i];
    if(max<a[i]) max=a[i];
  }
  if(max<k){
    printf("IMPOSSIBLE");
    return 0;
  }
  if(min==1){
    printf("POSSIBLE");
    return 0;
  }

  for(i=min;i>=1;i--){
    for(j=0;j<n;j++){
      if(a[j]%i!=0) break;
    }
    if(j==n){
      if(k%i==0){
        printf("POSSIBLE");
        return 0;
      } else{
        printf("IMPOSSIBLE");
        return 0;
      }
    }
  }
  //printf("IMPOSSIBLE");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&k);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[0]);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf(" %d",&a[i]);
     ^