# include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    char color;
    scanf("%c", &color);
    if (color == 'Y'){
      printf("%s\n","Four");
      return 0;
    }
  }
  printf("%s\n","Three");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%c", &color);
     ^