#include<stdio.h>
#include<stdlib.h>

char board[104][104];


void ch2dir(char x,int*a,int*b){
  switch(x){
    case '>':*a=0;*b=1;break;
    case '<':*a=0;*b=-1;break;
    case '^':*a=-1;*b=0;break;
    case 'v':*a=1;*b=0;break;
    default:exit(-1);
  }
}
int h;
int w;
int isout(int a,int b,int x,int y){
  int c,d;
  for(c=a+x,d=b+y;c>=0&&c<h&&d>=0&&d<w;c+=x,d+=y){
    if(board[c][d]!='.')return 0;
  }
  return 1;
}

int main(int argc,char*argv[]){
  int a,b,ncase,nc;
  scanf("%d",&ncase);
  for(nc=1;nc<=ncase;nc++){
    scanf("%d%d",&h,&w);
    for(a=0;a<h;a++){
      scanf("%s",board[a]);
    }
    printf("Case #%d: ",nc);
    int ans=0;
    for(a=0;a<h;a++){
      for(b=0;b<w;b++){
        if(board[a][b]=='.')continue;
        int x,y;
        ch2dir(board[a][b],&x,&y);
        if(isout(a,b,x,y)==0)continue;
        if(
        isout(a,b,1,0)&&
        isout(a,b,-1,0)&&
        isout(a,b,0,1)&&
        isout(a,b,0,-1)
        )goto impossible;
        ans++;
      }
    }
    printf("%d\n",ans);
    continue;
    impossible:
    puts("IMPOSSIBLE");
  }
  return 0;
}
