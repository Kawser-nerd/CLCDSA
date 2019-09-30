#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>

int n;
char *b[300];

int main()
{
  int i,x,y,cnt=0;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    b[i] = (char*)malloc(310);
    scanf("%s",b[i]);
  }
  if( n==1 ){
    printf("1\n");
    exit(0);
  }
  for(i=0;i<n;i++){
    int no = 0;
    for(x=1;x<n;x++){
      for(y=0;y<x;y++){
        if( b[(x+i)%n][y] != b[(y+i)%n][x] ){
          no = 1;
          break;
        }
      }
      if( no==1 ) break;
    }
    if( no != 1 ) cnt += n;
  }
  printf("%d\n",cnt);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",b[i]);
     ^