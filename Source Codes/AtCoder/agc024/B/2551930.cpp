#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include<map>
using namespace std;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

typedef long long LL;
const LL mod=1000000007;
#define MAX 10000
#define NIL -1
const double PI  = acos(-1.0);
const int INF = 1e9 + 7;
//-------------------------------------------



int main(){
	int n;
	cin >> n;
	map<int,int> mp;
	
	for(int i = 0;i < n;i++){
		int p;
		cin >> p;
		mp[p] = i+1;
	}
	
	int cnt = 1;
	int temp = 1;
	for(int i = 1;i <= n;i++){
		if(mp[i] < mp[i+1]){
			temp++;
		}else{
			cnt = max(cnt,temp);
			temp = 1;
		}
	}
	
	cout << n - cnt << endl;
	return 0;
}