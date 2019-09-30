#include <stdio.h>

long long box[200][2] , toy[200][2];
int N,M;

long long min(long long a,long long b){
	if(a<b)
		return a;
	else
		return b;
}

long long max(long long a,long long b){
	if(a>b)
		return a;
	else
		return b;
}

long long next(int assem1 , int assem2){
	long long tem=0,result;
	if(N==assem1 || M==assem2)
		return 0;
	
	if(box[assem1][1] == toy[assem2][1])
		tem = min(box[assem1][0] , toy[assem2][0]);

	//printf("%d %d %lld\n" , assem1 , assem2 , tem);
	box[assem1][0] -= tem;
	toy[assem2][0] -= tem;
	result = max( tem+next(assem1+1,assem2) , tem+next(assem1,assem2+1));
	box[assem1][0] += tem;
	toy[assem2][0] += tem;
	return result;
}

int main(){
	int i,j,testn,test=1;
	scanf("%d" , &testn);
	while(testn--){
		long long sum;
		scanf("%d%d" , &N , &M);

		for(i=0;i<N;i++)
			scanf("%lld%lld" , &box[i][0] , &box[i][1]);
		for(i=0;i<M;i++)
			scanf("%lld%lld" , &toy[i][0] , &toy[i][1]);
		sum = next(0,0);
		printf("Case #%d: %lld\n" , test++ , sum);
	}
}
