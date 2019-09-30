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

#define INF 1.0E+15

int N;
double x[1000010];

bool func(double T, double D){
	int i;
	
	double tmp = -INF;
	REP(i,N){
		double next = max(tmp + D, x[i] - T);
		if(next > x[i] + T) return false;
		tmp = next;
	}
	
	return true;
}

void main2(void){
	int K,P,V,D,i,j;
	
	N = 0;
	
	scanf("%d%d",&K,&D);
	REP(i,K){
		scanf("%d%d",&P,&V);
		REP(j,V) x[N+j] = P;
		N += V;
	}
	
	double low = 0.0, high = INF;
	REP(i,100){
		double mid = (high + low) / 2.0;
		if(func(mid,D)) high = mid; else low = mid;
	}
	
	printf("%.9f\n",high);
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
