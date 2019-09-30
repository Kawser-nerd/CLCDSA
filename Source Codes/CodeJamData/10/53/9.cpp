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

int x[210];

void main2(void){
	int N=0,C,i,j;
	
	cin >> C;
	REP(i,C){
		int P,V;
		cin >> P >> V;
		REP(j,V) x[N+j] = P;
		N += V;
	}
	
	int ans = 0;
	while(1){
		sort(x,x+N);
		bool found = false;
		REP(i,N-1) if(x[i] == x[i+1]) {found = true; break;}
		if(!found) break;
		x[i]--; x[i+1]++; ans++;
	}
	
	gout << ans << endl;
}

int main(void){
	int number_of_test_cases,i;
	scanf("%d",&number_of_test_cases);
	REP(i,number_of_test_cases) main2();
	return 0;
}
