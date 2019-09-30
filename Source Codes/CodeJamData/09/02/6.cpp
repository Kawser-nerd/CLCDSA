#include <iostream>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > words;
#define fu(i,m,n) for(int i=m; i<n; i++)

int sinks[200][200], heights[200][200];
int dr[]={-1,0,0,1}, dc[]={0,-1,1,0};

int nsink=0;

int doit(int h, int w) {
	int& ret=sinks[h][w];
	if(ret>=0) return ret;
	int best=heights[h][w];
	int wh=-1;
	fu(d,0,4) {
		int h2=h+dr[d];
		int w2=w+dc[d];
		if(heights[h2][w2]<best) {
			best=heights[h2][w2];
			wh=d;
		}
	}
	if(wh==-1) return ret=(nsink++);
	int h2=h+dr[wh];
	int w2=w+dc[wh];
	return ret=doit(h2,w2);
}

int main(void) {
	int T;
	cin >> T;
	fu(t,0,T) {
		int H,W;
		nsink=0;
		cin >> H >> W;
		memset(sinks,-1,sizeof(sinks));
		fu(h,0,H+2) fu(w,0,W+2) heights[h][w]=1000000;
		fu(h,0,H) fu(w,0,W) cin >> heights[h+1][w+1];
		fu(h,1,H+1) fu(w,1,W+1) {
			sinks[h][w]=doit(h,w);
		}
		string ma(26,0);
		char c='a';
		fu(h,1,H+1) fu(w,1,W+1) if(ma[sinks[h][w]]==0)
			ma[sinks[h][w]]=(c++);
		cout << "Case #" << t+1 << ":" << endl;
		fu(h,1,H+1) {
			fu(w,1,W+1) {
				if(w>1) cout << " ";
				cout << ma[sinks[h][w]];
			}
			cout << endl;
		}
	}
}
