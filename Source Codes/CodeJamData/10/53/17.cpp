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

int n;
map<int,int> ma;

int main() {
	int st;
	scanf("%d",&st);
	Rep(test,st){
		cerr<<"test="<<test+1<<endl;
		cin>>n;
		ma.clear();
		Rep(i,n){
			int p,v;cin>>p>>v;
			ma[p]+=v;	
		}
		bool tiep=true;
		int step=0;
		while(tiep){
			tiep=false;
			vector<PII> vec;
			for(map<int,int>::iterator p=ma.begin();p!=ma.end();++p){
				if(p->second>1){
					tiep=true;
					int u=p->first;
					int v=p->second;
					vec.pb(MP(u,v));
					break;
				}	
			}	
			Rep(i,vec.size()){
				int tmp = vec[i].second / 2;
				step += tmp;
				ma[vec[i].fi] -= 2 * tmp;
				ma[vec[i].fi-1]+=tmp;
				ma[vec[i].fi+1]+=tmp;	
			}
		}
		cout<<"Case #"<<test+1<<": ";
		cout<<step<<endl;
	}	
	return 0;	
}
