#include<stdio.h>
int main(){
	int h,w,i,r,t,ny,nx,a=0,y[3000],x[3000],c[60][60]={};
	int X[]={0,1,0,-1};
	int Y[]={1,0,-1,0};
	char s[60][60]={};
	scanf("%d %d",&h,&w);
	for(i=0;i<h;i++)scanf("%s",s[i+1]+1);
	for(i=0;i<h*w;i++){
		if(s[i/w+1][i%w+1]=='.')a++;
	}//printf("%d\n",a);
	x[0]=y[0]=r=c[1][1]=1;
	s[1][1]='#';
	c[h][w]=a+1;
	for(t=0;r-t;t++){//printf("%d %d\n",y[t],x[t]);
		for(i=0;i<4;i++){
			ny=y[t]+Y[i];
			nx=x[t]+X[i];
			if(s[ny][nx]-'.')continue;
			c[ny][nx]=c[y[t]][x[t]]+1;
			s[y[r]=ny][x[r]=nx]='#';
			r++;
		}
	}
	printf("%d\n",a-c[h][w]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&h,&w);
  ^
./Main.c:8:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<h;i++)scanf("%s",s[i+1]+1);
                  ^