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

typedef long long ll;
	
string s;
map <int, int> mp;

void add(int x, int c){
	int tmp = mp[x];
	tmp = (tmp + c) % 256;
	mp[x] = tmp;
}
	
void main2(void){
	int i;
	int jump = -1;
	int shift = 0, moves = 0;
	
	cin >> s;
	REP(i,s.length()) if(s[i] == '(') jump = i;
	
	if(jump != -1){
		for(i=jump+1;;i++){
			if(s[i] == ')') break;
			if(s[i] == 'b'){
				shift--;
				moves++;
			}
			if(s[i] == 'f'){
				shift++;
				moves++;
			}
		}
	}
	
	mp.clear();
	
	int pos = 0;
	ll ans = 0;
	int x = 0;
	int CNT = 0;
	
	while(pos < s.length()){
		if(s[pos] == 'b'){
			x--;
			ans++;
			pos++;
		} else if(s[pos] == 'f'){
			x++;
			ans++;
			pos++;
		} else if(s[pos] == 'u'){
			add(x, 1);
			pos++;
		} else if(s[pos] == 'd'){
			add(x, 255);
			pos++;
		} else if(s[pos] == ')'){
			if(mp[x] == 0 && x > -50000 && x < 50000){
				// cerr << x << endl;
				pos++;
			} else {
				pos = jump;
				if(abs(x) > 100000){
					ll steps = ((1ll<<40) - 80000 - abs(x)) / abs(shift);
					ans += steps * moves;
					ll y = x + steps * shift;
					if(y < 0) y += (1ll<<40); else y -= (1ll<<40);
					x = y;
				}
			}
			// cout << x << endl;
		} else {
			pos++;
		}
	}
	
	cout << ans << endl;
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
