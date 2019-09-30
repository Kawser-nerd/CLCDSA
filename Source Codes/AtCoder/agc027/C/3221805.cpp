#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
#include<cassert>
using namespace std;
#define pb push_back
#define pf push_front
typedef long long lint;
typedef complex<double> P;
#define mp make_pair
#define fi first
#define se second
typedef pair<int,int> pint;
#define All(s) s.begin(),s.end()
#define rAll(s) s.rbegin(),s.rend()
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
//???????????????????
//????10^5?????2×10^5????????????????????????????
//???????????????????????
int an[200100],bn[200100];
bool sumi[200100];
vector<int> gr[200100];
queue<int> q;
int main()
{
	string s;int n,m,a,b;
	cin>>n>>m;cin>>s;
	rep(i,m){
		cin>>a>>b;a--;b--;
		if(s[a]=='A') an[b]++;else bn[b]++;
		if(s[b]=='A') an[a]++;else bn[a]++;
		gr[a].pb(b);gr[b].pb(a);
	}
	rep(i,n){
		if(an[i]<1 || bn[i]<1){
			q.push(i);
			sumi[i]=true;
		}
	}
	while(!q.empty()){
		int p=q.front();q.pop();
		//cout<<p<<endl;
		//if(!sumi[p]) cout<<"hoge"<<endl;
		rep(i,gr[p].size()){
			int v=gr[p][i];
			if(sumi[v]) continue;
			//cout<<v<<'a'<<endl;
			if(s[p]=='A') an[v]--;else bn[v]--;
			if(an[v]<1 || bn[v]<1){
				sumi[v]=true;q.push(v);
			}
		}
	}
	rep(i,n){
		if(!sumi[i]){
			cout<<"Yes"<<endl;return 0;
		}
	}
	cout<<"No"<<endl;
}