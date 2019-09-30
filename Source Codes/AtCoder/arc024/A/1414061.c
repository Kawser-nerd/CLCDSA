#include<stdio.h>
int MIN(int a,int b){return a<b?a:b;}
int main(){
	int n[2],s,i,c[2][100]={};
	scanf("%d %d",&n[0],&n[1]);
	for(i=0;i<2;i++){
		while(n[i]--){
			scanf("%d",&s);
			c[i][s]++;
		}
	}
	for(i=s=0;i<50;i++)s+=MIN(c[0][i],c[1][i]);
	printf("%d\n",s);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n[0],&n[1]);
  ^
./Main.c:8:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&s);
    ^