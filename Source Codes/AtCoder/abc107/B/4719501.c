#include<stdio.h>
short h, w, i, j;
char m[100][101];
char row[100], col[100];
int main(void){
  scanf("%hd%hd", &h, &w);
  register char f;
  for(i=0; i<h; i++){
    scanf("%s", m[i]);
    for(j=0; j<w; j++){
      if(m[i][j]=='#'){
        row[i]=1;
        col[j]=1;
      }
    }
  }
  for(i=0; i<h; i++){
    for(j=0; j<w; j++){
      if(row[i]==1 && col[j]==1){
        putchar(m[i][j]);
      }
    }
    if(row[i]==1){
      putchar(10);
    }
  }
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%hd%hd", &h, &w);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", m[i]);
     ^