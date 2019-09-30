#include <stdio.h>  
int main(){
	int c[10][10],a,h,w,i,j,d[10]={0},k,s=0;
	scanf("%d%d",&h,&w);
	for(i=0;i<10;i++)
	for(j=0;j<10;j++){
	scanf("%d",&c[i][j]);
}
	for(i=1;i<=h;i++)for(j=1;j<=w;j++){
	scanf("%d",&a);
	if(a>=0)d[a]++;
	}
  for(k=0;k<10;k++)
  	for(i=0;i<10;i++)
  	for(j=0;j<10;j++)
  	 if(c[i][j]>c[i][k]+c[k][j])c[i][j]=c[i][k]+c[k][j];
  	 for(i=0;i<10;i++){
  	 	if(d[i])s+=d[i]*c[i][1];
	   }
	   printf("%d",s);
	   return 0;
  	 
  } ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&h,&w);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&c[i][j]);
  ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&a);
  ^