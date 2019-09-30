#include <stdio.h>
#include <stdlib.h>

int int_sort(const void *a, const void *b) {
  if( *(int *)a > *(int *)b ) {
    return -1;
  }else if( *(int *)a == *(int *)b ) {
    return 0;
  }
  return 1;
}

int main(){
  int n;
  scanf("%d", &n);
  int i;
  int a[n];
  int used[n];
  for(i=0;i<n;i++){
    used[i] = 0;
    scanf("%d", &a[i]);
  }
  qsort(a, n, sizeof(int), int_sort);
  int ans = 0;
  long long int max = 1;
  while(max <= a[0]){
    max = max * 2;
  }
  int j = n - 1;
  for(i=0;i<n;i++){
    if(used[i] == 1){
      continue;
    }
    while(a[i] < max / 2){
      max = max / 2;
      j = n - 1;
    }
    while(a[j]<=max-a[i] && i<j){
      if(a[j] == max-a[i] && used[j] == 0){
        ans++;
        //used[i] = 1;
        used[j] = 1;
        j--;
        break;
      }
      j--;
    }
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a[i]);
     ^