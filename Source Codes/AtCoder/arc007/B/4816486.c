#include<stdio.h>

int main(){
	int n,m,i,j,d[101],num[101];
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)scanf("%d",&d[i]);
	for(i=0;i<=n;i++)num[i]=i;
	for(i=0;i<m;i++){
		int tmp;
		for(j=0;j<=n;j++){
			if(num[j]==d[i]){
				tmp=j;
				break;
			}
		}
		int ttmp=num[0];
		num[0]=num[tmp];
		num[tmp]=ttmp;
	}
	for(i=1;i<=n;i++)printf("%d\n",num[i]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:6:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<m;i++)scanf("%d",&d[i]);
                  ^