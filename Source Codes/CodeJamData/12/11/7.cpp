#include <iostream>
#include <iomanip>

using namespace std;

typedef double ld;

int a,b;
ld arr[1<<19];

int main(){
	int t; cin >> t;
	for (int zz = 1; zz <= t; zz++){
		cin >> a >> b;
		for (int i = 0; i < a; i++)
			cin >> arr[i];
		ld best = b+2;
		ld prob = b+1;
		for (int i = 0; i < a; i++){
			prob *= arr[i];
			ld ans = (b+1-prob) + (b-a+2*(a-i)-1);
			if (best > ans) best = ans;
			//cout << "i = " << i << ", ans = " << ans << endl;
		}
		cout << "Case #" << zz << ": " << setprecision(10) << best << endl;
	}
	
	return 0;
}
