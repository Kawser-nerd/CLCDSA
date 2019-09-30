#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <cmath>
#include <sstream>
using namespace std;
#define PB push_back
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define FORE(i,x) for(__typeof((x).begin()) i=(x).begin();i != (x).end();++i)
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,w) memset((x),w,sizeof (x))
#define X first
#define Y second
typedef long long int lli;
typedef pair<int, int> P;
typedef vector<int> VI;

#define MAXN 207
int s[MAXN], n, sum;

bool test(int i, double q){
	double pot = q, score = s[i] + q * sum;
	REP(j,n) if(i != j) {
		pot += max(0.0, (score - s[j]) / (double)sum);
		if(pot > 1.0)
			return false;
	}
	return true;
}

int main(){ 
	int T;
	cin >> T;
	FOR(t,1,T){
		//in
		cin >> n;
		REP(i,n) cin >> s[i];
		sum = 0;
		REP(i,n) sum += s[i];
		//out
		cout << "Case #" << t << ": ";
		REP(i,n){
			double l=0,r=1;
			REP(wqewq,50){
				double q=(l+r)/2;
				if(test(i,q))
					l=q;
				else
					r=q;
			}
			printf("%.9lf ", l * 100);
		}
		cout << endl;
	}
    return 0;
}
