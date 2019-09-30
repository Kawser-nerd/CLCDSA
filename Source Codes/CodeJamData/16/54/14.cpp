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

int N,L;
string good[110];
string bad;

void main2(void){
	int i;
	
	cin >> N >> L;
	REP(i,N) cin >> good[i];
	cin >> bad;
	
	REP(i,N) if(good[i] == bad){
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	
	string s;
	REP(i,L){
		if(bad[i] == '0'){
			s += "10";
		} else {
			s += "01";
		}
	}
	s = s.substr(0, 2*L-1);
	
	string t;
	REP(i,L){
		if(bad[i] == '0'){
			t += "1?";
		} else {
			t += "0?";
		}
	}
	
	cout << s << ' ' << t << endl;
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
