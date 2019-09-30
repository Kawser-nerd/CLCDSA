#include <stdio.h>

int b[3][3],c[3][3];
int data[3][3];

int max(int a,int b){
  if(a > b){
    return a;
  }
  return b;
}

int min(int a,int b){
  if(a < b){
    return a;
  }
  return b;
}

void init(){
  for(int i = 0;i < 3;i++){
    for(int j = 0;j < 3;j++){
      data[i][j] = 0;
    }
  }
}

int hyouka(){
  int chokudai = 0;
  for(int i = 0;i < 2;i++){
    for(int j = 0;j < 3;j++){
      if(data[i][j] == data[i+1][j]) chokudai += b[i][j];
      else chokudai -= b[i][j];
    }
  }
  for(int i = 0;i < 3;i++){
    for(int j = 0;j < 2;j++){
      if(data[i][j] == data[i][j+1]) chokudai += c[i][j];
      else chokudai -= c[i][j];
    }
  }

  return chokudai;
}

int maximam(int depth);
int minimam(int depth);

int maximam(int depth){
  if(depth == 9) return hyouka(data);

  int MAX = -10000000;
  for(int i = 0;i < 3;i++){
    for(int j = 0;j < 3;j++){
      if(data[i][j]) continue;
      data[i][j] = 1;
      MAX = max(MAX,minimam(depth+1));
      data[i][j] = 0;
    }
  }

  return MAX;
}

int minimam(int depth){
  if(depth == 9) return hyouka(data);

  int MIN = 1000000;
  for(int i = 0;i < 3;i++){
    for(int j = 0;j < 3;j++){
      if(data[i][j]) continue;
      data[i][j] = 2;
      MIN = min(MIN,maximam(depth+1));
      data[i][j] = 0;
    }
  }

  return MIN;
}


int main(void){
  int maxpoint = 0;
  int point = 0;
  for(int i = 0;i < 2;i++){
    for(int j = 0;j < 3;j++){
      scanf("%d",&b[i][j]);
      maxpoint += b[i][j];
    }
  }
  for(int i = 0;i < 3;i++){
    for(int j = 0;j < 2;j++){
      scanf("%d",&c[i][j]);
      maxpoint += c[i][j];
    }
  }

  init();
  point = maximam(0);
  printf("%d\n%d\n",(maxpoint+point)/2,(maxpoint-point)/2);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:87:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&b[i][j]);
       ^
./Main.c:93:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&c[i][j]);
       ^