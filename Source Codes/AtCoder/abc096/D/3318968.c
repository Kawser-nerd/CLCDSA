#include <stdio.h>
#include <math.h>

int sosuufi(int n){
  int i;
  int flag=1;
  for(i=2;i<=(int)sqrt(n);i++){
    if(n%i==0){
      flag=0;
    }
  }
  return flag;
}

void sosuu(int*A){
  int i;
  int k=0;
  for(i=6;i<=55555;i++){
    if(i%5==1 && sosuufi(i)==1){
      A[k]=i;
      k++;
    }
    if(k>55){
      break;
    }
  }
}

int main(){
  int n;
  scanf("%d",&n);
  int A[55];
  sosuu(A);
  int i;
  for(i=0;i<n;i++){
    printf("%d ",A[i]);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^