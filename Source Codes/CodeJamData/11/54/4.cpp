#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;

string s;
string ans;

bool check(void){
	int N=s.length(),i;
	
	ll x = 0;
	REP(i,N) if(s[i] == '1') x |= (1ll<<(N-1-i));
	
	ll d = (ll)(sqrt((double)x) + 0.5);
	return (x == d*d);
}

void dfs(int pos){
	if(pos == s.length()){
		if(check()) ans = s;
		return;
	}
	
	if(s[pos] != '?'){
		dfs(pos+1);
		return;
	}
	
	s[pos] = '0';
	dfs(pos+1);
	s[pos] = '1';
	dfs(pos+1);
	s[pos] = '?';
}

void main2(void){
	cin >> s;
	ans = "";
	dfs(0);
	cout << ans << endl;
}

//////////////////////////////// multiple testcases ////////////////////////////////

int main(void){
	int T,t;
	scanf("%d",&T);
	REP(t,T){
		printf("Case #%d: ",t+1);
		main2();
	}
	return 0;
}
