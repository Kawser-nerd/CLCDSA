#include<stdio.h>

int main(){
		int a[100][100]={0},w,h,n,i,j,xya[3],ans=0;
		scanf("%d%d%d",&w,&h,&n);
		for(i=h;i<100;i++){
				for(j=w;j<100;j++){
						a[i][j]=1;
				}
		}
		for(i=0;i<n;i++){
				scanf("%d%d%d",&xya[0],&xya[1],&xya[2]);
				int k;
				if(xya[2]==1){
						for(k=0;k<xya[0];k++){
								for(j=0;j<100;j++)a[j][k]=1;
						}
				}if(xya[2]==2){
						for(k=xya[0];k<100;k++){
								for(j=0;j<100;j++)a[j][k]=1;
						}
				}if(xya[2]==3){
						for(k=0;k<xya[1];k++){
								for(j=0;j<100;j++)a[k][j]=1;
						}
				}if(xya[2]==4){
						for(k=xya[1];k<100;k++){
								for(j=0;j<100;j++)a[k][j]=1;
						}
				}
		}
		for(i=0;i<h;i++){
				for(j=0;j<w;j++){
						if(a[i][j]==0)
								ans++;
				}
		}
		printf("%d\n",ans);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&w,&h,&n);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&xya[0],&xya[1],&xya[2]);
     ^