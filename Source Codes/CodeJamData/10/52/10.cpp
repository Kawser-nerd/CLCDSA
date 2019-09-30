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

typedef long long ll;
#define INF (1ll<<60)

priority_queue <pair <ll, int> > q; // dist, vertex
ll dist[100010];
bool used[100010];

vector <int> c;

void main2(void){
	int N,i,tmp;
	
	ll L;
	cin >> L >> N;
	c.clear();
	REP(i,N) {cin >> tmp; c.push_back(tmp);}
	sort(c.begin(),c.end());
	int M = c[N-1];
	
	REP(i,M) dist[i] = INF;
	REP(i,M) used[i] = false;
	
	dist[0] = 0; q.push(make_pair(0,0));
	while(!q.empty()){
		ll d = -q.top().first; int x = q.top().second; q.pop();
		if(used[x]) continue; used[x] = true;
		REP(i,N-1){
			int y = (x + c[i]) % M;
			ll d2 = d + (M - c[i]);
			if(d2 < dist[y]){
				dist[y] = d2;
				q.push(make_pair(-d2,y));
			}
		}
	}
	
	ll D = dist[(int)(L%M)];
	if(D == INF) gout << "IMPOSSIBLE" << endl;
	else gout << (L + D) / M << endl;
}

int main(void){
	int number_of_test_cases,i;
	scanf("%d",&number_of_test_cases);
	REP(i,number_of_test_cases) main2();
	return 0;
}
