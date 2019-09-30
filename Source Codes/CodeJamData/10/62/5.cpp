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

int d[1010][1010];

void main2(void){
	int N,i,j,x,y;
	
	cin >> N;
	REP(i,N) REP(j,N) d[i][j] = 0;
	REP(i,3) REP(j,3) if(i != j) d[i][j] = 1;
	for(i=3;i<N;i++){
		cin >> x >> y; x--; y--;
		d[i][x] = d[i][y] = d[x][i] = d[y][i] = 1;
	}
	
	int ans = 3;
	for(i=N-1;i>=3;i--){
		x = y = -1;
		REP(j,i) if(d[j][i] != 0){
			if(x == -1) x = j;
			else y = j;
		}
		ans = max(ans,d[x][y]+d[i][x]+d[i][y]);
		d[x][y] = d[y][x] = max(d[x][y],d[i][x]+d[i][y]);
	}
	ans = max(ans,d[0][1]+d[1][2]+d[2][0]);
	
	gout << ans << endl;
}

int main(void){
	int number_of_test_cases,i;
	scanf("%d",&number_of_test_cases);
	REP(i,number_of_test_cases) main2();
	return 0;
}
