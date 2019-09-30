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

#define X 21
#define T (1<<X)

typedef long long ll;

ll x[510];

int sz;
ll a[T],b[T],tmp[T];

void adda(ll x){
	int i,j;
	
	i = j = 0;
	while(i < sz || j < sz){
		if(j == sz || (i < sz && a[i] < a[j] + x)){
			tmp[i+j] = a[i];
			i++;
		} else {
			tmp[i+j] = a[j] + x;
			j++;
		}
	}
	
	sz *= 2;
	REP(i,sz) a[i] = tmp[i];
}

void addb(ll x){
	int i,j;
	
	i = j = 0;
	while(i < sz || j < sz){
		if(j == sz || (i < sz && b[i] < b[j] + x)){
			tmp[i+j] = b[i];
			i++;
		} else {
			tmp[i+j] = b[j] + x;
			j++;
		}
	}
	
	sz *= 2;
	REP(i,sz) b[i] = tmp[i];
}

bool dfsa(ll sum, int mask, int pos){
	int i;
	
	if(pos == X){
		if(sum != 0) return false;
		vector <int> v;
		REP(i,X) if(mask&(1<<i)) v.push_back(i);
		REP(i,v.size()){
			cout << x[v[i]];
			if(i + 1 == v.size()) cout << endl; else cout << ' ';
		}
		return true;
	}
	
	dfsa(sum - x[pos], (mask | (1<<pos)), pos + 1);
	dfsa(sum, mask, pos + 1);
}

bool dfsb(ll sum, int mask, int pos){
	int i;
	
	if(pos == X){
		if(sum != 0) return false;
		vector <int> v;
		REP(i,X) if(mask&(1<<i)) v.push_back(X+i);
		REP(i,v.size()){
			cout << x[v[i]];
			if(i + 1 == v.size()) cout << endl; else cout << ' ';
		}
		return true;
	}
	
	dfsb(sum - x[X+pos], (mask | (1<<pos)), pos + 1);
	dfsb(sum, mask, pos + 1);
}

void main2(void){
	int N,i,j;
	
	cin >> N;
	REP(i,N) cin >> x[i];
	
	while(1){
		random_shuffle(x,x+N);
		
		sz = 1;
		a[0] = 0;
		REP(i,X) adda(x[i]);
		
		sz = 1;
		b[0] = 0;
		REP(i,X) addb(x[X+i]);
		
		i = j = 1;
		while(i < T && j < T){
			if(a[i] == b[j]){
				break;
			} else if(a[i] < b[j]){
				i++;
			} else {
				j++;
			}
		}
		
	//	cout << a[i] << ' ' << b[j] << endl;
		
		if(i < T && j < T){
			dfsa(a[i],0,0);
			dfsb(b[j],0,0);
			return;
		}
	}
}

int main(void){
	int tc,t;
	cin >> tc;
	REP(t,tc){
		printf("Case #%d:\n",t+1);
		main2();
	}
	return 0;
}
