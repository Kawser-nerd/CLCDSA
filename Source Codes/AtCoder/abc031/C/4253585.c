#include<stdio.h>
#include<stdlib.h>

#define min(a,b) ((a)<(b)?(a):(b))

int main(){
	int n,i,j,a[50],tkao[50][50][2]={0},ans=-2000000;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j){
				int k;
				for(k=0;k<=abs(i-j);k++)tkao[i][j][k%2]+=a[min(i,j)+k];
			}else {
				tkao[i][j][0]=-200000000;
				tkao[i][j][1]=-200000000;
			}
		}
	}
	for(i=0;i<n;i++){
		int tmp=0;
		for(j=0;j<n;j++){
			if(tkao[i][tmp][1]<tkao[i][j][1])tmp=j;
		}
		if(ans<tkao[i][tmp][0])ans=tkao[i][tmp][0];
	}
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:9:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%d",&a[i]);
                  ^