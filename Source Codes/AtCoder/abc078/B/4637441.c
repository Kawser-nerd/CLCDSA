#include<stdio.h>

int main(){
    int num=1;
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    while(1){
        if(y*num+z*(num+1) > x) break;
        else num++;
    }
    printf("%d",num-1);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d %d", &x, &y, &z);
     ^