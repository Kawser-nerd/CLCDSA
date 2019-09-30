#include <iostream>

using namespace std;

int n;
int a[1<<12];
int b[1<<12];
int cnt[1<<12];


int main(){
	int t; cin >> t;
	for (int zz = 1; zz <= t; zz++){
		cin >> n;	
		for (int i = 0; i < n; i++){
			cin >> a[i] >> b[i];
			cnt[i] = 2;
		}
		int stars = 0;
		int moves = 0;
		while (stars < 2*n){
			bool ok = false;
			for (int i = 0; i < n; i++){
				if (cnt[i] && b[i] <= stars){
					moves++;
					stars += cnt[i];
					cnt[i] = 0;
					ok = true;
				}
			}
			if (ok) continue;
			int nb = -1;
			int ni;
			for (int i = 0; i < n; i++){
				if (cnt[i] == 2 && a[i] <= stars && nb < b[i] ){
					nb = b[i];
					ni = i;
				}
			}
			if (nb == -1) break;
			moves++;
			stars++;
			cnt[ni]--;
		}
		if (stars < 2*n) cout << "Case #" << zz << ": Too Bad" << endl; 
		else cout << "Case #" << zz << ": " << moves << endl;
	}

	return 0;
}
