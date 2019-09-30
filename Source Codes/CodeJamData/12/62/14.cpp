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

int N,K;
double p[1000010];
double prodl[1000010], prodr[1000010];
double suml[1000010], sumr[1000010];

void main2(void){
	int M,i,j;
	
	cin >> M >> K;
	
	N = 0;
	REP(i,M){
		string s;
		int a,b,c;
		cin >> s >> c;
		REP(j,s.length()) if(s[j] == '/') s[j] = ' ';
		istringstream ss(s);
		ss >> a >> b;
		double tmp = (double)a / b;
		REP(j,c){
			p[N] = tmp;
			N++;
		}
	}
	
	sort(p,p+N);
	reverse(p,p+N);
	
//	REP(i,N) cout << p[i] << ' ';
//	cout << endl;
	
	double ans = 0.0;
	
	prodl[0] = 1.0;
	REP(i,N) prodl[i+1] = prodl[i] * p[i];
	prodr[N] = 1.0;
	for(i=N-1;i>=0;i--) prodr[i] = prodr[i+1] * (1.0 - p[i]);
	suml[0] = 1.0;
	REP(i,N) suml[i+1] = suml[i] * (1.0 - p[i]) + prodl[i+1];
	sumr[N] = 1.0;
	for(i=N-1;i>=0;i--) sumr[i] = sumr[i+1] * p[i] + prodr[i];
	
	REP(i,K+1){
		double tmp = suml[i] * prodr[N-K+i] + prodl[i] * sumr[N-K+i] - prodl[i] * prodr[N-K+i];
	//	cout << i << ' ' << tmp << endl;
		ans = max(ans,tmp);
	}
	
	printf("%.12f\n", 1.0 - ans);
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
