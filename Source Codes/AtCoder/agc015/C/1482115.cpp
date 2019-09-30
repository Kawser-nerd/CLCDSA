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
int n,m,q,a[2005][2005],b[2005][2005],c[2005][2005];
string s[2005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>q;
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=a[i][j-1]+s[i-1][j-1]-'0';
		}
		for(int j=1;j<=m;j++){
			a[i][j]+=a[i-1][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++){
			b[i][j]=b[i][j-1]+(s[i-1][j-1]=='1' && s[i-1][j-2]=='1');
		}
		for(int j=2;j<=m;j++){
			b[i][j]+=b[i-1][j];
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=2;i<=n;i++){
			c[i][j]=c[i-1][j]+(s[i-1][j-1]=='1' && s[i-2][j-1]=='1');
		}
		for(int i=2;i<=n;i++){
			c[i][j]+=c[i][j-1];
		}
	}
	while(q--){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		int a1=a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
		int b1=b[x2][y2]-b[x1-1][y2]-b[x2][y1]+b[x1-1][y1];
		int c1=c[x2][y2]-c[x1][y2]-c[x2][y1-1]+c[x1][y1-1];
		cout<<a1-b1-c1<<endl;
	}
	return 0;
}