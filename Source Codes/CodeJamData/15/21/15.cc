
#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long i64;
#define fu(i,m,n) for(int i=m; i<n; i++)
#define fr(i,m,n) for(typeof(m) i=m; i!=n; i++)
#define fa(i,c) fr(i,(c).begin(),(c).end())

long pt[20];

long time_to(long N) {
    if(N==0) return 0;
    long D=0;
    while(pt[D]*10<=N) D++;
    //cout << N << " " << pt[D] << endl;
    long ret = time_to(pt[D]-1), ret1=0, ret2=0;
    fu(i,0,(D/2+1)) ret1 += ((N/pt[i])%10)*pt[i];
    fu(i,0,(D+1)/2) ret2 += (N/pt[D-i])%10*pt[i];
    if(ret1) {
        return ret + ret1 + ret2 + (ret2>1);
    } else {
        //cout << "Here!" << endl;
        return time_to(N-1)+1;
    }
}

int main(void) {

    pt[0]=1;
    fu(i,1,20) pt[i]=pt[i-1]*10;

	int T;
	cin >> T;
	for(int ts=1; ts<=T; ts++) {
		cout << "Case #" << ts << ": ";
        long N;
        cin >> N;
        cout << time_to(N) << endl;
	}
}
