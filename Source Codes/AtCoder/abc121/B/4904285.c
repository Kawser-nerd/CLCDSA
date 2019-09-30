#include <stdio.h>
int main(void){
	int n,m,c;
	int i,j;
	int a[21][21];
	scanf("%d%d%d",&n,&m,&c);
	for(i=0;i<n+1;i++){
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	int temp;
	int ans = 0;
	for(i=1;i<n+1;i++){
		temp = 0;
		for(j=0;j<m;j++){
			temp+= a[0][j]*(a[i][j]);
		}
		temp += c;
		if(temp>0){
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&m,&c);
  ^
./Main.c:9:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&a[i][j]);
    ^