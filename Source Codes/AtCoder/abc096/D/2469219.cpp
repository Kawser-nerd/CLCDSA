#include <iostream>
#include <math.h>
#define REP(i,n) for(int i=0;i<n;i++)
using namespace std;

int main() {
	int N;
	cin >> N;
	int ans[N];
	ans[0]=2;

	int now=1;
	for (int i=11; i<55555; i+=10) {
		bool prime=true;
		for (int j=2; j<=sqrt(i); j++) {
			if(i%j == 0){
				prime=false;
				break;
			}
		}
		if(prime) {
			ans[now]=i;
			now++;
		}
		if (now == N) {
      REP(i,N)
				cout << ans[i] << " ";
      cout << endl;
			return 0;
		}
	}
	return 0;
}