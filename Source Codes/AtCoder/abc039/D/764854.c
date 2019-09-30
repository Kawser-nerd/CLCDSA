#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 102
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
int main(void){
  int w,h,i,j;
  char a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
  scanf("%d %d\n",&h,&w);
  for(i = 1; i <= h; ++i){
    for(j = 1; j <= w; ++j){
      scanf("%c",&a[i][j]);
    }
    scanf("\n");
  }
  for(i = 0; i <= w+1; ++i){
    a[0][i] = '#';
    a[h+1][i] = '#';
  }
  for(i = 1; i <= h; ++i){
    a[i][0] = '#';
    a[i][w+1] = '#';
  }
  
  for(i = 1; i <= h; ++i){
    for(j = 1; j <= w; ++j){
      if((a[i-1][j-1] == '#')&&
	 (a[i-1][j] == '#')&&
	 (a[i-1][j+1] == '#')&&
	 (a[i][j-1] == '#')&&
	 (a[i][j] == '#')&&
	 (a[i][j+1] == '#')&&
	 (a[i+1][j-1] == '#')&&
	 (a[i+1][j] == '#')&&
	 (a[i+1][j+1] == '#')){
	b[i][j] = '#';
      }
      else{
	b[i][j] = '.';
      }
    }
  }

  for(i = 1; i <= h; ++i){
    for(j = 1; j <= w; ++j){
      if(b[i][j] == '#'){
	a[i-1][j-1] = '.';
	a[i-1][j] = '.';
	a[i-1][j+1] = '.';
	a[i][j-1] = '.';
	a[i][j] = '.';
	a[i][j+1] = '.';
	a[i+1][j-1] = '.';
	a[i+1][j] = '.';
	a[i+1][j+1] = '.';
      }
    }
  }

  
  for(i = 1; i <= h; ++i){
    for(j = 1; j <= w; ++j){
      if(a[i][j] == '#'){
	printf("impossible");
	return 0;
      }
    }
  }
  printf("possible\n");
  for(i = 1; i <= h; ++i){
    for(j = 1; j <= w; ++j){
      printf("%c",b[i][j]);
      if(j == w && i != h)
	printf("\n");
    }
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d\n",&h,&w);
   ^
./Main.c:13:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%c",&a[i][j]);
       ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("\n");
     ^