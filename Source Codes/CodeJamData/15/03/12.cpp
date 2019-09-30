#include <iostream>
#include <numeric>
#include <iterator>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <stack>
#include <string>
#include <sstream>
#include <math.h>

#define REP(i,n) for(int i = 0; i<(n); i++)
#define ITER(i,v) for(auto i : v)
#define INF 1000000000
#define F(v) (v).begin(), (v).end()
#ifdef DEBUG
const bool DEBUG = true;
#else
const bool DEBUG = false;
#endif

using namespace std;

template <class T>
using priority_queue_asc =  priority_queue<T,vector<T>, greater<T> >;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<bool> vb;

array<array<int,4>,4> mult{{
	{{0,1,2,3}},
	{{1,4,3,6}},
	{{2,7,4,1}},
	{{3,2,5,4}}
}};


struct quad{
	int v; // 0,1,2,3 for 1,i,j,k
	// 4567 for -1ijk
	quad operator*(quad r){
		int q = mult[v & 3][r.v & 3];
		q ^= (v^r.v)&4;
		//cerr << v<<"*"<<r.v<<"="<<q<<"\n";
		return {q};
	}
	quad(char c){
		v = c-'h';
	}
	quad(int i) :v(i){}
	quad() : v(0){}
	
};

const quad target = quad('i')*quad('j')*quad('k');

int main(){
	//ios_base::sync_with_stdio(false);cin.tie(0);
	int TC; cin >> TC;
	for(int tc = 1; tc <= TC; tc++){
		ll L,X; cin >> L >> X;
		if(X>=12){
			X = (X%12) + 12;
		}
		// first read the string of quad
		vector<quad> l(L);
		REP(i,L){
			char c;
			cin >> c;
			l[i] = quad(c);
			//cerr << c<<"\t";
			//cerr << l[i].v<<"\n";
		}

		quad curtarget(1); // first try to make i
		quad cur(0);
		REP(x,X){
			REP(i,L){
				cur = cur * l[i];
				//cerr << "current: "<<cur.v<<"\n";
				if(cur.v == curtarget.v && curtarget.v != 3){
					curtarget.v++;
					cur.v=0;
					//cerr << "curtarget is now "<<curtarget.v<<"\n";
				}
			}
		}
		bool ans=curtarget.v == 3 && cur.v==3;
		cout << "Case #"<<tc<<": "<< (ans ? "YES":"NO")<<" \n";

	}
	return 0;
}


