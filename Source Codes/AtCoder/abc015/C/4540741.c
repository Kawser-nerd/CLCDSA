#include<stdio.h>

int runm(int a,int b){
	int r=1,i;
	for(i=0;i<b;i++)r=r*a;
	return r;
}

int main(){
	int i,j,n,k,t[5][5]={0},ans=2000000;
	scanf("%d%d",&n,&k);
	for(i=0;i<n;i++){
		for(j=0;j<k;j++){
			scanf("%d",&t[i][j]);
		}
	}
	for(i=0;i<runm(k,n);i++){
		int tmp[5]={0},l=0,icp=i,ab=0;
		while(icp>0){
			tmp[l]=icp%k;
			icp/=k;
			l++;
		}
		for(j=0;j<n;j++){
			ab=ab^t[j][tmp[j]];
		}
		if(ab==0){
			puts("Found");
			return 0;
		}
	}
	puts("Nothing");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^
./Main.c:14:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&t[i][j]);
    ^