#include <stdio.h>

void bubbleSort(int a[], int len){
  int i,j;

  for(i=0; i<len; i++){
    for(j=len-1; j>i; j--){
      if(a[j] < a[j-1]){
        int temp;
        temp = a[j];
        a[j] = a[j-1];
        a[j-1] = temp;
      }
    }
  }
}

int main(){
  int n,x;
  scanf("%d%d",&n,&x);
  int a[n];
  int i;
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  bubbleSort(a,n);
  int ans = 0;
  while(ans<n){
    //printf("a[%d], %d\n",ans,a[ans]);
    if(x<a[ans]){
      break;
    }
    if(ans==n-1 && x != a[ans]){
      break;
    }
    x = x - a[ans];
    ans++;
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&x);
   ^
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a[i]);
     ^