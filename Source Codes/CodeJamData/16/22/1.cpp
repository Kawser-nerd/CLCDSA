#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define _abs(x) ((x)>0?(x):-(x))

typedef long long ll;
#define INF (1ll<<60)
ll ansA,ansB;

ll parse(string s){
	ll ans = 0;
	int i;
	REP(i,s.length()) ans = ans * 10 + (s[i] - '0');
	return ans;
}

void answer(ll A, ll B){
	if(_abs(A - B) < _abs(ansA - ansB)){
		ansA = A;
		ansB = B;
	} else if(_abs(A - B) == _abs(ansA - ansB) && make_pair(A, B) < make_pair(ansA, ansB)){
		ansA = A;
		ansB = B;
	}
}

void print(int N, ll x){
	int i;
	string s;
	REP(i,N){
		s = (char)('0' + x%10) + s;
		x /= 10;
	}
	cout << s;
}

void check(int N, string A, string B, int k, int p, int q, int r, int s){
	int i;
	string AA = A, BB = B;
	
	REP(i,k){
		char c = '0';
		if(A[i] != '?') c = A[i];
		if(B[i] != '?') c = B[i];
		if(AA[i] == '?') AA[i] = c;
		if(BB[i] == '?') BB[i] = c;
	}
	
	if(k < N){
		if(AA[i] == '?') AA[i] = '0' + p;
		if(BB[i] == '?') BB[i] = '0' + q;
	}
	
	string t = "09";
	for(i=k+1;i<N;i++){
		if(AA[i] == '?') AA[i] = t[r];
		if(BB[i] == '?') BB[i] = t[s];
	}
	
	answer(parse(AA), parse(BB));
}

void main2(void){
	int i,p,q,r,s;
	
	string A,B;
	cin >> A >> B;
	
	ansA = INF;
	ansB = 0;
	
	int N = A.length();
	REP(i,N+1) REP(p,10) REP(q,10) REP(r,2) REP(s,2) check(N, A, B, i, p, q, r, s);
	
	print(N, ansA);
	cout << ' ';
	print(N, ansB);
	cout << endl;
}

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc+1);
		main2();
	}
	return 0;
}
