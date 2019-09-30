#include<stdio.h>

long long ru(int a){
	int i;
	long long r=1;
	for(i=0;i<a;i++)r=r*2;
	return r;
}

int main(){
	int n,i;
	long long k,a[100000],ans=0,keta[100]={0},tmp2=0;
	scanf("%d%lld",&n,&k);
	for(i=0;i<n;i++)scanf("%lld",&a[i]);
	for(i=0;i<n;i++){
		int j=0;
		long long tmp=a[i];
		while(tmp>0){
			if(tmp%2==1){
				keta[j]++;
				tmp--;
			}
			tmp=tmp/2;
			j++;
		}
	}
	long long nokori=k;
	for(i=50;i>=0;i--){
		//printf("%lld,",keta[i]);
		if((keta[i]<=(n/2))&&(nokori>=ru(i))){
		//printf("%lld\n",nokori);
			tmp2+=ru(i);
			nokori=nokori-ru(i);
		}
	}
	for(i=0;i<n;i++)ans+=tmp2^a[i];
	printf("%lld\n",ans);
//	printf("%lld\n",ru(50));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%lld",&n,&k);
  ^
./Main.c:14:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<n;i++)scanf("%lld",&a[i]);
                  ^