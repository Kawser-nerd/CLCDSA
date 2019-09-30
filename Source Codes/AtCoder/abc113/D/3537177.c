#include<stdio.h>
int main(){
  int h,w,n,i,j,k,nk,M=1e9+7,d[110][10]={1};
  scanf("%d %d %d",&h,&w,&n);
  for(i=0;i<h;i++){
    for(j=0;j<(1<<(w-1));j++){
      for(k=0;k<w-1;k++){
	if((j&(1<<k))&&(j&(1<<(k+1))))goto NEXT;
      }
      //if(i==0)printf("%d\n",j);
      for(k=0;k<w;k++){
	nk=k;
	if(   j&(1<< k   ))nk=k+1;
	if(k&&j&(1<<(k-1)))nk=k-1;
	//printf("%d %d\n",nk,k);
	d[i+1][nk]=(d[i+1][nk]+d[i][k])%M;
      }
    NEXT:;
    }
  }
  /*for(i=0;i<=h;i++){
    for(j=0;j<w;j++)printf("%d ",d[i][j]);printf("\n");
    }
    printf("%d\n",n);//*/
  printf("%d\n",d[h][n-1]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&h,&w,&n);
   ^