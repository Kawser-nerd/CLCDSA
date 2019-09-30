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

string s[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int freq[30];
int ans[10];

void check(int d){
	int i;
	REP(i,s[d].length()) freq[s[d][i] - 'A']--;
}

void main2(void){
	int i,j;
	
	string t;
	cin >> t;
	
	REP(i,30) freq[i] = 0;
	REP(i,t.length()) freq[t[i]-'A']++;
	
	REP(i,10) ans[i] = 0;
	ans[0] = freq['Z' - 'A'];
	ans[2] = freq['W' - 'A'];
	ans[4] = freq['U' - 'A'];
	ans[6] = freq['X' - 'A'];
	ans[8] = freq['G' - 'A'];
	
	REP(i,10) REP(j,ans[i]) check(i);
	
	ans[1] = freq['O' - 'A'];
	ans[3] = freq['H' - 'A'];
	ans[5] = freq['F' - 'A'];
	ans[7] = freq['S' - 'A'];
	
	REP(i,10) if(i%2 == 1) REP(j,ans[i]) check(i);
	
	ans[9] = freq['I' - 'A'];
	
	string ss;
	REP(i,10) REP(j,ans[i]) ss += (char)('0' + i);
	cout << ss << endl;
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
