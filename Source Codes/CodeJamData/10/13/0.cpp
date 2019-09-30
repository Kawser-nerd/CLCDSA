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

typedef long long ll;

int case_number;
#define printg case_number++, printf("Case #%d: ",case_number), printf
#define gout case_number++, printf("Case #%d: ",case_number), cout

double golden = (sqrt(5.0) + 1.0) / 2.0;

ll main2(int A1, int A2, int B1, int B2){ // A * golden < B
	ll ans = 0;
	for(int A=A1;A<=A2;A++){
		int x = (int)(A * golden) + 1;
		x = max(x,B1);
		if(x <= B2) ans += B2 - x + 1;
	}
	return ans;
}

// bool win[110][110],win2[110][110];

int main(void){
	int number_of_test_cases,i;
	scanf("%d",&number_of_test_cases);
	REP(i,number_of_test_cases){
		int A1,A2,B1,B2;
		scanf("%d%d%d%d",&A1,&A2,&B1,&B2);
		ll ans = main2(A1,A2,B1,B2) + main2(B1,B2,A1,A2);
		gout << ans << endl;
	}
/*	
	int j,k;
	REP(i,110) REP(j,110) if(i > 0 && j > 0){
		for(k=j-i;k>0;k-=i) if(!win[i][k]) win[i][j] = true;
		for(k=i-j;k>0;k-=j) if(!win[k][j]) win[i][j] = true;
	}
	
	double golden = (sqrt(5.0) + 1.0) / 2.0;
	REP(i,110) REP(j,110) if(i > 0 && j > 0 && max(i,j) > min(i,j) * golden) win2[i][j] = true;
	REP(i,110) REP(j,110) if(win[i][j] != win2[i][j]) cout << "A" << endl;
*/	
	return 0;
}
