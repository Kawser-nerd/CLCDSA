#include<stdio.h>

int main(void)
{
  int r,c,sy,sx,gy,gx,i,j,x,y,nx,ny;
  char C[51][51];
  char dummy;
  int que1[3000],que2[3000];
  int head=0,tail=1;
  int count[50][50];
  int vx[]={0,1,0,-1};
  int vy[]={1,0,-1,0};
  
  scanf("%d %d",&r,&c);
  scanf("%d %d",&sy,&sx);
  scanf("%d %d",&gy,&gx);
  for(i=0;i<r;i++){
    scanf("%s",C[i]);
  }
  sx--;
  sy--;
  gx--;
  gy--;


  for(i=0;i<r;i++){
    for(j=0;j<c;j++){
      count[i][j]=-1;
    }
  }

  que1[0]=sy;
  que2[0]=sx;
  count[sy][sx]=0;
  
  while(head!=tail){
    y=que1[head];
    x=que2[head];
    head=(head+1)%3000;

    for(i=0;i<4;i++){
      ny=y+vy[i];
      nx=x+vx[i];

      if(C[ny][nx]=='.'&&count[ny][nx]<0&&0<=ny&&0<=nx&&ny<r&&nx<c) {
	count[ny][nx]=count[y][x]+1;
	if(ny==gy&&nx==gx)
	  {
	    printf("%d\n",count[ny][nx]);
	    return 0;
	  }
	que1[tail]=ny;
	que2[tail]=nx;
	tail=(tail+1)%3000;
      }
    }
  }
   for(i=0;i<r;i++){
     for(j=0;j<c;j++){
    printf("%d",count[i][j]);
     }
     printf("\n");
   }
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&r,&c);
   ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&sy,&sx);
   ^
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&gy,&gx);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",C[i]);
     ^