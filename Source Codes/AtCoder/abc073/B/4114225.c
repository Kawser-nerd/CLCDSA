# include <stdio.h>

int main(){
  int n;
  int num = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    int l, r;
    scanf("%d %d",&l, &r);
    num += r - l + 1;
  }
  printf("%d\n",num);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&l, &r);
     ^