#include<stdio.h>
#include<stdlib.h>

long long min(long long x,long long y){
	if(x<y)return x;
	return y;
}

long long C(long long p,long long q){
	if(q==0 || p==q)return 1;
	if(q>p/2)q=p-q;
	long long ans=1;
	for(long long i=1;i<=q;i++){
		ans*=p-i+1;
		ans/=i;
	}
	return ans;
}

int compare(const void *a, const void *b){
	long long int *A = (long long int *)a;
	long long int *B = (long long int *)b;
	if (*A < *B) return 1;
	if (*A > *B) return -1;
	return 0;
}

int main(){
	long long N,A,B,i,j,ans=0;
	scanf("%lld%lld%lld",&N,&A,&B);
	long long v[N];
	for(i=0;i<N;i++)scanf("%lld",&v[i]);
	long long max=0;
	
	qsort(v,N,sizeof(long long),compare);
	
	for(j=0;j<A;j++)max+=v[j];
	j--;
	
	long long req=A;
	long long count=0;
	for(i=0;i<N;i++){
		if(v[i]>v[j])req--;
		if(v[i]==v[j])count++;
	}
	
	if(v[0]==v[j]){
		B=min(B,count);
		for(i=A;i<=B;i++)ans+=C(count,i);
		printf("%lld\n%lld\n",v[0],ans);
		return 0;
	}
	
	
	ans+=C(count,req);
	
	long long ans1=max/A;
	long long ans2=max%A;
	int ans3=(int)ans2;
	double ans4=(double)ans3/A;
	long long ans5=ans1%10;
	int ans6=(int)ans5;
	ans4+=ans6%10;
	ans1-=ans1%10;
	ans1/=10;
	if(ans1==0)printf("%lf\n",ans4);
	else printf("%lld%lf\n",ans1,ans4);
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:30:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&N,&A,&B);
  ^
./Main.c:32:18: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=0;i<N;i++)scanf("%lld",&v[i]);
                  ^