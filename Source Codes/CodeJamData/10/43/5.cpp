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
template <class T> inline string itos(T n) {return (n)<0?"-"+itos(-(n)):(n)<10?(string)("")+(char)('0'+(n)):itos((n)/10)+itos((n)%10);}

int case_number;
#define printg case_number++, printf("Case #%d: ",case_number), printf
#define gout case_number++, printf("Case #%d: ",case_number), cout

#define INF (1<<29)

int dx[]={1,-1,0,0,1,-1},dy[]={0,0,1,-1,-1,1};
int x[1000010],y[1000010];
bool used[1000010];
map <pair <int, int>, int> mp;
queue <int> q;

int bfs(int sx, int sy, int sid){
	int xmax=-INF,ymax=-INF,summin=INF,i,j;
	
	q.push(sx); q.push(sy); used[sid] = true;
	while(!q.empty()){
		int x2 = q.front(); q.pop(); int y2 = q.front(); q.pop();
		xmax = max(xmax,x2); ymax = max(ymax,y2); summin = min(summin,x2+y2);
		REP(i,6){
			int x3 = x2 + dx[i], y3 = y2 + dy[i];
			if(mp.find(make_pair(x3,y3)) != mp.end()){
				int id3 = mp[make_pair(x3,y3)];
				if(!used[id3]){
					q.push(x3); q.push(y3);
					used[id3] = true;
				}
			}
		}
	}
	
	int ans = xmax + ymax - summin + 1;
	return ans;
}

void main2(void){
	int N=0,R,x2,x3,y2,y3,i,j,k;
	
	mp.clear();
	scanf("%d",&R);
	REP(i,R){
		scanf("%d%d%d%d",&x2,&y2,&x3,&y3);
		for(j=x2;j<=x3;j++) for(k=y2;k<=y3;k++){
			pair <int, int> p = make_pair(j,k);
			if(mp.find(p) != mp.end()) continue;
			mp[p] = N;
			x[N] = j; y[N] = k; N++;
		}
	}
	
	int ans = 0;
	REP(i,N) used[i] = false;
	REP(i,N) if(!used[i]) ans = max(ans,bfs(x[i],y[i],i));
	
	printg("%d\n",ans);
}

int main(void){
	int number_of_test_cases,i;
	scanf("%d",&number_of_test_cases);
	REP(i,number_of_test_cases) main2();
	return 0;
}
