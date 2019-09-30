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
int t[1010],p[1010];
bool used[1010];

void main2(void){
	int iter,i;
	
	cin >> N;
	REP(i,N) cin >> t[i];
	REP(i,N) cin >> p[i];
	
	REP(i,N) used[i] = false;
	REP(iter,N){
		int x = -1;
		REP(i,N) if(!used[i]){
			if(x == -1){
				x = i;
			} else if(t[i] * p[x] < t[x] * p[i]){
				x = i;
			}
		}
		cout << ' ' << x;
		used[x] = true;
	}
	
	cout << endl;
}

//////////////////////////////// multiple testcases ////////////////////////////////

int main(void){
	int T,t;
	scanf("%d",&T);
	REP(t,T){
		printf("Case #%d:",t+1);
		main2();
	}
	return 0;
}
