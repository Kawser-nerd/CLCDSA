#include<stdio.h>
short N, W, H, N, x, y, a;
short l, r, b, t;
short i;
int main(){
  scanf("%hd%hd%hd", &W, &H, &N);
  l=0; r=W, b=0; t=H;
  for(i=0; i<N; i++){
    scanf("%d%d%d", &x, &y, &a);
    if(a==1){
      if(x>l){l=x;}
    }else if(a==2){
      if(x<r){r=x;}
    }else if(a==3){
      if(y>b){b=y;}
    }else if(a==4){
      if(y<t){t=y;}
    }
  }
  if(l<r && b<t){
    printf("%d\n", (r-l)*(t-b));
  }else{
    printf("0\n");
  }
} ./Main.c: In function ‘main’:
./Main.c:9:11: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘short int *’ [-Wformat=]
     scanf("%d%d%d", &x, &y, &a);
           ^
./Main.c:9:11: warning: format ‘%d’ expects argument of type ‘int *’, but argument 3 has type ‘short int *’ [-Wformat=]
./Main.c:9:11: warning: format ‘%d’ expects argument of type ‘int *’, but argument 4 has type ‘short int *’ [-Wformat=]
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%hd%hd%hd", &W, &H, &N);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d", &x, &y, &a);
     ^