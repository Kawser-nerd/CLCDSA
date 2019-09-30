#include <iostream>
#include <string>
#include <iomanip>

typedef double ld;

using namespace std;

int n;
string mat[1<<8];
ld wp[1<<8];
ld twp[1<<8][1<<8];
ld owp[1<<8];
ld oowp[1<<8];

int main(){
	int t; cin >> t;
	for (int zzz = 1; zzz <= t; zzz++){
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> mat[i];
		//cout << "wp: " << endl;
		for (int i = 0; i < n; i++){
			ld wins = 0, num = 0;
			for (int j = 0; j < n; j++){
				if (mat[i][j] == '1') wins++;
				if (mat[i][j] == '0' || mat[i][j] == '1') num++;
			}
			wp[i] = wins / num;
			//cout << wp[i] << endl;
			for (int j = 0; j < n; j++){
				if (mat[i][j] == '1') twp[i][j] = (wins-1)/(num-1);
				else if (mat[i][j] == '0') twp[i][j] = wins/(num-1);
				else twp[i][j] = wins/num;
				//cout << twp[i][j] << " ";
			}
			//cout << endl;
		}
		//cout << "owp: " << endl;
		for (int i = 0; i < n; i++){
			ld avg = 0;
			ld cnt = 0;
			for (int j = 0; j < n; j++){
				if (i == j) continue;
				if (mat[j][i] != '0' && mat[j][i] != '1') continue;
				avg += twp[j][i]; cnt++;
			}
			avg /= cnt;
			owp[i] = avg;
			//cout << owp[i] << endl;
		}
		for (int i = 0; i < n; i++){
			ld avg = 0;
			ld cnt = 0;
			for (int j = 0; j < n; j++){
				if (i == j) continue;
				if (mat[j][i] != '0' && mat[j][i] != '1') continue;
				avg += owp[j]; cnt++;
			}
			avg /= cnt;
			oowp[i] = avg;
		}
		cout << "Case #" << zzz << ":" << endl;
		for (int i = 0; i < n; i++){
			ld ans = 0.25 * wp[i] + 0.50 * owp[i] + 0.25 * oowp[i];
			cout << setprecision(12) << ans << endl;
		}
	}
	
	return 0;
}
