#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cassert>
#include <cstring>
#include <ext/numeric>
#include <gmpxx.h>
using namespace std ;
using namespace __gnu_cxx ;
typedef mpz_class LL ;
const int INF = 1000*1000*1000 ;
const LL INFLL = (LL)INF * (LL)INF ;
#define REP(i,n) for(i=0;i<(n);++i)
#define ALL(c) c.begin(),c.end()
#define VAR(v,i) __typeof(i) v=(i)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define CLEAR(t) memset(t,0,sizeof(t))
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

const int MAXN = 110 ;
LL w[MAXN][10] ;    // w[i][j] = ile jest ciagow palindromicznych dlugosci n, ktorych suma kwadratow <= j
LL p[MAXN]     ;    // p[i]    = ile jest palindromow dlugosci <= n (dobrych)


void prepare() {
	for(int j=0 ; j<10 ; j++) w[0][j] = 1 ;
	w[1][0] = 1 ;
	for(int j=1 ; j<10 ; j++) {
		int a = sqrt(j) ;
		w[1][j] = w[1][j-1] + (a*a==j) ;
	}
	for(int i=2 ; i<MAXN ; i++)
		for(int j=0 ; j<10 ; j++)
			for(int k=0 ; j-2*k*k>=0 ; k++)
				w[i][j] += w[i-2][j-2*k*k] ;
	
	p[0] = 0 ;
	p[1] = 3 ;
	for(int i=2 ; i<MAXN ; i++) {
		p[i] = p[i-1] ;
		for(int j=1 ; 2*j*j<=9 ; j++)
			p[i] += w[i-2][9-(2*j*j)] ;
	}
}

LL f(mpz_class x) {
	if(x==0) return 0 ;
	mpz_class y = sqrt(x) ;
	string num = y.get_str(), pref="" ;
	int n = num.size() ;
	LL ret = p[n-1] ;
	int kw_sum = 0 ;
	for(int i=0 ; i<(n-1)/2 ; i++) {
		for(int j=(i==0) ; j+'0'<num[i] && kw_sum+2*j*j<=9 ; j++) {
			ret += w[n-2*(i+1)][9-(kw_sum+2*j*j)] ;
		}
		kw_sum += 2*(num[i]-'0')*(num[i]-'0') ;
		pref += num[i] ;
	}
	string revPref = pref ;
	reverse(ALL(revPref)) ;
	int ile = 1+!(n%2) ;
	for(int j=(n<=2) ; j+'0' <= num[(n-1)/2] && kw_sum+ile*j*j<=9 ; j++) {
		if(pref + string(ile, j+'0') + revPref <= num) ret++ ;
	}
	return ret ;
}

int main()
{
	ios_base::sync_with_stdio(0) ;
	prepare() ;
	int C ;
	cin >> C ;
	for(int tests=1 ; tests<=C ; tests++) {
		cout << "Case #" << tests << ": " ;
		mpz_class A, B ;
		cin >> A >> B ;
		cout << f(B) - f(A-1) << endl ;
	}
}

