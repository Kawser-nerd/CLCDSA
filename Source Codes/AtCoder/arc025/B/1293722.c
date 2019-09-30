#include<stdio.h>
int MAX(int a,int b){return a<b?b:a;}
int main(){
	int h,w,i,j,k,l,d[110][110],max;
	scanf("%d %d",&h,&w);
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			scanf("%d",&k);
			d[i+1][j+1]=(i+j)%2?-k:k;
		}
	}
	for(i=0;i<h;i++){
		for(j=0;j<w;j++)d[i+1][j+1]+=d[i][j+1]+d[i+1][j]-d[i][j];
	}
	for(i=max=0;i<h;i++){
		for(j=0;j<w;j++){
			for(k=i;k<h;k++){
				for(l=j;l<w;l++){
					if(d[k+1][l+1]+d[i][j]==d[k+1][j]+d[i][l+1])max=MAX(max,(k+1-i)*(l+1-j));
				}
			}
		}
	}
	printf("%d\n",max);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&h,&w);
  ^
./Main.c:8:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&k);
    ^