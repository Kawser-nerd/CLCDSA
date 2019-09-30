#include <iostream>
#include <iomanip>

using namespace std;

typedef long long ll;

ll p[1<<10];
ll v[1<<10];
int c;
ll d;

int main(){
	int t; cin >> t;
	for (int zzz = 1; zzz <= t; zzz++){
		cin >> c >> d; d *= 2;
		ll maxv = 0; ll totv = 0;
		for (int i = 0; i < c; i++){
			cin >> p[i] >> v[i];
			p[i] *= 2;
			if (maxv < v[i]) maxv = v[i];
			totv += v[i];
		}
		ll mi = (d/2) * (maxv-1);
		ll ma = totv * d;
		ll high = ma, low = mi;
		while(high != low){
			ll curr = (high + low) / 2;
			//cout << "low = " << low << ", high = " << high << ", curr = " << curr << endl;
			bool okay = true;
			ll pos = p[0]-curr-d-1;
			for (int i = 0;	i < c; i++){
				ll left = p[i] - curr;
				if (left < pos + d){
					left = pos + d;
				}
				pos = left + (v[i]-1) * d;
				if (pos - p[i] > curr){
					okay = false;
					//cout << "break on " << i << endl;
					break;
				}
			}
			if (okay) high = curr;
			else low = curr+1;
		}
		cout << "Case #" << zzz << ": " << setprecision(15) << (high / 2.0) << endl;
		//cout << high << endl;
	}
	
	
	return 0;
}
