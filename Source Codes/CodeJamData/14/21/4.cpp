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

int N;
string t[110];
vector <int> v[110];

pair <string, vector <int> > func(string s){
	int i,j;
	string t;
	vector <int> v;
	
	REP(i,s.length()) if(i == 0 || s[i] != s[i-1]){
		for(j=i;j<s.length();j++) if(s[j] != s[i]) break;
		t += s[i];
		v.push_back(j-i);
	}
	
	return make_pair(t, v);
}

int get_cost(vector <int> v){
	int N=v.size(),i;
	sort(v.begin(),v.end());
	int ans = 0;
	REP(i,N) ans += abs(v[i] - v[N/2]);
	return ans;
}

void main2(void){
	int i,j,k;
	
	cin >> N;
	REP(i,N){
		string s;
		cin >> s;
		pair <string, vector <int> > p = func(s);
		t[i] = p.first;
		v[i] = p.second;
	}
	
	REP(i,N) if(t[i] != t[0]){
		cout << "Fegla Won" << endl;
		return;
	}
	
	int ans = 0;
	int L = v[0].size();
	REP(i,L){
		vector <int> w;
		REP(j,N) w.push_back(v[j][i]);
		ans += get_cost(w);
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
