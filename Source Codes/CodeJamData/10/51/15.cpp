#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

bool isprime[1000010];

int a[111];

int POW(int a,int sm,int p){
	if(sm==0)return 1%p;
	else{
		long long r=POW(a,sm/2,p);
		if(sm%2==0)return r*r%p;
		else return r*r%p*a%p;	
	}
}

int main() {
	
	memset(isprime,true,sizeof(isprime));
	isprime[0]=isprime[1]=false;
	For(i,2,1000000)if(isprime[i])
		for(int j=i+i;j<=1000000;j+=i)isprime[j]=false;
	
	int st;
	scanf("%d",&st);
	Rep(test,st){
		int D,K;
		cin>>D>>K;
		Rep(i,K)cin>>a[i];
		cout<<"Case #"<<test+1<<": ";
		if(K==1){
			cout<<"I don't know."<<endl;
			continue;
		}
		else{
			if(a[K-1]==a[K-2]){ cout<<a[K-1]<<endl;	continue;}
			
			if(K==2){cout<<"I don't know."<<endl;
			continue;}
			
			int tend=1;
			Rep(i,D)tend*=10;
			
			int maxi=0;
			Rep(i,K)maxi>?=a[i];
			
			set<int> se;
			
			For(p,maxi+1,tend)if(isprime[p]){
				int x=((a[1]-a[0])%p+p)%p;
				int z=((a[2]-a[1])%p+p)%p;
				int A=z * (long long)POW(x,p-2,p)%p;
				int B=(a[1]-a[0]*(long long)A)%p;
				//cout<<p<<" "<<A<<" "<<B<<endl;
				if(B<0) B=(B+p)%p;
				// check
				bool ok=true;
				for(int i=1;i<K;++i){
					int ai=(a[i-1]*(long long)A+B)%p;
					if(ai!=a[i]){ok=false;break;}	
				}
				if(ok){
					//cout<<"here"<<endl;
					int next=(a[K-1]*(long long)A+B)%p;
					se.insert(next);
					if(se.size()>=2)break;
				}
			}
			// cerr<<se.size()<<endl;
			if(se.size()>=2){
				cout<<"I don't know."<<endl;
					
			}
			else if(se.size()==1){
				cout<<(*se.begin())<<endl;	
			}
			else{
				cerr<<"ERROR"<<endl;	
				cerr<<D<<" "<<K<<endl;
				Rep(i,K)cerr<<a[i]<<" ";cerr<<endl;
			}
		}
	}	
	return 0;	
}
