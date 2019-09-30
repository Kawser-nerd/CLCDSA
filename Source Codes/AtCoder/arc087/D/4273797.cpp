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

const LL M=1e9+7;
const int L=5001;
vector<int> ps[L];
int ww[L];
int N;
LL C[L][L];
LL F[L];
vector<int> cs;
int dfs(int i,int r){
	int s=1;
	bool center=true;
	for(auto p:ps[i]){
		if(p==r)continue;
		int v=dfs(p,i);
		if(v>N/2){
			center=false;
		}
		s+=v;
	}
	ww[i]=s;
	if(N-s>N/2){
		center=false;
	}
	if(center){
		cs.push_back(i);
	}
	//cerr << i << ", " << ww[i] << endl;
	return s;
}
LL dp[L][L];
int main() {
	cin >> N;
	for(int i=1;i<N;i++){
		int x,y;
		cin >> x >> y;
		ps[x].push_back(y);
		ps[y].push_back(x);
	}
	dfs(1,0);
	for(int i=0;i<L;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%M;
		}
	}
	F[0]=1;
	for(int i=1;i<L;i++){
		F[i]=F[i-1]*i%M;
	}
	//cerr << cs.size() << endl;
	if(cs.size()==2){
		cout << F[N/2]*F[N/2]%M << endl;
		return 0;
	}
	int c=cs[0];
	for(auto p:ps[c]){
		if(ww[p]>ww[c]){
			ww[p]=N-ww[c];
		}
	}
	dp[0][0]=1;
	int sum=0;
	for(int i=0;i<ps[c].size();i++){
		auto w=ww[ps[c][i]];
		for(int j=0;j<=sum;j++){
			for(int k=0;k<=w;k++){
				dp[i+1][j+k]+=dp[i][j]*C[w][k]%M*C[w][k]%M*F[k]%M;
				dp[i+1][j+k]%=M;
			}
		}
		sum+=w;
	}
	int sg=1;
	LL ret=0;
	for(int i=0;i<=N;i++){
		//cerr << F[N-i] << ", " << dp[ps[c].size()][i] << endl;
		ret+=(M+sg)*F[N-i]%M*dp[ps[c].size()][i]%M;
		ret%=M;
		sg*=-1;
		//cerr << ret << endl;
	}
	cout << ret << endl;

	return 0;
}