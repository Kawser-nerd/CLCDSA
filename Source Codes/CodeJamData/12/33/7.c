#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef long long LL;

LL N,M;
LL A[1005],B[1005],a[1005],b[1005],max;

LL MIN(LL x,LL y){
	if(x<y) return x;
	return y;
}

void curr(LL X,LL Y,LL x,LL y,LL sum){
	LL min;
	if(A[X] == B[Y]){
		min = MIN(x,y);
		sum += min;
		if(sum > max) max = sum;
		if(x == min && y == min){
			if(X+1 < N && Y+1 < M)
			curr(X+1,Y+1,a[X+1],b[Y+1],sum);
		}else if(x== min){
			if(X+1<N)
			curr(X+1,Y,a[X+1],y-min,sum);
		}else if(y== min){
			if(Y+1<M)
			curr(X,Y+1,x-min,b[Y+1],sum);
		}
	}else{
		if(X+1<N)
		curr(X+1,Y,a[X+1],y,sum);
		if(Y+1<M)
		curr(X,Y+1,x,b[Y+1],sum);
	}
}

void solve(){
	max = 0;
	curr(0,0,a[0],b[0],0);
	printf("%lld",max);
}


int main(){
	LL i,j,t;
    scanf("%lld\n",&t);
    for(i=1;i<=t;i++){
		scanf("%lld%lld",&N,&M);
		for(j=0;j<N;j++)scanf("%lld%lld",&a[j],&A[j]);
		for(j=0;j<M;j++)scanf("%lld%lld",&b[j],&B[j]);
        printf("Case #%lld: ",i);
        solve();
        printf("\n");
    }
}
