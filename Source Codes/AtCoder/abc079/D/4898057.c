#include <stdio.h>
int main(void){
	int H,W,c[10][10],i,j,k;
	scanf("%d%d",&H,&W);
	for(i=0;i<10;i++)for(j=0;j<10;j++)scanf("%d",&c[i][j]);
		
	
	for(k=0;k<10;k++){
		for(i=0;i<10;i++){
			for(j=0;j<10;j++){
				int tmp = c[i][k]+c[k][j];
				if(tmp<c[i][j])c[i][j] = tmp;
			}
		}
	}
	
	int ans=0;
	for(i=0;i<H;i++){
		for(j=0;j<W;j++){
			int a;
			scanf("%d",&a);
			if(a>=0)ans +=c[a][1];
		}
	}
	printf("%d",ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&H,&W);
  ^
./Main.c:5:36: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<10;i++)for(j=0;j<10;j++)scanf("%d",&c[i][j]);
                                    ^
./Main.c:21:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&a);
    ^