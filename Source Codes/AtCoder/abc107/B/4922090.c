#include <stdio.h>
#include <string.h>

int
main(int argc, char *argv[])
{
  int H, W;
  char a[101][101];
  scanf("%d%d", &H, &W);
  for(int i = 0; i < H; i++){
    scanf("%s", a[i]);
    
  }

  int b[101]; int p = 0; int l = 0;

  for(int i = 0; i < H; i++){
    l = 0; 
    for(int j = 0; j < W; j++){
      if(a[i][j] == '#'){
	l += 1;
	break;
      }
    }
    if(l != 0){
      b[p] = i;
      p++;
    }
  }

  int c[101]; int q = 0;
  for(int j = 0; j < W; j++){
    l = 0;
    for(int i = 0; i < H; i++){
      if(a[i][j] == '#'){
	l += 1;
	break;
      }
    }
    if(l != 0){
      c[q] = j;
      q++;
    }
  }

   for(int i = 0; i < p; i++){
  for(int j = 0; j < q; j++){
    printf("%c", a[b[i]][c[j]]);
  }
  printf("\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &H, &W);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", a[i]);
     ^