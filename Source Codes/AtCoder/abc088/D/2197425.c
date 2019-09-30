#include<stdio.h>
char map[60][60];
int book[60][60];
int black=0;
struct Queue{
   int x;
   int y;
   int step;
};
int front=-1,back=-1;
int main(){
   int h,w;
   int i,j;
   int pop,mx,my;
   int num[4][4]={{1,0},{-1,0},{0,1},{0,-1}};
   struct Queue Q[50000];
   scanf("%d%d",&h,&w);
   getchar();
   for(i=0;i<h;i++){
      for(j=0;j<w;j++){
          scanf("%c",&map[i][j]);
          if(map[i][j]=='#'){
            black++;
          }
      }
      getchar();
   }
   book[0][0]=1;
   back++;
   Q[back].x=0;
   Q[back].y=0;
   Q[back].step=0;
   //printf("1\n");
   while(front!=back){
       front++;
       pop=front;
       for(i=0;i<4;i++){
               mx=Q[pop].x+num[i][0];
               my=Q[pop].y+num[i][1];
               if(mx<0||mx>=h||my<0||my>=w)continue;
               if(book[mx][my]==0&&map[mx][my]=='.'){
                   book[mx][my]=1;
                   back++;
                   Q[back].x=mx;
                   Q[back].y=my;
                   Q[back].step=Q[pop].step+1;
                  // printf("mx=%d  my=%d   step=%d\n",mx,my,Q[back].step);
               }
               if(mx+1==h&&my+1==w){
                   break;
               }
       }
       if(mx+1==h&&my+1==w){
            break;
       }
   }
  // printf("2\n");
   if(mx+1==h&&my+1==w){//??
       printf("%d\n",h*w-black-Q[back].step-1);
   }
   else{
       printf("-1\n");
   }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d%d",&h,&w);
    ^
./Main.c:21:11: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
           scanf("%c",&map[i][j]);
           ^