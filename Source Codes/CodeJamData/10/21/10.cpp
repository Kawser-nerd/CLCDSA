#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(i,a,b) for (int i=(a); i<=(b); ++i)
#define FORD(i,a,b) for (int i=(a); i>=(b); --i)
#define FORE(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define debug(x) cerr << #x << " = " << x << "\n";
#define debugv(x) cerr << #x << " = "; FORE(it,(x)) cerr<< *it <<","; cerr<<"\n";
#define PB push_back
#define ALL(x) (x).begin(),(x).end()
#define CLR(x) memset(x,0,sizeof x)
#define xx first
#define yy second
typedef long long int lli;
typedef pair<int, int> P;
typedef vector<int> vi;

template<class C>
vector<C> split(string s,char spec=' '){
        FORE(i,s) if(*i == spec) *i=' ';
            vector<C> res;
                stringstream ss(s);
                    C buf;
                        while(ss >> buf) res.PB(buf);
                            return res;
}

int T,N,M;
set<string> S;
string s;

int main(){
	cin >> T;
	FOR(cas,1,T){
        int res = 0;
        S.clear();
        S.insert("");
        cin >> N >> M;
        REP(i,N){
            cin >> s;
            S.insert(s);
        }
        REP(i,M){
            cin >> s;
            while(!S.count(s)){
                S.insert(s);
                res++;
                int i = s.size() - 1;
                while(s[i] != '/') i--;
                s = s.substr(0,i);
            }
        }
		cout << "Case #" << cas << ": " << res << endl;
	}
	return 0;
}
