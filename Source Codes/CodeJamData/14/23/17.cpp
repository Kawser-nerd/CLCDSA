/* 
 * in the name of god 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */ 

#include <iostream> 
#include <fstream> 
#include <sstream> 
#include <cstdio> 
#include <cstring> 
#include <cstdlib> 
#include <cmath> 
#include <ctime> 
#include <algorithm> 
#include <vector> 
#include <queue> 
#include <deque> 
#include <stack> 
#include <set> 
#include <map> 
#include <complex> 
#include <bitset> 
#include <iomanip> 
#include <utility> 

using namespace std; 

typedef long long LL; 
typedef pair<int,int> pii; 
typedef complex<double> point; 

bool active[100],mark[100],vis[100];
int n,e;
int val[100],par[100],hei[100];
vector <int> adj[100];

bool go (int v, int p, int last){
	for (int i = last; i != p; i = par[i])
		active[i] = false;
	queue <int> Q;
	vector <bool> vis(n, false);
	for (int i=0; i<n; i++) if (mark[i] && active[i]){
		Q.push(i);
		vis[i] = true; 
	}
	while (!Q.empty()){
		int front = Q.front(); Q.pop();
		for (int i=0; i<(int)adj[front].size(); i++){
			int tmp = adj[front][i];
			if ((!vis[tmp]) && ((!mark[tmp]))){
				Q.push(tmp);
				vis[tmp] = true;
			}
		}
	}
	for (int i=0; i<n; i++) if (mark[i]==false && vis[i]==false){
		for (int j=last; j!=p; j=par[j])
			active[j] = true;
		return false;
	}
	for (int j=last; j!=p; j=par[j])
		active[j] = true;
	return true;
}

inline void main2(){
	cin >> n >> e;
	for (int i=0; i<n; i++)
		adj[i].clear();
	vector < pair<int,int> > Q;
	for (int i=0; i<n; i++){
		cin >> val[i];
		Q.push_back(pair<int,int>(val[i], i));
	}
	for (int j=0; j<e; j++){
		int e1,e2; cin >> e1 >> e2;
		e1--; e2--;
		adj[e1].push_back(e2);
		adj[e2].push_back(e1);
	}
	memset(mark, 0, sizeof mark);
	memset(active, 0, sizeof active);
	sort(Q.begin(), Q.end());
	mark[Q[0].second] = true;
	active[Q[0].second] = true;
	cout << Q[0].first;
	int last = Q[0].second;
	for (int rep = 1; rep < n; rep++){
		for (int j=0; j<n; j++) if (!mark[Q[j].second]){
			memset(vis, false, sizeof vis);
			int temp = last;
			int C = 0;
			while (temp != Q[0].second){
				vis[temp] = true;
				hei[temp] = C++;
				temp = par[temp];
			}
			hei[Q[0].second] = C++;
			vis[Q[0].second] = true;
			int pos = -1;
			for (int k=0; k<(int)adj[Q[j].second].size(); k++){
				int B = adj[Q[j].second][k];
				if (vis[B]){
					if (go(Q[j].second, B, last)){
						if ((pos==-1) || (hei[B] < hei[pos]))
							pos = B;
					}
				}
			}
			if (pos != -1){
				cout << Q[j].first;
				mark[Q[j].second] = active[Q[j].second] = true;
				par[Q[j].second] = pos;
				for (int k=last; k != pos; k = par[k])
					active[k] = false;
				last = Q[j].second;
				break;
			}
		}
	}
	cout << endl;
}

int main(){
	int tt; cin >> tt;	
	for (int o=1; o<=tt; o++){
		cout << "Case #" << o << ": ";
		main2();
	}
	return 0;
}
