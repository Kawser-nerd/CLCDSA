#include <stdio.h>

int main(){
  int a,b,c;
    int x[3];
    scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
    if(a>b&&a>c) {
      x[0]=1;
      if(b>c) {x[1]=2; x[2]=3;}
      else {x[1]=3; x[2]=2;}
    }
    else if(b>a&&b>c) {
      x[1]=1;
      if(a>c) {x[0]=2; x[2]=3;}
      else {x[0]=3;x[2]=2;}
    }
      else{
	x[2]=1;
	if(a>b) {x[0]=2; x[1]=3;}
	else {x[0]=3; x[1]=2;}
      }
      for(int i = 0; i<3;i++){
	printf("%d\n",x[i]);
      }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&b);
     ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&c);
     ^