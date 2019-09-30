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
const int SIZE=2050;
//????????
int main(){
	int N,Z,W;
	cin>>N>>Z>>W;
	ll a[SIZE];
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	if(N==1){
		cout<<abs(W-a[0])<<endl;
		return 0;
	}
	cout<<max(abs(W-a[N-1]),abs(a[N-1]-a[N-2]))<<endl;
	return 0;
}