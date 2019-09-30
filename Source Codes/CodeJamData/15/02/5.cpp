#include<cstdio>
#include<algorithm>

using namespace std;

int D;
int P[1010];

int calc(int M){
	int res=0;
	for(int i=0;i<D;i++){
		int tmp=P[i]/M;
		if(P[i]%M==0) tmp--;
		if(tmp<0) tmp=0;
		res+=tmp;
	}
	return res;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int datano=1;datano<=T;datano++){
		scanf("%d",&D);
		for(int i=0;i<D;i++) scanf("%d",P+i);
		int ans=10000;
		for(int i=1;i<=1000;i++){
			ans=min(ans,i+calc(i));
		}
		printf("Case #%d: %d\n",datano,ans);
	}
	return 0;
}
