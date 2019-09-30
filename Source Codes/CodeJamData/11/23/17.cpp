#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int u[1<<12];
int v[1<<12];

int best;

vector<int> edges[1<<12];
int colors[1<<12];

void dfs_1(int prev, int curr){
	bool first = true;
	int x = curr;
	int y = prev;
	int cnt = 1;
	vector<pair<int,int> > st;
	//cout << "entering " << prev << " " << curr << endl;
	//cout << curr << " ";
	while(first || x != prev){
		first = false;
		vector<int>::iterator itr = upper_bound(edges[x].begin(),edges[x].end(),(y-x+n)%n);
		//if (itr == edges[x].end()) itr = edges[x].begin();
		y = ((*itr) + x)%n;
		if (((y-x+n)%n) != n-1){
			//dfs_1(y,x);	
			st.push_back(make_pair(y,x));
		}
		cnt++;
		swap(x,y);
		//cout << x << " ";
	}
	//cout << endl;
	if (best > cnt) best = cnt;
	for (int i = 0; i < st.size(); i++)
		dfs_1(st[i].first,st[i].second);
}

void dfs_2(int prev, int curr){ // colors of prev, curr already assigned
	bool first = true;
	int x = curr;
	int y = prev;
	int cnt = 1;
	vector<pair<int,int> > st;
	//cout << "entering " << prev << " " << curr << endl;
	//cout << curr << " ";
	int col_cnt = 2;
	while(first || x != prev){
		if (x != curr){
			colors[x] = (colors[y]+1)%best;
			if (col_cnt < best){
				while(colors[x] == colors[prev] || colors[x] == colors[curr])
					colors[x] = (colors[x]+1)%best;
			}
		}
		first = false;
		vector<int>::iterator itr = upper_bound(edges[x].begin(),edges[x].end(),(y-x+n)%n);
		//if (itr == edges[x].end()) itr = edges[x].begin();
		y = ((*itr) + x)%n;
		if (((y-x+n)%n) != n-1){
			//dfs_1(y,x);	
			st.push_back(make_pair(y,x));
		}
		cnt++;
		swap(x,y);
		col_cnt++;
		//cout << x << " ";
	}
	//cout << endl;
	if (colors[y] == colors[prev]){
		colors[y] = (colors[y]+1)%best;
	}

	for (int i = 0; i < st.size(); i++)
		dfs_2(st[i].first,st[i].second);
}

int main(){
	int t; cin >> t;
	for (int zzz = 1; zzz <= t; zzz++){
		cin >> n >> m;
		for (int i = 0; i < n; i++){
			edges[i].clear();	
			edges[i].push_back(1);
			edges[i].push_back(n-1);
		}
		for (int i = 0; i < m; i++){
			cin >> u[i]; u[i]--;
		}
		for (int j = 0; j < m; j++){
			cin >> v[j]; v[j]--;
		}
		for (int i = 0; i < m; i++){
			int x = u[i], y = v[i];
			edges[x].push_back((y - x + n) % n);
			edges[y].push_back((x - y + n) % n);	
		}
		for (int i = 0; i < n; i++){
			sort(edges[i].begin(),edges[i].end());
			/*for (int j = 0; j < edges[i].size(); j++){
				edges[i][j] = (edges[i][j] + i) % n;	
			}*/
		}
		/*for (int i = 0; i < n; i++){
			cout << "i = " << i << ": ";
			for (int j = 0; j < edges[i].size(); j++)
				cout << edges[i][j] << " ";
			cout << endl;	
		}*/
		best = n;
		dfs_1(1,0);
		cout << "Case #" << zzz << ": " << best << endl;
		memset(colors,-1,sizeof(colors));
		colors[0] = 0;
		colors[1] = 1;
		dfs_2(1,0);
		for (int i = 0; i < n; i++)
			cout << (colors[i]+1) << " ";
		cout << endl;
	}
	
	return 0;
}
