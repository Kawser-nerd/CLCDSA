#include <stdio.h>
#include <stdlib.h>

int main(void){
	int H,W,i,j;
	scanf("%d%d",&H,&W);
	int a[H+1][W+1];
	for(i=1;i<=H;i++)for(j=1;j<=W;j++)scanf("%d",&a[i][j]);
	int count=0,ans[250000][4];
	for(i=1;i<=H;i++){
		if(i%2==1){
			for(j=1;j<W;j++){
				if(a[i][j]%2==1){
					ans[count][0] = ans[count][2] = i;
					ans[count][1] = j;
					ans[count][3] = j+1;
					count++;
					a[i][j+1]++;
				}
			}
			if(a[i][W]%2==1 && i<H){
				ans[count][0] = i;
				ans[count][1] = ans[count][3] = j;
				ans[count][2] = i+1;
				count++;
				a[i+1][j]++;
			}
		}else{
			for(j=W;j>1;j--){
				if(a[i][j]%2==1){
					ans[count][0] = ans[count][2] = i;
					ans[count][1] = j;
					ans[count][3] = j-1;
					count++;
					a[i][j-1]++;
				}
			}
			if(a[i][1]%2==1 && i<H){
				ans[count][0] = i;
				ans[count][1] = ans[count][3] = j;
				ans[count][2] = i+1;
				count++;
				a[i+1][j]++;
			}
		}
	}
	
	printf("%d\n",count);
	for(i=0;i<count;i++){
		printf("%d %d %d %d\n",ans[i][0],ans[i][1],ans[i][2],ans[i][3]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&H,&W);
  ^
./Main.c:8:36: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=1;i<=H;i++)for(j=1;j<=W;j++)scanf("%d",&a[i][j]);
                                    ^