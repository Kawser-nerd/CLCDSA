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

string two = "oieastbg";
string s;

bool graph[40][40];

void main2(void){
	int i,j,k,tmp;
	
	cin >> tmp >> s;
	
	REP(i,40) REP(j,40) graph[i][j] = false;
	int N = s.length();
	REP(i,N-1){
		graph[s[i]-'a'][s[i+1]-'a'] = true;
		REP(j,8) if(s[i] == two[j]) graph[26+j][s[i+1]-'a'] = true;
		REP(j,8) if(s[i+1] == two[j]) graph[s[i]-'a'][26+j] = true;
		REP(j,8) REP(k,8) if(s[i] == two[j] && s[i+1] == two[k]) graph[26+j][26+k] = true;
	}
	
	int ans = 1;
	REP(i,40) REP(j,40) if(graph[i][j]) ans++;
	
	int sum = 0;
	REP(i,40){
		int deg = 0;
		REP(j,40) if(graph[i][j]) deg++;
		REP(j,40) if(graph[j][i]) deg--;
		if(deg > 0) sum += deg;
	}
	
	if(sum > 0) ans += sum - 1;
	
	cout << ans << endl;
}

//////////////////////////////// multiple testcases ////////////////////////////////

int main(void){
	int T,t;
	scanf("%d",&T);
	REP(t,T){
		printf("Case #%d: ",t+1);
		main2();
	}
	return 0;
}
