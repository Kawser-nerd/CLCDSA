#include <stdio.h>
int H,W;
char s[100][100];
char t[100][100];
char u[100][100];
int dx[8]={1,0,-1,-1,-1,0,1,1};
int dy[8]={-1,-1,-1,0,1,1,1,0};
int is_white(int i,int j){
  
  int k;
  int ni,nj;
  for(k=0;k<8;k++){
    ni=i+dy[k];
    nj=j+dx[k];
    if(0<=ni && ni<H && 0<=nj && nj<W){
      if(s[ni][nj]=='.')return 1;
    }
  }
  return 0;
}
void assyuku(){
  int k;
  int i,j;
  int ni,nj;
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      if(t[i][j]=='#'){
	for(k=0;k<8;k++){
	  ni=i+dy[k];nj=j+dx[k];
	  if(0<=ni && ni<H && 0<=nj && nj<W) u[ni][nj]='#';
	}
      }
    }
  }
}
void print(char x[100][100]){
  int i,j;
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      printf("%c",x[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}
int main(){
  int i,j,flag;
  scanf("%d %d",&H,&W);
  
  for(i=0;i<H;i++)scanf("%s",&s[i]);
 
   for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      t[i][j]=s[i][j];
    }
  }
   
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      if(is_white(i,j))t[i][j]='.';
    }
  }
  for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      u[i][j]=t[i][j];
    }
  }
  assyuku();
  
  flag=0;
   for(i=0;i<H;i++){
    for(j=0;j<W;j++){
      if(s[i][j]!=u[i][j]){flag=1;}
    }
   }
  
   if(flag==0) {printf("possible\n");print(t);}
   else printf("impossible\n");
   
   return 0;
} ./Main.c: In function ‘main’:
./Main.c:50:25: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
   for(i=0;i<H;i++)scanf("%s",&s[i]);
                         ^
./Main.c:48:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&H,&W);
   ^
./Main.c:50:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<H;i++)scanf("%s",&s[i]);
                   ^