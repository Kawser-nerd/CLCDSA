#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;


char S[13][13];
int H,W;
vector<P> ps;
bool us[13],vs[13];
bool g();
bool f(){
#if 0
	if(ps.size()>10){
		for(auto p:ps){
			cerr << p.first << ", " << p.second << endl;
		}
		exit(0);
	}
#endif
	int t=0;
	while(us[t]){
		t++;
	}
	//cerr << t << ", " <<  H << endl;
	if(t==H){
		return g();
	}
	us[t]=true;
	int cnt=1;
	for(int s=t+1;s<H;s++){
		if(us[s])continue;
		us[s]=true;
		cnt++;
		ps.push_back(P(t,s));
		if(f()){
			//cerr << "f " << t << ", " << s << endl;
			return true;
		}
		ps.pop_back();
		us[s]=false;
	}
	if(cnt%2){
		ps.push_back(P(t,t));
		if(f()){
			//cerr << "f " << t << endl;
			return true;
		}
		ps.pop_back();
	}
	us[t]=false;
	return false;
}
bool g(){
	int t=0;
	while(vs[t]){
		t++;
	}
	if(t==W){
		return true;
	}
	vs[t]=true;
	int cnt=1;
	for(int s=t+1;s<W;s++){
		if(vs[s])continue;
		vs[s]=true;
		cnt++;
		bool ok=true;
		for(auto p:ps){
			if(S[p.first][s]!=S[p.second][t]||S[p.first][t]!=S[p.second][s]){
				ok=false;
				break;
			}
		}
		if(ok&&g()){
#if 0
			for(auto p:ps){
				cerr << S[p.first][s] << ", " << S[p.second][t] << ": ";
			}
			cerr << endl;
			cerr << "g " << t << ", " << s << endl;
#endif
			return true;
		}
		vs[s]=false;
	}
	if(cnt%2){
		bool ok=true;
		for(auto p:ps){
			if(S[p.first][t]!=S[p.second][t]){
				ok=false;
				break;
			}
		}
		if(ok&&g()){
			//cerr << "g " << t << endl;
			return true;
		}
	}
	vs[t]=false;
	return false;
}
int main() {
	cin >> H >> W;
	for(int i=0;i<H;i++){
		cin >> S[i];
	}
	if(f()){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}


	return 0;
}