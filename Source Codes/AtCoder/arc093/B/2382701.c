#include<stdio.h>
int main(){
  int a,b,i,j;
  char d[110][110]={};
  scanf("%d %d",&a,&b);
  a--;
  b--;
  printf("100 100\n");
  for(i=0;i<50;i+=2){
    for(j=0;j<100;j+=2){
      d[i][j]=d[i+1][j]=d[i][j+1]=d[i+1][j+1]='#';
      if(a){
	d[i][j]='.';
	a--;
      }
    }
  }
  for(i=50;i<100;i+=2){
    for(j=0;j<100;j+=2){
      d[i][j]=d[i+1][j]=d[i][j+1]=d[i+1][j+1]='.';
      if(b){
	d[i+1][j]='#';
	b--;
      }
    }
  }
  for(i=0;i<100;i++)printf("%s\n",d[i]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^