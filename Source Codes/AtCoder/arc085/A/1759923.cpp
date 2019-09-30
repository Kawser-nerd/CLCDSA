#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <utility>
#include <tuple>
#include <cctype>
using namespace std;
#define INF 0x3f3f3f3f
//#define INF 1100000000000000000LL
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pint;
typedef tuple<int,int,int> tint;
typedef vector<int> vint;
typedef vector<ll> vll;
int dx[8]={0,0,-1,1,1,1,-1,-1};
int dy[8]={-1,1,0,0,1,-1,1,-1};
const int SIZE=100050;
//????????
int main(){
	int N,M;
	cin>>N>>M;
	ll ans=N-M+M*19;
	for(int i=0;i<M;i++){
		ans*=2;
	}
	ans*=100;
	cout<<ans<<endl;
	return 0;
}