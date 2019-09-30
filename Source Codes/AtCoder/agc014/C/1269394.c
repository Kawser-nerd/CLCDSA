#include<stdio.h>

char A[810][810];
int B[810][810] = {0};
int H,W,K;
int s_i,s_j;

int abs(int x){
  if(x<0){
    x *= -1;
  }
  return x;
}

void check(int i,int j, int k){
  if((A[i][j]=='.' || A[i][j]=='S') && (abs(i - s_i) + abs(j - s_j)) <= k ){
    B[i][j] = 1;
  } else if(A[i][j]=='#'){
    B[i][j] = -1;
    return;
  }

  if(B[i][j]==1){
    if(B[i+1][j]==0 && i+1<H){
      check(i+1,j,k);
    }
    if(B[i-1][j]==0 && i-1>=0){
      check(i-1,j,k);
    }
    if(B[i][j+1]==0 && j+1<W){
      check(i,j+1,k);
    }
    if(B[i][j-1]==0 && j-1>=0){
      check(i,j-1,k);
    }
  }

  /* printf("%d %d %d\n",i,j,k); */
}

int main(void){
  scanf("%d %d %d",&H,&W,&K);
  int i,j;

  for(i=0;i<H;i++){
    scanf("%s", A[i]);
  }

  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      if(A[i][j]=='S'){
        s_i = i;
        s_j = j;
      }
    }
    /* printf("%s\n",A[i]); */
  }

  check(s_i,s_j,K);

  /* for(i=0;i<H;i++){ */
  /*   for(j=0;j<W;j++){ */
  /*     printf("%2d",B[i][j]); */
  /*   } */
  /*   printf("\n"); */
  /* } */
  int up = s_i;
  int down = s_i;
  int left = s_j;
  int right = s_j;

  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      if(B[i][j]==1){
        if(i<up){
          up = i;
        }
        if(i>down){
          down = i;
        }
        if(j<left){
          left = j;
        }
        if(j>right){
          right = j;
        }
      }
    }
  }

  /* printf("left:%d\n",left); */
  /* printf("right:%d\n",right); */
  /* printf("up:%d\n",up); */
  /* printf("down:%d\n",down); */

  int min = 800;
  if(up < min){
    min = up;
    /* printf("up\n"); */
  }
  if(H-1 - down < min){
    min = (H-1) - down;
    /* printf("down\n"); */
  }
  if(left < min){
    min = left;
    /* printf("left\n"); */
  }
  if(W-1 - right < min){
    min = (W-1) - right;
    /* printf("right\n"); */
  }

  /* printf("min:%d\n",min); */

  int ans = 1;
  ans += (min+K-1)/K;

  printf("%d\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:42:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&H,&W,&K);
   ^
./Main.c:46:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s", A[i]);
     ^