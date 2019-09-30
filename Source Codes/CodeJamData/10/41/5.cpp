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

int a[2000][2000];
bool X[2000],Y[2000];

bool inside(int D, int x, int y){
	return (x+y >= -D && x+y <= D && x-y >= -D && x-y <= D && (x+y+11*D)%2 == 0);
}

void main2(void){
	int D,i,j,x,y;
	
	scanf("%d",&D); D--;
	for(i=-D;i<=D;i++) for(j=-D;j<=D;j++) if(inside(D,i,j)) scanf("%d",&a[1000+i][1000+j]);
	
	for(i=-2*D;i<=2*D;i++) X[1000+i] = Y[1000+i] = true;
	for(i=-D;i<=D;i++) for(j=-D;j<=D;j++) if(inside(D,i,j)){
		for(x=-2*D;x<=2*D;x++) if(inside(D,2*x-i,j) && a[1000+i][1000+j] != a[1000+2*x-i][1000+j]) X[1000+x] = false;
		for(y=-2*D;y<=2*D;y++) if(inside(D,i,2*y-j) && a[1000+i][1000+j] != a[1000+i][1000+2*y-j]) Y[1000+y] = false;
	}
	
	int small = (1<<29);
	for(x=-2*D;x<=2*D;x++) for(y=-2*D;y<=2*D;y++) if(X[1000+x] && Y[1000+y]) small = min(small, D + 1 + abs(x) + abs(y));
	int ans = small*small - (D+1)*(D+1);
//	cout << small << ' ' << D+1 << endl;
	gout << ans << endl;
}

int main(void){
	int number_of_test_cases,i;
	scanf("%d",&number_of_test_cases);
	REP(i,number_of_test_cases) main2();
	return 0;
}
