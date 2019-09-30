#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <utility>
#include <vector>
#include <iomanip>
#include <cstring>
#include <cassert>

using namespace std;

typedef double ld;

const ld eps = 1e-7;

int n;
char c[1<<7];
ld sp[1<<7];
ld pos[1<<7];
ld cross[1<<7][1<<7][2]; //[x][y][ty]
int encode[1<<7][1<<7]; //[x][y]
vector<pair<pair<ld,int>, pair<int,int> > > events;
vector<pair<pair<ld,int>, int> > ev_car[1<<7];
int point[1<<7];
int passing[1<<7];
int prev[1<<7];

int parent[1<<17];
int find(int x){
	if (parent[x] != x)
		parent[x] = find(parent[x]);
	return parent[x];
}
int merge(int x, int y){
	x = find(x); y = find(y);
	if (x > y) swap(x,y);
	parent[y] = x;
}

int main(){
	int t; cin >> t;
	for (int zz = 1; zz <= t; zz++){
		cin >> n;	
		for (int i = 0; i < n; i++){
			cin >> c[i] >> sp[i] >> pos[i];
		}
		events.clear();
		for (int i = 0; i < n; i++)
			ev_car[i].clear();
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++){
				if (abs(sp[i]-sp[j]) < 1e-7) continue;
				ld t1,t2;
				t1 = (5-pos[j]+pos[i])/(sp[j]-sp[i]);
				t2 = (-5-pos[j]+pos[i])/(sp[j]-sp[i]);
				if (t1 > t2){
					ld temp = t2; t2 = t1; t1 = temp;					
				}
				ev_car[i].push_back(make_pair(make_pair(t1,1),j));
				ev_car[i].push_back(make_pair(make_pair(t2,0),j));
				ev_car[j].push_back(make_pair(make_pair(t1,1),i));
				ev_car[j].push_back(make_pair(make_pair(t2,0),i));
				events.push_back(make_pair(make_pair(t1,1),make_pair(i,j)));
				events.push_back(make_pair(make_pair(t2,0),make_pair(i,j)));
				cross[i][j][1] = t1; cross[i][j][0] = t2;
				cross[j][i][1] = t1; cross[j][i][0] = t2;
			}
		//cout << "events.size() == " << events.size() << endl;
		for (int i = 0; i < n; i++){
			sort(ev_car[i].begin(),ev_car[i].end());
		}
		sort(events.begin(),events.end());
		memset(encode,-1,sizeof(encode));
		parent[0] = 0;//left
		parent[1] = 1;//right
		int cmp_cnt = 2;
		for (int i = 0; i < n; i++){
			//initial situation
			if (c[i] == 'L') {
				parent[2*(i+1)] = 0;
				parent[2*(i+1)+1] = 1;
			}
			else {
				parent[2*(i+1)] = 1;
				parent[2*(i+1)+1] = 0;
			}
			prev[i] = 2*(i+1);
			cmp_cnt+=2;
		}
		memset(point,0,sizeof(point));
		memset(passing,0,sizeof(passing));
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++){
				if (j == i) continue;
				if (abs(pos[i]-pos[j]) < 5-eps)
					passing[i]++;
			}
		/*for (int i = 0; i < n; i++)
			cout << passing[i] << " ";
		cout << ": passing" << endl;*/
		for (int i = 0; i < n; i++){
			while(point[i] < ev_car[i].size() && ev_car[i][point[i]].first.first < eps)
				point[i]++;
		}
		int i = 0;
		while(i < events.size() && (events[i].first.first < -eps || (events[i].first.first < eps && events[i].first.second == 0))) i++;
		//cout << "i = " << i << endl;
		ld curr = 0;
		for (; i < events.size(); i++){
			int x = events[i].second.first;
			int y = events[i].second.second;
			int ty = events[i].first.second;
			curr = events[i].first.first;
		//	cout << "curr = " << curr << ", x = " << x << ", y = " << y << ", ty = " << ty << endl;
			
			assert(passing[x] >= 0);
			assert(passing[y] >= 0);
			if (ty == 0){
				passing[x]--;
				passing[y]--;
			}
			else{
				encode[x][y] = cmp_cnt;
				parent[cmp_cnt] = cmp_cnt;
				parent[cmp_cnt+1] = cmp_cnt+1;
				cmp_cnt+=2;
				encode[y][x] = cmp_cnt;
				parent[cmp_cnt] = cmp_cnt;
				parent[cmp_cnt+1] = cmp_cnt+1;
				cmp_cnt+=2;
				
				int cx = encode[x][y], cy = encode[y][x];
				if (passing[x] > 0){
					merge(cx,prev[x]);
					merge(cx+1,prev[x]+1);
				//	cout << "trigx" << endl;
				}
				if (passing[y] > 0){
					merge(cy,prev[y]);
					merge(cy+1,prev[y]+1);
					//cout << "trigy" << endl;
				}
				prev[x] = cx;
				prev[y] = cy;
				passing[x]++; passing[y]++;
				merge(cx,cy+1); merge(cy,cx+1);
				//cout << "cx = " << cx << ", cy = " << cy << endl;
				bool okay = true;
				for (int i = 0; i < cmp_cnt; i+=2){
					if (find(i) == find(i+1)){
						okay = false;
						break;
					}
				}
				/*for (int i = 0; i < cmp_cnt; i++)
					cout << find(i) << " ";
				cout << ": find" << endl;
				cout << endl;*/
				if (!okay) break;
			}
		}
		if (i == events.size()){
			cout << "Case #" << zz << ": Possible" << endl;
		}
		else cout << "Case #" << zz << ": " << setprecision(10) << curr << endl;
	}

	return 0;
}
