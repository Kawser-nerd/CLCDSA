#include<stdio.h>
#include<stdlib.h>

#define Rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define Rep2(i,bottom,ceiling) for(int (i)=(bottom);(i)<=(ceiling);(i)++)
#define POS(i,j) ((i)*w+(j))

char *board;
int h,w;

void SwapChar(char* v1,char* v2){
    char sw = *v1;
    *v1=*v2;
    *v2=sw;
}

int func(int i,int j){
  Rep(k,h) if(board[POS(k,i)]!=board[POS(h-1-k,j)]) return 0;
  return 1;
}

int calcCol(){
  int flag[16];
  Rep(i,w) flag[i]=0;
  int useCenter=0;
  Rep(i,w){
    if(flag[i]) continue;
    Rep2(j,i+1,w-1){
      if(flag[j]) continue;
      if(func(i,j)){
		flag[i]=1;
		flag[j]=1;
		break;
      }
    }
    if(!flag[i]){
      if(w%2==0 || useCenter) return 0;
      Rep(j,h-1-j){
		if(board[POS(j,i)]!=board[POS(h-1-j,i)]) return 0;
      }
      useCenter=1;
      flag[i]=1;
    }
  }
  return 1;
}

void swapRow(int a,int b){
  Rep(i,w) SwapChar(&board[POS(a,i)],&board[POS(b,i)]);
}

int loopRow(int d){
  if(d>=h-1-d) return calcCol();
  Rep2(i,d+1,h-1-d){
    if(h%2==1 && i==h/2) continue;
    swapRow(i,h-1-d);
    if(loopRow(d+1)) return 1;
    swapRow(i,h-1-d);
  }
  return 0;
}

int calc(void){
  if(h%2==0) return loopRow(0);
  int center=h/2;
  Rep(i,h){
    swapRow(i,center);
    if(loopRow(0)) return 1;
    swapRow(i,center);
  }
  return 0;
}

int main(){
  scanf("%d%d",&h,&w);
  board=(char *)malloc(sizeof(char)*(h*w+1));
  Rep(i,h) scanf("%s",board+POS(i,0));
  printf("%s\n",calc()?"YES":"NO");
  free(board);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:75:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&h,&w);
   ^
./Main.c:77:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   Rep(i,h) scanf("%s",board+POS(i,0));
            ^