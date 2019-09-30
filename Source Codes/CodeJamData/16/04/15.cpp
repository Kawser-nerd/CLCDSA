#include<stdio.h>
#include<vector>
using namespace std;
int T,K,C,S;
vector<long long> output;
int main(){
	scanf("%d",&T);
	for(int tt=1;tt<=T;++tt){
		scanf("%d%d%d",&K,&C,&S);
		int g=0;
		output.clear();
		printf("Case #%d: ",tt);
		while(g<K){
			long long f=0;
			for(int i=0;i<C;++i){
				if(g==K) f=f*K+K-1;
				else f=f*K+(g++);
			}
			output.push_back(f+1);
		}
		if(S<(int)output.size()) printf("IMPOSSIBLE\n");
		else{
			for(int i=0;i<int(output.size());++i){
				printf("%lld%c",output[i],i==(int)output.size()-1?'\n':' ');
			}
		}
	}
	return 0;
}
