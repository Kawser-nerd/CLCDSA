#include<stdio.h>

int main(){
	int x,y,z;
	int s,k;
	int cnt=0;
	scanf("%d%d",&k,&s);
	for(int i=0;i<=k;i++){
		for(int j=0;j<=k;j++){
			if(s-i-j>=0&&s-i-j<=k){
				cnt++;
			}
		}
	}
	printf("%d",cnt);
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&k,&s);
  ^