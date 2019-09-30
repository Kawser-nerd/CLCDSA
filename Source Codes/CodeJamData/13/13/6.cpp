#include <iostream>
#include <cstdlib>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;

int r, m, n, k;

ll factorial[1<<4];
int currcnt[1<<4];
int numcnt[1<<16][1<<4];

ll prior[1<<16];
map<ll,ld> prod[1<<16];

ll target[1<<4];

int cnt = 0;

void generate(int ind, int left){
	if (ind > m) return;
	if (ind == m){
		numcnt[cnt][ind] = left;
		for (int i = 2; i < m; i++)
			numcnt[cnt][i] = currcnt[i];
		
		prior[cnt] = factorial[n];
		for (int i = 2; i <= m; i++)
			prior[cnt] /= factorial[numcnt[cnt][i]];	
		
		cnt++;
		//cout << "test" << endl;
		return;
	}
	for (int i = 0; i <= left; i++){
		currcnt[ind] = i;
		generate(ind+1,left-i);
	}
}

void calc_prod(int ca, int ind, ll pr, ll prob){
	if (ind > m){
		prod[ca][pr] += prob;
		return;
	}
	for (int i = 0; i <= numcnt[ca][ind]; i++){
		ll np = prob;
		np *= (factorial[numcnt[ca][ind]] / factorial[i] / factorial[numcnt[ca][ind]-i]);
		calc_prod(ca,ind+1,pr,np);
		pr *= ind;
	}
}

void print_ans(int ca){
	for (int i = 2; i <= m; i++)
		for (int j = 0; j < numcnt[ca][i]; j++)
			cout << i;
}

int main(){
	int tt; cin >> tt;
	cin >> r >> n >> m >> k;
	
	factorial[0] = 1;
	factorial[1] = 1;
	for (int i = 2; i < 14; i++)
		factorial[i] = factorial[i-1] * i;
		
	//cout << "here0" << endl;
	generate(2,n);
	
	//cout << "cnt = " << cnt << endl;
	
	//cout << "here" << endl;
	for (int i = 0; i < cnt; i++){
		calc_prod(i,2,1,1);
	}
	
	cout << "Case #1:" << endl;
	for (int zz = 1; zz <= r; zz++){
		
		for (int i = 0; i < k; i++)
			cin >> target[i];
		
		int best = 0;
		ld bestval = 0;
		
		for (int i = 0; i < cnt; i++){
			ld sc = prior[i];
			bool okay = true;
			for (int j = 0; j < k; j++){
				sc *= prod[i][target[j]];
				if (sc < 1){
					okay = false;
					break;
				}
			}
			if (!okay) continue;
			if (sc > bestval){
				bestval = sc;
				best = i;
				/*cout << "best = ";
				print_ans(i);
				cout << ", score = " << sc << endl;*/
			}
		}
		print_ans(best);
		cout << endl;
	}
	
	return 0;
}
