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
ll F,X[40];

int A,B;
pair <int, ll> a[1300000],b[1300000];

void dfs1(int L, int pos, int sum, ll x){
	if(L == 0){
		a[A] = make_pair(sum,x); A++;
	} else {
		for(int i=-1;i<=1;i++) if(sum+i < 0) dfs1(L-1,pos+1,sum+i,x+i*X[pos]);
	}
}

void dfs2(int R, int pos, int sum, ll x){
	if(R == 0){
		b[B] = make_pair(sum,x); B++;
	} else {
		for(int i=-1;i<=1;i++) if(sum+i > 0) dfs2(R-1,pos-1,sum+i,x+i*X[pos]);
	}
}

void main2(void){
	int N,i,j;
	
	cin >> N;
	REP(i,N) cin >> X[i]; sort(X,X+N);
	cin >> F; F /= 2;
	
	int L = N/2, R = N-L;
	A = B = 0;
	dfs1(L,0,0,0); dfs2(R,N-1,0,0);
	sort(a,a+A); sort(b,b+B);
	
	ll ans = -1;
	j = B-1;
	REP(i,A){
		while(j >= 0 && (a[i].first + b[j].first > 0 || (a[i].first + b[j].first == 0 && a[i].second + b[j].second > F))) j--;
		if(j >= 0 && a[i].first + b[j].first == 0 && a[i].second + b[j].second <= F) ans = max(ans, a[i].second + b[j].second);
	}
	
	if(ans == -1) gout << "NO SOLUTION" << endl;
	else gout << ans * 2 << endl;
}

int main(void){
	int number_of_test_cases,i;
	scanf("%d",&number_of_test_cases);
	REP(i,number_of_test_cases) main2();
	return 0;
}
