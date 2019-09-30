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

const int MOD = 1000000007;

int n,b;
map<VI,int> ma[111][111];

int go(int sum, VI mask, int maxi){
	if(sum == 0) return 1;
	//cout<<sum<<" "<<maxi<<endl;
	if(ma[sum][maxi].count(mask)) return ma[sum][maxi][mask];
	int ret=0;
	for(int i=maxi;i>0;--i)if(sum>=i){
		// check i
		int x=i;
		bool ok = true;
		for(int j=0;j<10;++j){
			if(x==0) break;
			int dig = x % b;
			x /= b;
			if((mask[j] & (1<<dig))!=0){
				ok = false;
				break;	
			}
		}	
		
		if(ok){
			// new mask
			VI v=mask;
			x=i;
			for(int j=0;j<10;++j){
				if(x==0) break;
				int dig = x % b;
				x /= b;
				v[j] |= 1 << dig;
			}	
			ret = (ret + go(sum-i, v, i)) % MOD;
		}
	}
	return ma[sum][maxi][mask] = ret;
}

int main() {
	int st;
	scanf("%d",&st);
	Rep(test,st){
		cin>>n>>b;
		Rep(i,111)Rep(j,111)ma[i][j].clear();
		int res = go(n, VI(10,0), n);
		//cout<<"here"<<endl;
		cout<<"Case #"<<test+1<<": ";
		cout<<res<<endl;
	}	
	return 0;	
}
