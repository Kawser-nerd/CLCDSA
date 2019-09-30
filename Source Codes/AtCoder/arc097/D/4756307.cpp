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

using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int L=1e5+10;
vector<int> ps[L];
char c[L];

bool target[L];
bool f(int r,int p)
{
	bool ok=c[r]=='W';
	vector<int> nx;
	for(auto j:ps[r]){
		if(j!=p){
			if(f(j,r)){
				ok=true;
				nx.push_back(j);
			}
		}
		else if(p){
			nx.push_back(j);
		}
	}
	nx.swap(ps[r]);
	target[r]=ok;
	return ok;
}
P g(int r,int p)
{
	int d=0;
	bool odd=ps[r].size()%2;
	bool black=c[r]=='B';
	if(odd==black){
		d++;
	}
	P ret=P(d,r);
	for(int j:ps[r]){
		if(j!=p){
			auto q=g(j,r);
			q.first+=d;
			ret=max(ret,q);
		}
	}
	return ret;
}
int main() {
	int N;
	cin >> N;
	for(int i=0;i<N-1;i++){
		int a,b;
		cin >> a >> b;
		ps[a].push_back(b);
		ps[b].push_back(a);
	}
	cin >> (c+1);
	int r=0;
	for(int i=1;i<=N;i++){
		if(c[i]=='W'){
			r=i;
			break;
		}
	}
	if(r==0){
		cout << 0 << endl;
		return 0;
	}
	f(r,0);
	int d=0;
	int a=0;
	for(int i=1;i<=N;i++){
		if(target[i]){
			d++;
			bool odd=ps[i].size()%2;
			bool black=c[i]=='B';
			if(odd==black)
			{
				a++;
			}
		}
	}
	if(d==1){
		cout << 1 << endl;
		return 0;
	}
	int ret=2*(d-1)+a;
	//cerr << d << ", " << a << endl;
	//cerr << ret << endl;
	auto p=g(r,0);
	//cerr << p.first << "," << p.second << endl;
	p=g(p.second,0);
	//cerr << p.first << "," << p.second << endl;
	ret-=2*p.first;
	cout << ret << endl;

	return 0;
}