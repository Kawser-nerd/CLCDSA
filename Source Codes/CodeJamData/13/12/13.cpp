#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int NMax=10000;
long long E;
long long R;
long long V[NMax];
int N;
long long score;
long long A[NMax],B[NMax];
long long dfs(int i,long long lmt){
	int u=i>>1;
	long long r=0;
	if (i%2==1){
		if (A[u+1]){
			long long t=min(A[u+1],lmt);
			lmt-=t;
			r+=t;
			A[u+1]-=t;
		}
		long long t=dfs(i-1,lmt);
		return r+t;
	}else{
		if (i==0){
			long long t=min(A[0],lmt);
			A[0]-=t;
			lmt-=t;
			return t;
		}else{
			long long t=min(B[u-1],lmt);
			t=dfs(i-1,t);
			B[u-1]-=t;
			return t;
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int Case=0;Case<T;Case++){
		scanf("%lld%lld%d",&E,&R,&N);
		for (int i=0;i<N;i++)
			scanf("%lld",V+i);
		score=0;
		for (int i=0;i<N;i++){
			if (i==0)
				A[i]=E;
			else
				A[i]=R;
		}
		for (int i=0;i<N;i++)
			B[i]=E;
		vector<pair<int,int> >as;
		for (int i=0;i<N;i++)
			as.push_back(make_pair(V[i],i));
		sort(as.begin(),as.end());
		for (int i=N-1;i>=0;i--){
			int t=as[i].second;
			//for (int j=0;j<N;j++)
				//printf("%lld ",A[j]);
			//puts("");
			//for (int j=0;j<N-1;j++)
				//printf("%lld ",B[j]);
			//puts("");
			score+=V[t]*dfs(2*t,E);
			//printf("score %lld\n",score);
		}
		printf("Case #%d: %lld\n",Case+1,score);
	}
	return 0;
}

