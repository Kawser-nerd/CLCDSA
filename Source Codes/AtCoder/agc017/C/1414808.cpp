#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
int N,Q;
int a[200010];
int front[200010];
int cover[200010];
int covered;
 
void add(int x){
	int n = front[x]-1;
	if(n>0){
		if(cover[n]==0) covered++;
		cover[n]++;
	}
	front[x]--;
}
void erase(int x){
	int n = front[x];
	if(n>0){
		cover[n]--;
		if(cover[n]==0) covered--;
	}
	front[x]++;
}
 
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
	cin>>N>>Q;
	rep1(i,N) front[i] = i+1;
	rep(i,N){
		cin>>a[i];
		add(a[i]);
	}
	rep(t,Q){
		int x,v;
		cin>>x>>v;
		x--;
		int pv = a[x];
		erase(pv);
		add(v);
		a[x] = v;
		cout<<N-covered<<endl;
	}
}