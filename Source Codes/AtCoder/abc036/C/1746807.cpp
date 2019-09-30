#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<memory>
#include<functional>
#include<set>
 
using namespace std;
 
#define ALL(g) (g).begin(),(g).end()
#define REP(i, x, n) for(int i = x; i < n; i++)
#define rep(i,n) REP(i,0,n)
#define F(i,j,k) fill(i[0],i[0]+j*j,k)
#define P(p) cout<<(p)<<endl;
#define pb push_back
#define INF 1<<25
 
typedef long long ll;

int dy[8]={1,1,1,0,0,-1,-1,-1};
int dx[8]={-1,0,1,-1,1,-1,0,1};
struct S{
	int a,b,c;
};
bool asc(const S& left,const S& right){
	return left.c > right.c;
}

int main(){
	int N;
	cin>>N;
	vector<int>a(N);
	map<int,int>mp;
	set<int>st;
	rep(i,N){
		cin>>a[i];
		st.insert(a[i]);
	}
	int cnt=0;
	for(auto it=st.begin();it!=st.end();it++){
		mp[*it]=cnt;
		cnt++;
	}
	vector<int>ans(N);
	rep(i,N){
		ans[i]=mp[a[i]];
	}
	rep(i,ans.size()){
		cout<<ans[i]<<endl;
	}
	return 0;
}