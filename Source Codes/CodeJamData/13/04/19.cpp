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
using namespace std ;
using namespace __gnu_cxx ;
typedef long long LL ;
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

const int MAXKEYS = 210 ;
const int MAXN = 210 ;

int keysInHand[MAXKEYS] ;	            // ile mamy kluczy w rece
vector<int> notOpenChests[MAXKEYS]   ;  // ile jest nieotwartych skrzyni

int type[MAXN] ;   			 // jakiego typu jest skrzynia
vector<int> inside[MAXN] ;
bool isOpen[MAXN] ;

vector<int> ret ;

template<class T>
inline void erase(vector<T> &v, T a) {
	for(int i=0 ; i<v.size() ; i++) {
		if(v[i] == a) {
			swap(v[i], v.back()) ;
			v.pop_back() ;
			return ;
		}
	}
}

inline void open(int a) {
	ret.PB(a) ;
	erase(notOpenChests[ type[a] ], a) ;
	isOpen[a] = true ;
	keysInHand[ type[a] ]-- ;
	FOREACH(q, inside[a])
		keysInHand[*q]++ ;
}

inline void close(int a) {
	ret.pop_back() ;
	notOpenChests[ type[a] ].PB(a) ;
	isOpen[a] = false ;
	keysInHand[ type[a] ]++ ;
	FOREACH(q, inside[a])
		keysInHand[*q]-- ;
}

bool d[MAXKEYS] ;

bool tryToOpen(int a) {
	if(notOpenChests[type[a]].size()==1) { // jedyny wybor
		open(a) ;
		return true ; 
	}
	if(keysInHand[type[a]]>1) { // nie pogorszy
		open(a) ;
		return true ; 
	}
	
	open(a) ;
	
	CLEAR(d) ;
	queue<int> Q ;
	int k ;
	REP(k,MAXKEYS) {
		if(keysInHand[k]) {
			d[k] = true ;
//			cout << "mam klucz do " << k << endl ;
			Q.push(k) ;
		}
	}
	while(!Q.empty()) {
		k = Q.front() ; Q.pop() ;
		if(k == type[a]) return true ;
		FOREACH(u, notOpenChests[k]) {
			FOREACH(q, inside[*u]) {
				if(!d[*q]) {
					d[*q] = true ;
					Q.push(*q) ;
				}
			}
		}
	}
	
	close(a) ;
	return false ;
}

int main()
{
	ios_base::sync_with_stdio(0) ;
	int C ;
	cin >> C ;
	for(int tests=1 ; tests<=C ; tests++) {
		cout << "Case #" << tests << ": " ;
		int k, n, i, j, a ;
		CLEAR(keysInHand) ;
		CLEAR(isOpen) ;
		for(i=0 ; i<MAXKEYS ; i++)
			notOpenChests[i].clear() ;
		ret.clear() ;
		
		cin >> k >> n ;
		while(k--) {
			cin >> a ;
			keysInHand[a]++ ;
		}
		for(i=1 ; i<=n ; i++) {
			cin >> type[i] >> k ;
			notOpenChests[type[i]].PB(i) ;
			inside[i].clear() ;
			while(k--) {
				cin >> a ;
				inside[i].PB(a) ;
			}
		}
		
/*		cout << "mam klucze: " ;
		REP(i, MAXKEYS)
			if(keysInHand[i]) cout << i << " " ;
		cout << endl ;*/
		
		for(int counter=0 ; counter<n ; counter++) {
			for(i=1 ; i<=n ; i++) {
				if(keysInHand[type[i]] && !isOpen[i]) {
					if(tryToOpen(i))
						break ;
				}
			}
		}
		if(ret.size() != n) cout << "IMPOSSIBLE" << endl ;
		else {
			FOREACH(q, ret) cout << *q << " " ;
			cout << endl ;
		}
	}
}

