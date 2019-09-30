#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif
#pragma comment(linker, "/STACK:1024000000,1024000000") 
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EPS 1e-10
#define set0(x) memset((x),0,sizeof(x))
#define setINF(x) memset((x),63,sizeof(x))
using namespace std;
int n,m,iter[100005],dist[1100005],vis[100005];
vector<pair<int,int> > og[100005];
vector<int> st[1000005],g[1100005];
queue<int> q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v,c;
		cin>>u>>v>>c;
		--u;
		--v;
		og[u].push_back(make_pair(c,v));
		og[v].push_back(make_pair(c,u));
		st[c].push_back(u);
		st[c].push_back(v);
	}
	for(int i=0;i<n;i++){
		sort(og[i].begin(),og[i].end());
	}
	int newn=n;
	for(int col=1;col<=1000000;col++){
		if(st[col].empty())continue;
		for(int i=0;i<st[col].size();i++){
			int u=st[col][i];
			if(vis[u]==col)continue;
			vector<int> cur;
			q.push(u);
			vis[u]=col;
			while(!q.empty()){
				int v=q.front();
				q.pop();
				cur.push_back(v);
				while(iter[v]<og[v].size()){
					int x=og[v][iter[v]].first;
					if(x!=col)break;
					int u=og[v][iter[v]].second;
					if(vis[u]!=col){
						vis[u]=col;
						q.push(og[v][iter[v]].second);
					}
					iter[v]++;
				}
			}
			for(int i=0;i<cur.size();i++){
				g[newn].push_back(cur[i]);
				g[cur[i]].push_back(newn);
			}
			newn++;
		}
	}
	setINF(dist);
	dist[0]=0;
	q.push(0);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(dist[v]<INF)continue;
			dist[v]=dist[u]+1;
			q.push(v);
		}
	}
	if(dist[n-1]==INF)cout<<"-1\n";
	else cout<<dist[n-1]/2<<endl;
	return 0;
}