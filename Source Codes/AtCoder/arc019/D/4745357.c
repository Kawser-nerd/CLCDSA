#include<stdio.h>

int main(){
  int i,j,k;
  int arr[16]={0};
  char s[256][256];
  for(i=0;i<256;i++){
    for(j=0;j<256;j++){
      s[i][j]='.';
    }
  }
  for(i=0;i<13;i++){
    for(j=i*13;j<(i+1)*13;j++){
      for(k=0;k<13;k++){
        s[j][k*13+(arr[k]+j)%13]='O';
      }
    }
    for(j=0;j<13;j++){
      arr[j]+=j;
      arr[j]%=13;
    }
  }
  printf("150\n");
  for(i=0;i<150;i++){
    s[i][150]=0;
    printf("%s\n",s[i]);
  }
  return 0;
}