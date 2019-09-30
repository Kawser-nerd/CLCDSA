#include<stdio.h>
#include<stdlib.h>
int compare_short(const void *a, const void *b){
    return *(short*)b - *(short*)a;
}

int n, i;
short a[100];
int ans[2];
int main(){
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%hd", a+i);
  }
  qsort(a, n, sizeof(short), compare_short);
  for(i=0; i<n; i++){
    ans[i&1] += a[i];
  }
  printf("%d\n", ans[0]-ans[1]);
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%hd", a+i);
     ^