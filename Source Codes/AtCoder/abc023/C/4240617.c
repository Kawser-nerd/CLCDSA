#include<stdio.h>

int main(){
	int r,c,k,i,n,rc[100000][2],gyoc[100000]={0},retk[100000]={0};
	long long ans=0,keit=0;
	scanf("%d%d%d%d",&r,&c,&k,&n);
	for(i=0;i<n;i++){
		scanf("%d%d",&rc[i][0],&rc[i][1]);
		retk[rc[i][0]-1]++;
		gyoc[rc[i][1]-1]++;
	}
	int gsrs[2][100001]={0};
	for(i=0;i<c;i++)gsrs[0][gyoc[i]]++;
	for(i=0;i<r;i++)gsrs[1][retk[i]]++;
	for(i=0;i<=k;i++)ans+=(long long)gsrs[0][i]*(long long)gsrs[1][k-i];
	for(i=0;i<n;i++){
		if(retk[rc[i][0]-1]+gyoc[rc[i][1]-1]==k)ans--;
		if(retk[rc[i][0]-1]+gyoc[rc[i][1]-1]==k+1)ans++;
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d",&r,&c,&k,&n);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&rc[i][0],&rc[i][1]);
   ^