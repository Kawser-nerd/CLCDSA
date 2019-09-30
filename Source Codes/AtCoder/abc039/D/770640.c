#include<stdio.h>

int ifexist(int judge[102][102],int i, int j){
  if(judge[i-1][j-1] == 2 || judge[i-1][j] == 2 || judge[i-1][j+1] == 2 || judge[i][j-1] == 2 || judge[i][j+1] == 2 || judge[i+1][j-1] == 2 || judge[i+1][j] == 2 || judge[i+1][j+1] == 2) return 0;
  else return 1;
}

int makejudge(char input[102][102],int i, int j, int h, int w){
  if(i == 0 || i == h+1 || j == 0 || j == w+1) return 0;
  else if(input[i][j] == '#'){
    if(input[i-1][j-1] == '#' && input[i-1][j] == '#' && input[i-1][j+1] == '#' && input[i][j-1] == '#' && input[i][j+1] == '#' && input[i+1][j-1] == '#' && input[i+1][j] == '#' && input[i+1][j+1] == '#') return 2;
    else return 1;
  }
  else return 0;
}

int main(){
  int h,w,i,j,k = 0,judge[102][102];
  char input[100][100],search[102][102];

  scanf("%d %d",&h,&w);

  for(i = 0; i < h; ++i){
    scanf("%s",input[i]);
  }

  for(i = 0; i < h+2; ++i){
    for(j = 0; j < w+2; ++j){
      if(i == 0 || i == h+1 || j == 0 || j == w+1) search[i][j] = '#';
      else search[i][j] = input[i-1][j-1];
    }
  }

  for( i = 0; i < h+2; ++i){
    for( j = 0; j < w+2; ++j){
      judge[i][j] = makejudge(search,i,j,h,w);
    }
  }

  for( i = 1; i < h+1 && k == 0; ++i){
    for ( j = 1; j < w+1 && k == 0; ++j){
      if(judge[i][j] == 1){
	if(ifexist(judge,i,j) == 1){
	  k = 1;
	  printf("impossible\n");
	}
	else{
	  input[i-1][j-1] = '.';
	}
      }
    }
  }
  if ( k == 0 ){
    printf("possible\n");
    for(i = 0; i < h; ++i){
      printf("%s\n",input[i]);
    }
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&h,&w);
   ^
./Main.c:24:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",input[i]);
     ^