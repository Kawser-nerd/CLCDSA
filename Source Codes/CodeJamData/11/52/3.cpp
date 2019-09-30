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

int a[10010];
vector <int> vp,vm;

void main2(void){
	int N,i,j,x;
	
	REP(i,10010) a[i] = 0;
	
	cin >> N;
	REP(i,N){
		cin >> x;
		a[x]++; a[x+1]--;
	}
	
	if(N == 0){
		cout << 0 << endl;
		return;
	}
	
	vp.clear(); vm.clear();
	REP(i,10010) if(a[i] != 0){
		if(a[i] > 0) REP(j,a[i]) vp.push_back(i);
		if(a[i] < 0) REP(j,-a[i]) vm.push_back(i);
	}
	
	sort(vp.begin(),vp.end());
	sort(vm.begin(),vm.end());
	
	int ans = INF;
	REP(i,vp.size()) ans = min(ans,vm[i]-vp[i]);
	cout << ans << endl;
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
