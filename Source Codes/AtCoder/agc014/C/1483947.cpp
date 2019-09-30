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
#define X first
#define Y second
using namespace std;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int h,w,k,dist[805][805],d[805][805];
string b[805];
pair<int,int> s;
queue<pair<int,int> > q,q2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>h>>w>>k;
	for(int i=0;i<h;i++){
		cin>>b[i];
		for(int j=0;j<w;j++){
			if(b[i][j]=='S'){
				s.X=i;
				s.Y=j;
				break;
			}
		}
	}
	setINF(dist);
	setINF(d);
	dist[s.X][s.Y]=d[s.X][s.Y]=0;
	q.push(s);
	q2.push(s);
	while(!q.empty()){
		pair<int,int> u=q.front();
		q.pop();
		if(dist[u.X][u.Y]>=k)continue;
		for(int o=0;o<4;o++){
			pair<int,int> v;
			v.X=u.X+dx[o];
			v.Y=u.Y+dy[o];
			if(v.X<0 || v.X>=h || v.Y<0 || v.Y>=w || b[v.X][v.Y]=='#' || dist[v.X][v.Y]<INF)continue;
			dist[v.X][v.Y]=dist[u.X][u.Y]+1;
			d[v.X][v.Y]=0;
			q.push(v);
			q2.push(v);
		}
	}
	while(!q2.empty()){
		pair<int,int> u=q2.front();
		q2.pop();
		for(int o=0;o<4;o++){
			pair<int,int> v;
			v.X=u.X+dx[o];
			v.Y=u.Y+dy[o];
			if(v.X<0 || v.X>=h || v.Y<0 || v.Y>=w || d[v.X][v.Y]<INF)continue;
			d[v.X][v.Y]=d[u.X][u.Y]+1;
			q2.push(v);
		}
	}
	int ans=INF;
	for(int i=0;i<max(h,w);i++){
		if(i<h)ans=min(ans,min(d[i][0],d[i][w-1]));
		if(i<w)ans=min(ans,min(d[0][i],d[h-1][i]));
	}
	if(!ans)cout<<"1\n";
	else cout<<(ans-1)/k+2<<endl;
	return 0;
}