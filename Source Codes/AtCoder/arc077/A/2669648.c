#include<stdio.h>

int main(){
  int i,n,j;
  long a[200000],b[200000];
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%ld",&a[i]);
  j=0;
  for(i=n-1;i>=0;i--){
    if(j%2==0){
      b[j/2]=a[i];
    }
    else{
      b[n-1-(j/2)]=a[i];
    }
    j++;
  }
  for(i=0;i<n;i++)
    printf("%ld ",b[i]);
  printf("\n");
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&a[i]);
     ^