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
int a[20],b[20];
bool visited[20][(1<<10)];

void main2(void){
	int i,mask;
	
	cin >> N;
	REP(i,N-1) cin >> a[i] >> b[i];
	REP(i,N-1) {a[i]--; b[i]--;}
	
	REP(i,N) REP(mask,(1<<N)) visited[i][mask] = false;
	
	int x = 0;
	mask = 0;
	int step = 0;
	
	while(1){
		if(x == N-1){
			cout << step << endl;
			break;
		}
		step++;
		
		if(visited[x][mask]){
			cout << "Infinity" << endl;
			break;
		}
		
		visited[x][mask] = true;
		mask ^= (1<<x);
		if(mask&(1<<x)) x = a[x]; else x = b[x];
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
