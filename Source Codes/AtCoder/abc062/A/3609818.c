#include<stdio.h>

int main(){
  int x, y, x_group, y_group;
  
  scanf("%d %d", &x, &y);
  
  if(x == 2){
    x_group = 3;
  } else if(x == 4 || x == 6 || x == 9 || x == 11){
    x_group = 2;
  } else {
    x_group = 1;
  }
  if(y == 2){
    y_group = 3;
  } else if(y == 4 || y == 6 || y == 9 || y == 11){
    y_group = 2;
  } else {
    y_group = 1;
  }
  
  if(x_group == y_group){
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &x, &y);
   ^