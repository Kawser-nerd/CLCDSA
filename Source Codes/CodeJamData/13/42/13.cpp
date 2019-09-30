#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<string>
#include<cmath>
using namespace std; typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int T;
i64 P, N;

bool unlucky_sub(i64 X)
{
	if(X==0) return true;

	i64 stg = X; i64 pt = 1;
	for(int i=N-1;i>=0;i--){
		if(stg == 0){
			return pt <= P;
		}
		stg = (stg-1)/2;
		pt += 1LL << (i64)i;
	}

	return pt <= P;
}

i64 unlucky()
{
	i64 L=0, R=((1LL)<<N)-1;
	while(R!=L){
		i64 mid = (L+R+1)/2;
		if(unlucky_sub(mid)){
			L = mid;
		}else{
			R = mid-1;
		}
	}

	return L;
}

bool lucky_sub(i64 X)
{
	if(X==0) return true;

	i64 stg = X;
	for(int i=N;i>=1;i--){
		if(stg == (1LL<<(i64)i)-1){
			return (1LL<<(i64)i) <= P;
		}
		stg = (stg+1)/2;
	}

	return true;
}

i64 lucky()
{
	i64 L=0, R=((1LL)<<N)-1;
	while(R!=L){
		i64 mid = (L+R+1)/2;
		if(lucky_sub(mid)){
			L = mid;
		}else{
			R = mid-1;
		}
	}

	return L;
}

int main()
{
	scanf("%d", &T);
	for(int t=0;t++<T;){
		scanf("%lld%lld", &N, &P);

		printf("Case #%d: %lld %lld\n", t, unlucky(), lucky());
	}

	return 0;
}
