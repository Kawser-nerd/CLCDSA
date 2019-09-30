# include <stdio.h>

int main(){
  int n;
  scanf("%d", &n);
  int q = n;
  int f_n = 0;
  for (int i = 0; i < 9; i++){
    f_n += q % 10;
    q /= 10;
    if(!q){
      break;
    }
  }
  if (!(n % f_n)){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^