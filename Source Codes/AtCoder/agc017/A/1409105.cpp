#include <iostream>
using namespace std;

int main() {
	int n,p;
	long long stat[52][2];
	memset(stat,0,sizeof(stat));
	stat[0][0]=1;
	cin>>n>>p;
	for (int i=1;i<=n;i++) {
		int tt; cin>>tt;
		if (tt%2 == 1) {
			stat[i][0] = stat[i-1][0] + stat[i-1][1];
			stat[i][1] = stat[i-1][1] + stat[i-1][0];
		}else {
			stat[i][1] = stat[i-1][1]*2;
			stat[i][0] = stat[i-1][0]*2;
		}
	}
	cout<<stat[n][p]<<endl;
	return 0;
}