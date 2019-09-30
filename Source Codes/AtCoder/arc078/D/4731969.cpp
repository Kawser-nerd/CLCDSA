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

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

int dp[1<<15][15];
bool done[1<<15][15];
int tb[1<<15];
int cs[15][15];
int main() {
	int N,M;
	cin >> N >> M;
	for(int i=0;i<M;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		a--;b--;
		cs[a][b]=cs[b][a]=c;
	}
	for(int u=0;u<(1<<N);u++)
	{
		for(int i=0;i<N;i++){
			dp[u][i]=-(1<<29);
			if(!(u&(1<<i)))continue;
			for(int j=i+1;j<N;j++){
				if(!(u&(1<<j)))continue;
				tb[u]+=cs[i][j];
			}
		}
		//cerr << u << ": " << tb[u] << endl;
	}
	dp[1][0]=0;
	for(int u=1;u<(1<<N);u+=2)
	{
		for(int i=1;i<N;i++){
			if(!(u&(1<<i)))continue;
			for(int j=0;j<N;j++){
				if(!(u^(1<<j))||!cs[i][j])continue;
				dp[u][i]=max(dp[u][i],dp[u^(1<<i)][j]+cs[j][i]);
			}
		}
		for(int v=u;v>0;v=(v-1)&u){
			for(int i=0;i<N;i++){
				if(!(v&(1<<i)))continue;
				dp[u][i]=max(dp[u][i],dp[u^v^(1<<i)][i]+tb[v]);
			}
		}
#if 0
		for(int i=0;i<N;i++){
			cerr << u << ", "  << i << ": " << dp[u][i]/100<< endl;
		}
#endif
	}
	//cerr << dp[(1<<N)-1][N-1]<<endl;
	cout << tb[(1<<N)-1]-dp[(1<<N)-1][N-1] << endl;



	return 0;
}