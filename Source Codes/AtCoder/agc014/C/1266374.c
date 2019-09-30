#include<stdio.h>
int MIN(int a,int b){return a<b?a:b;}
int Y[]={0,1,0,-1};
int X[]={1,0,-1,0};
  int h,w,n,ny,nx,min=1e9,i,j,x[800010],y[800010],t=0,r,a;
int main(){
  char d[1010][1010]={};
  int c[1010][1010]={};
  scanf("%d %d %d",&h,&w,&n);
  for(i=1;i<=h;i++){
    for(j=1;j<=w;j++){
      scanf(" %c",&d[i][j]);
      if(d[i][j]=='S')d[y[0]=i][x[0]=j]='#';
    }
  }
  t=0;
  min=1e9;
  for(r=1;r-t;t++){
    for(i=0;i<4;i++){
      a=MIN(MIN(y[t]-1,h-y[t]),MIN(x[t]-1,w-x[t]));
      if(a)a=(a-1)/n+1;
      min=MIN(min,a);//printf("%d\n",min);
      ny=y[t]+Y[i];
      nx=x[t]+X[i];
      if(d[ny][nx]-'.')continue;
      c[ny][nx]=c[y[t]][x[t]]+1;
      d[y[r]=ny][x[r]=nx]='#';
      if(c[ny][nx]<=n){
	a=MIN(MIN(ny-1,h-ny),MIN(nx-1,w-nx));	
	if(a)a=(a-1)/n+1;
	min=MIN(min,a);
	r++;
      }      
    }
  }
  
  printf("%d\n",min+1);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&h,&w,&n);
   ^
./Main.c:12:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf(" %c",&d[i][j]);
       ^