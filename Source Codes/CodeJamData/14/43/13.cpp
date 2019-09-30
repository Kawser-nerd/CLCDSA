#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int w,h,b;
struct building{
	int x0, y0;
	int x1, y1;
};

building dat[1024];

int dist[1024][1024];

int sd[1024], v[1024];

int calcDist(int x, int y, building &b) {
	if (x <= b.x0 && y-x >= b.y0 - b.x0 && y+x <= b.x0 + b.y1){
		return b.x0 - x - 1;
	}
	if (x >= b.x1 && y-x <= b.y1 - b.x1 && y+x >= b.x1 + b.y0) {
		return x - b.x1 - 1;
	}
	if (y >= b.y1) return y - b.y1 - 1;
	return b.y0 - y - 1;
}

int calcDist(building &a, building &b) {
	int ret = calcDist(a.x0, a.y0, b);
	ret = min(ret,calcDist(a.x0, a.y1, b));
	ret = min(ret,calcDist(a.x1, a.y0, b));
	ret = min(ret,calcDist(a.x1, a.y1, b));

	ret = min(ret,calcDist(b.x0, b.y0, a));
	ret = min(ret,calcDist(b.x0, b.y1, a));
	ret = min(ret,calcDist(b.x1, b.y0, a));
	ret = min(ret,calcDist(b.x1, b.y1, a));
	return max(0,ret);
}

int main(){
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase++) {
		scanf("%d%d%d",&w,&h,&b);
		for(int i = 0; i < b; i++) {
			scanf("%d%d%d%d",&dat[i].x0,&dat[i].y0,&dat[i].x1,&dat[i].y1);
		}
		dat[b].x0 = -1;
		dat[b].x1 = -1;
		dat[b].y0 = 0;
		dat[b].y1 = h;
		b++;
		dat[b].x0 = w;
		dat[b].x1 = w;
		dat[b].y0 = 0;
		dat[b].y1 = h;
		b++;
		for(int i = 0; i < b; i++) {
			for(int j = i + 1; j < b; j++) {
				dist[j][i] = dist[i][j] = calcDist(dat[i],dat[j]);
			}
		}
		
		for(int i = 0; i < b; i++) sd[i] = INT_MAX;
		memset(v,0,sizeof(v));
		sd[b-2] = 0;
		for(int i = 0; i < b; i++) {
			int minv = INT_MAX, vmin = -1;
			for(int j = 0; j < b; j++) {
				if(v[j])continue;
				if (minv > sd[j]){
					minv = sd[j];
					vmin = j;
				}
			}
			if (vmin == -1) break;
			v[vmin] = 1;
			for(int j = 0; j < b; j++) {
				if (sd[j] > minv + dist[vmin][j]) {
					sd[j] = minv + dist[vmin][j];
				}
			}
		}
		printf("Case #%d: %d\n", testcase, sd[b-1]);
	}
	return 0;
}
