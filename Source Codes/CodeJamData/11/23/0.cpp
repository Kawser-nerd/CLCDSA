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

int N;
vector <pair <int, pair <int, int> > > edge;
vector <vector <int> > poly;
bool exist[2010];
int color[2010];

void func(int a, int b){
	int i;
	
	if(!exist[a] || !exist[b]) return;
	
	if(a > b) b += N;
	
	int cnt = 0;
	for(i=a+1;i<b;i++) if(exist[i%N]) cnt++;
	if(cnt == 0) return;
	
	vector <int> v;
	v.push_back(a); v.push_back(b%N);
	for(i=b-1;i>a;i--) if(exist[i%N]){
		v.push_back(i%N);
		exist[i%N] = false;
	}
	
	poly.push_back(v);
}

int U[2010],V[2010];

void main2(void){
	int M,a,b,i,j,p;
	
	edge.clear(); poly.clear();
	
	cin >> N >> M;
	REP(i,M) cin >> U[i];
	REP(i,M) cin >> V[i];
	
	REP(i,M){
		a = U[i] - 1; b = V[i] - 1;
		int d = (b-a+N) % N;
		edge.push_back(make_pair(d,make_pair(a,b)));
		d = (a-b+N) % N;
		edge.push_back(make_pair(d,make_pair(b,a)));
	}
	
	sort(edge.begin(),edge.end());
	REP(i,N) exist[i] = true;
	REP(i,edge.size()) func(edge[i].second.first,edge[i].second.second);
	reverse(poly.begin(),poly.end());
	
	int C = (1<<29);
	REP(i,poly.size()) C = min(C, (int)(poly[i].size()));
	cout << C << endl;
	
	REP(i,N) color[i] = -1;
	
	REP(p,poly.size()){
		vector <int> v = poly[p];
		
		if(p == 0){
			color[v[0]] = 0; color[v[1]] = 1;
		}
		
		i = 2;
		REP(j,C) if(j != color[v[0]] && j != color[v[1]]){
			color[v[i]] = j; i++;
		}
		
		for(i=C;i<v.size();i++){
			j = 0;
			while(j == color[v[i-1]] || (i == v.size()-1 && j == color[v[0]])) j++;
			color[v[i]] = j;
		}
	}
	
	REP(i,N){
		cout << color[i] + 1;
		if(i == N-1) cout << endl; else cout << ' ';
	}
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
