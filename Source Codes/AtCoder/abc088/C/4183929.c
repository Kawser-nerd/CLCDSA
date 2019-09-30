#include <stdio.h>

int min(int a,int b){
  if(a < b){
    return a;
  }
  return b;
}

int main(void){
  int data[3][3];
  int b[3];

  for(int i = 0;i < 3;i++){
    for(int j = 0;j < 3;j++){
      scanf("%d",&data[i][j]);
    }
  }


  for(int i = 0;i <= min(min(data[0][0],data[0][1]),data[0][2]);i++){
    b[0] = data[0][0]-i;
    b[1] = data[0][1]-i;
    b[2] = data[0][2]-i;
    int flag = 0;
    for(int j = 1;j < 3;j++){
      if(data[j][0]-b[0] == data[j][1]-b[1] && data[j][1]-b[1] == data[j][2]-b[2]){
        if(data[j][0]-b[0] >= 0){
          flag++;
        }
      }
    }
    if(flag == 2){
      printf("Yes\n");
      return 0;
    }
  }

  printf("No\n");

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&data[i][j]);
       ^