#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

int a[110];

void main2(void){
	int A,N,i,j;
	
	cin >> A >> N;
	REP(i,N) cin >> a[i];
	sort(a, a+N);
	
	int ans = N;
	for(i=1;i<=N;i++){
		int tmp = N-i;
		int x = A;
		REP(j,i){
			while(x <= a[j]){
				if(x == 1){
					tmp = N;
					break;
				}
				x = 2*x-1;
				tmp++;
			}
			x += a[j];
		}
		ans = min(ans, tmp);
	}
	
	cout << ans << endl;
}

int main(void){
	int TC,tc;
	cin >> TC;
	REP(tc,TC){
		printf("Case #%d: ", tc+1);
		main2();
	}
	return 0;
}
