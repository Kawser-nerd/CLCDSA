#include<stdio.h>
int MAX(int a,int b){return a<b?b:a;}
int d[310][310][610]={};
int main(){
	int n,m,o,i,j,k,a,b;
	scanf("%d %d %d",&n,&m,&o);
	for(i=0;i<o;i++){
		scanf("%d %d",&a,&b);
		for(j=0;j<=n;j++){
			for(k=0;k<=n+m;k++){
				d[i+1][j][k]=MAX(d[i+1][j][k],d[i][j][k]);
				d[i][j+1][k]=MAX(d[i][j+1][k],d[i][j][k]);
				d[i][j][k+1]=MAX(d[i][j][k+1],d[i][j][k]);
				if(k+a<=n+m)d[i+1][j+1][k+a]=MAX(d[i+1][j+1][k+a],d[i][j][k]+b);
			}
		}
	}
	/*for(i=0;i<=o;i++){
		for(j=0;j<=n;j++){
			for(k=0;k<=n+m;k++)printf("%3d ",d[i][j][k]);printf("\n");
		}printf("\n");
	}//*/			
	printf("%d\n",d[o][n][n+m]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&n,&m,&o);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^