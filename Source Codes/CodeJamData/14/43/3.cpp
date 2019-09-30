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
// #include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

typedef long long ll;
#define INF (1ll<<60)

int X,Y,B;
int N;
int x0[1010],y0[1010],x1[1010],y1[1010];
ll graph[1010][1010];
ll dist[1010];
bool used[1010];

struct point {int x,y;};
point A[4];
point C[4];

int get_dist(point &O, point &P, point &Q){
	int x1 = P.x - O.x;
	int y1 = P.y - O.y;
	int x2 = Q.x - O.x;
	int y2 = Q.y - O.y;
	
	if(x1 == x2){
		swap(x1, y1);
		swap(x2, y2);
	}
	
	int ans = min(max(abs(x1), abs(y1)), max(abs(x2), abs(y2)));
	if((x1 <= 0 && x2 >= 0) || (x1 >= 0 && x2 <= 0)) ans = min(ans, abs(y1));
	
	return ans;
}

int get_dist(int p, int q){
	int i,j;
	
		A[0].x = A[3].x = x0[p];
		A[1].x = A[2].x = x1[p];
		A[0].y = A[1].y = y0[p];
		A[2].y = A[3].y = y1[p];
		
		C[0].x = C[3].x = x0[q];
		C[1].x = C[2].x = x1[q];
		C[0].y = C[1].y = y0[q];
		C[2].y = C[3].y = y1[q];
	
	int ans = (1<<29);
	
	REP(i,4) REP(j,4){
		ans = min(ans, get_dist(A[i], C[j], C[(j+1)%4]));
		ans = min(ans, get_dist(C[i], A[j], A[(j+1)%4]));
	}
	
	return ans;
}

void add_edge(int s, int t, ll d){
	graph[s][t] = d;
}

void main2(void){
	int i,j;
	
	cin >> X >> Y >> B;
	N = B + 2;
	REP(i,B){
		cin >> x0[i] >> y0[i] >> x1[i] >> y1[i];
		x1[i]++; y1[i]++;
	}
	
	REP(i,N) REP(j,N) graph[i][j] = INF;
	add_edge(B, B+1, X);
	REP(i,B){
		add_edge(B, i, x0[i]);
		add_edge(i, B+1, X - x1[i]);
	}
	REP(i,B) REP(j,B) if(i != j){
		ll tmp = get_dist(i, j);
		add_edge(i, j, tmp);
	}
	
	REP(i,N) dist[i] = INF;
	dist[B] = 0;
	REP(i,N) used[i] = false;
	
	while(1){
		int next = -1;
		REP(i,N) if(!used[i] && (next == -1 || dist[i] < dist[next])) next = i;
		if(next == -1) break;
		used[next] = true;
		REP(i,N) dist[i] = min(dist[i], dist[next] + graph[next][i]);
	}
	
	cout << dist[B+1] << endl;
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
