#include <stdio.h>
long long A[999999],W[999999];
long long M(int l,int r){
	if(l+1>=r)return 0;
	if(l+2==r){
		if(A[l]<=A[l+1])return 0;
		long long z=A[l];A[l]=A[l+1];A[l+1]=z;
		return 1;
	}
	int m = (l+r)/2,i=l, j=m, k=l;
	long long cl=M(l, m),cr=M(m,r),c=0;
	while(i<m&&j<r){
		if(A[i]<=A[j])W[k++]=A[i++];
		else{
			W[k++]=A[j++];
			c+=m-i;
		}
	}
	while(i<m)W[k++]=A[i++];
	while(j<r)W[k++]=A[j++];
	for(i=l;i<r;i++)A[i]=W[i];
	return cl+cr+c;
}
int main(){
	int T,i,N;
	//PKU2299,aizu0167: ???????????
	//for(;scanf("%d",&N),N;printf("%lld\n",M(0,N)))for(i=0;i<N;i++)scanf("%d",A+i);
	//hackerrank~runningtime,aizuALDS1~5D
	//scanf("%d",&N);for(i=0;i<N;i++)scanf("%d",A+i);printf("%lld\n",M(0,N));
	//hackerrank~30-sorting
	//scanf("%d",&N);for(i=0;i<N;i++)scanf("%d",A+i);printf("Array is sorted in %lld swaps.\n",M(0,N)),printf("First Element: %d\nLast Element: %d\n",A[0],A[N-1]);
	//spojINVCNT,hackerrank~insertionsort
	//for(scanf("%d",&T);T--;printf("%lld\n",M(0,N)))for(scanf("%d",&N),i=0;i<N;++i)scanf("%d",A+i);
	//codeiq4322: ??????
	//for(N=0;~scanf("%d",A+N);N++);printf("%lld\n",M(0,N));
	//kcs1009K: N???????
	//for(i=0;~(N=getchar());)if('0'<N&&N<'9')A[i++]=N-'0';
	//puts(M(0,i)%2?"lmpossible":"Possible"); //"l"? lol!
	//atcoderutpc2014F: ????
	//for(scanf("%d",&T),getchar();T--;printf("%lld\n",M(0,N)%2))for(N=0;~(A[N]=getchar())&&A[N]!='\n';N++);
	//kcs1031A
	//scanf("%d%d",&N,&T);for(i=0;i<N;i++)scanf("%d",A+i);N=M(0,N)-T;printf("%d\n",N>0?N:0);
	//atcoderARC075E: ?????T??
	scanf("%d%d",&N,&T);for(i=1;i<=N;i++)scanf("%d",&A[i]);for(i=1;i<=N;i++)A[i]+=A[i-1]-T;printf("%lld\n",(long long)N*-~N/2-M(0,N+1));
	return 0;
} ./Main.c: In function �main�:
./Main.c:44:45: warning: format �%d� expects argument of type �int *�, but argument 2 has type �long long int *� [-Wformat=]
  scanf("%d%d",&N,&T);for(i=1;i<=N;i++)scanf("%d",&A[i]);for(i=1;i<=N;i++)A[i]+=A[i-1]-T;printf("%lld\n",(long long)N*-~N/2-M(0,N+1));
                                             ^
./Main.c:44:2: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&N,&T);for(i=1;i<=N;i++)scanf("%d",&A[i]);for(i=1;i<=N;i++)A[i]+=A[i-1]-T;printf("%lld\n",(long long)N*-~N/2-M(0,N+1));
  ^
./Main.c:44:39: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&N,&T);for(i=1;i<=N;i++)scanf("%d",&A[i]);for(i=1;i<=N;i++)A[i]+=A[i-1]-T;printf("%lld\n",(long long)N*-~N/2-M(0,N+1));
                                       ^