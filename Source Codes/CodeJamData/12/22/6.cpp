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

#define INF (1<<29)

int H,X,Y;
int high[110][110],low[110][110];
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};

int dist[110][110];
bool used[110][110];
priority_queue <pair <int, pair <int, int> > > q;

void add(int x, int y, int d){
	if(d < dist[x][y]){
		dist[x][y] = d;
		q.push(make_pair(-d,make_pair(x,y)));
	}
}

void main2(void){
	int i,j;
	
	cin >> H >> X >> Y;
	REP(i,X) REP(j,Y) cin >> high[i][j];
	REP(i,X) REP(j,Y) cin >> low[i][j];
	
	REP(i,X) REP(j,Y) dist[i][j] = INF;
	REP(i,X) REP(j,Y) used[i][j] = false;
	add(0, 0, 0);
	
	while(!q.empty()){
		int d = -q.top().first, x = q.top().second.first, y = q.top().second.second;
		q.pop();
		if(used[x][y]) continue;
		used[x][y] = true;
		
		REP(i,4){
			int x2 = x + dx[i], y2 = y + dy[i];
			if(x2 < 0 || x2 >= X || y2 < 0 || y2 >= Y) continue;
			
			if(high[x2][y2] - low[x2][y2] < 50) continue;
			if(high[x2][y2] - low[x][y] < 50) continue;
			if(high[x][y] - low[x2][y2] < 50) continue;
			
			int d2 = d;
			int diff = high[x2][y2] - (H - d);
			if(diff < 50) d2 += 50 - diff;
			
			if(d2 == 0){
				add(x2, y2, d2);
			} else if(H - d2 >= low[x][y] + 20){
				add(x2, y2, d2+10);
			} else {
				add(x2, y2, d2+100);
			}
		}
	}
	
	double ans = dist[X-1][Y-1] / 10.0;
	printf("%.1f\n",ans);
}

int main(void){
	int T,t;
	cin >> T;
	REP(t,T){
		printf("Case #%d: ",t+1);
		main2();
	}
	return 0;
}
