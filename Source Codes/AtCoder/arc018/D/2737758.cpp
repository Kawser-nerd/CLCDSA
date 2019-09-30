#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>

using namespace std;
typedef long long LL;
typedef array<int,3> A;
// a>=0, b>=0, x*a+y*b=gcd>=0, a>0,b>0=>abs(y)<=a,abs(x)<=b
LL gcdex(LL a,LL b,LL& x, LL& y){
	LL ax=1,ay=0;
	LL bx=0,by=1;
	while(b){
		LL r=a/b;
		LL t=a-r*b; a=b; b=t;
		LL tx=ax-r*bx; ax=bx; bx=tx;
		LL ty=ay-r*by; ay=by; by=ty;
	}
	x=ax;
	y=ay;
	return a;
}
LL modinv(LL a, LL m){
	LL x,y;
	gcdex(a,m,x,y);
	if(x<0){
		x+=m;
	} else if(x>=m){
		x-=m;
	}
	return x;
}
const LL M=1e9+7;
template<int NN>
LL det(LL p[NN][NN], int n){
	LL ret=1;
	for(int i=0;i<n;i++){
		int d=i;
		for(int j=i;j<n;j++){
			if(p[j][i]){
				d=j;
			}
		}
		// ???
		if(d==n){
			return 0;
		}

		if(d!=i){
			for(int j=i;j<n+1;j++){
				swap(p[i][j],p[d][j]);
			}
			ret*=M-1;
			ret%=M;
		}
		LL inv=modinv(p[i][i],M);
		ret*=p[i][i];
		ret%=M;
		for(int j=i+1;j<n;j++){
			auto r=p[j][i]*inv%M;
			for(int k=i;k<n+1;k++){
				p[j][k]+=(M-r*p[i][k]%M);
				p[j][k]%=M;
			}
		}
	}
	assert(ret>=0);
	return ret;
}



const int U=10*1000;
int rep[U];
int Find(int i){
	while(rep[i]!=i){
		i=rep[i]=rep[rep[i]];
	}
	return i;
}
void Union(int i,int j){
	i=Find(i);
	j=Find(j);
	rep[i]=j;
}
vector<int> es[U];
map<int,int> order;
void dfs(int r){
	order[r]=order.size();
	for(int i:es[r]){
		if(order.count(i)==0){
			dfs(i);
		}
	}
}
int main() {
	int N,m;
	cin >> N >> m;
	for(int i=0;i<N;i++){
		rep[i]=i;
	}
	vector<A> e;
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		a--;b--;
		e.push_back({{c,a,b}});
	}
	sort(e.begin(),e.end());
	LL mat[101][101];
	LL ret0=0;
	LL ret=1;
	for(int i=0;i<e.size();){
		int j=i;
		vector<int> vs;
		while(j<e.size()&&e[i][0]==e[j][0]){
			int a=Find(e[j][1]);
			int b=Find(e[j][2]);
			if(a==b){
				j++;
				continue;
			}
			vs.push_back(a);
			vs.push_back(b);
			es[a].push_back(b);
			es[b].push_back(a);
			j++;
		}
		sort(vs.begin(),vs.end());
		vs.resize(unique(vs.begin(),vs.end())-vs.begin());
		for(auto k:vs){
			if(es[k].size()==0){
				continue;
			}

			dfs(k);
			int s=order.size();
			for(int i=0;i<s-1;i++){
				for(int j=0;j<s-1;j++){
					mat[i][j]=0;
				}
			}
			for(auto p:order){
				for(auto q:es[p.first]){
					mat[p.second][order[q]]--;
				}
				mat[p.second][p.second]=es[p.first].size();
				es[p.first].clear();
			}
			for(int i=0;i<s-1;i++){
				for(int j=0;j<s-1;j++){
					if(mat[i][j]<0){
						mat[i][j]+=M;
					}
				}
			}
			auto v=det(mat,s-1);
			//cerr << v << endl;
			ret*=v;
			ret%=M;
			order.clear();
		}
		for(int k=i;k<j;k++){
			int a=Find(e[k][1]);
			int b=Find(e[k][2]);
			if(a!=b){
				Union(a,b);
				ret0+=e[k][0];
			}
		}
		i=j;
	}
	cout << ret0 << " " << ret << endl;
	return 0;
}