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

int N,sum;
int s[210];

bool check(int id, double p){
	int i;
	double tmp = p;
	
	REP(i,N) if(i != id){
		double diff = s[id] + p * sum - s[i];
		if(diff > 0.0) tmp += diff / sum;
	}
	
	return (tmp > 1.0);
}

void main2(void){
	int i,j;
	
	cin >> N;
	REP(i,N) cin >> s[i];
	
	sum = 0;
	REP(i,N) sum += s[i];
	
	REP(i,N){
		double low = 0.0, high = 1.0;
		REP(j,50){
			double mid = (high + low) / 2.0;
			if(check(i, mid)) high = mid; else low = mid;
		}
		printf(" %.9f",high*100.0);
	}
	
	printf("\n");
}

int main(void){
	int T,t;
	cin >> T;
	REP(t,T){
		printf("Case #%d:",t+1);
		main2();
	}
	return 0;
}
