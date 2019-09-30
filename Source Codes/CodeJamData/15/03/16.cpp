#include <bits/stdc++.h>
using namespace std;

#define size(v) int(v.size())
#define MOD 1000003
#define INF 1e9
#define ulint unsigned long long int
#define lint long long int
#define mp make_pair
#define pb push_back
#define pop pop_back
#define st first
#define nd second
#define all(X) (X).begin(),(X).end()
#define E12 1000000000000

struct min_heap_comparator{
	bool operator()(const long& a,const long& b) const{
		return a>b;
	}
};
#define mh_min(X) make_heap(all(X), min_heap_comparator());
#define poph_min(X) {pop_heap(all(X), min_heap_comparator()); (X).pop();}
#define pushh_min(X, Y) {(X).pb(Y); push_heap(all(X), min_heap_comparator());}
#define sorth_min(X) sort_heap(all(X), min_heap_comparator());

#define mh_max(X) make_heap(all(X));
#define poph_max(X) {pop_heap(all(X)); (X).pop();}
#define pushh_max(X, Y) {(X).pb(Y); push_heap(all(X));}
#define sorth_max(X) sort_heap(all(X));

int main(void){
	int multiplica[256][256];
	multiplica['1']['1'] = '1';
	multiplica['1']['i'] = 'i';
	multiplica['1']['j'] = 'j';
	multiplica['1']['k'] = 'k';
	multiplica['i']['1'] = 'i';
	multiplica['i']['i'] = 256-'1';
	multiplica['i']['j'] = 'k';
	multiplica['i']['k'] = 256-'j';
	multiplica['j']['1'] = 'j';
	multiplica['j']['i'] = 256-'k';
	multiplica['j']['j'] = 256-'1';
	multiplica['j']['k'] = 'i';
	multiplica['k']['1'] = 'k';
	multiplica['k']['i'] = 'j';
	multiplica['k']['j'] = 256-'i';
	multiplica['k']['k'] = 256-'1';

	multiplica[256-'1']['1'] = 256-'1';
	multiplica[256-'1']['i'] = 256-'i';
	multiplica[256-'1']['j'] = 256-'j';
	multiplica[256-'1']['k'] = 256-'k';
	multiplica[256-'i']['1'] = 256-'i';
	multiplica[256-'i']['i'] = '1';
	multiplica[256-'i']['j'] = 256-'k';
	multiplica[256-'i']['k'] = 'j';
	multiplica[256-'j']['1'] = 256-'j';
	multiplica[256-'j']['i'] = 'k';
	multiplica[256-'j']['j'] = '1';
	multiplica[256-'j']['k'] = 256-'i';
	multiplica[256-'k']['1'] = 256-'k';
	multiplica[256-'k']['i'] = 256-'j';
	multiplica[256-'k']['j'] = 'i';
	multiplica[256-'k']['k'] = '1';

	multiplica['1'][256-'1'] = 256-'1';
	multiplica['1'][256-'i'] = 256-'i';
	multiplica['1'][256-'j'] = 256-'j';
	multiplica['1'][256-'k'] = 256-'k';
	multiplica['i'][256-'1'] = 256-'i';
	multiplica['i'][256-'i'] = '1';
	multiplica['i'][256-'j'] = 256-'k';
	multiplica['i'][256-'k'] = 'j';
	multiplica['j'][256-'1'] = 256-'j';
	multiplica['j'][256-'i'] = 'k';
	multiplica['j'][256-'j'] = '1';
	multiplica['j'][256-'k'] = 256-'i';
	multiplica['k'][256-'1'] = 256-'k';
	multiplica['k'][256-'i'] = 256-'j';
	multiplica['k'][256-'j'] = 'i';
	multiplica['k'][256-'k'] = '1';

	multiplica[256-'1'][256-'1'] = '1';
	multiplica[256-'1'][256-'i'] = 'i';
	multiplica[256-'1'][256-'j'] = 'j';
	multiplica[256-'1'][256-'k'] = 'k';
	multiplica[256-'i'][256-'1'] = 'i';
	multiplica[256-'i'][256-'i'] = 256-'1';
	multiplica[256-'i'][256-'j'] = 'k';
	multiplica[256-'i'][256-'k'] = 256-'j';
	multiplica[256-'j'][256-'1'] = 'j';
	multiplica[256-'j'][256-'i'] = 256-'k';
	multiplica[256-'j'][256-'j'] = 256-'1';
	multiplica[256-'j'][256-'k'] = 'i';
	multiplica[256-'k'][256-'1'] = 'k';
	multiplica[256-'k'][256-'i'] = 'j';
	multiplica[256-'k'][256-'j'] = 256-'i';
	multiplica[256-'k'][256-'k'] = 256-'1';
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t){
		lint L, X;
		cin >> L >> X;
		string s;
		cin >> s;
		
		int atual = '1';
		bool hasI = false;
		bool hasJ = false;
		for (int i = 0; i < size(s); ++i){
			atual = multiplica[atual][(int)s[i]];
			if (atual == 'i'){
				hasI = true;
			}
			if (atual == 'k' && hasI){
				hasJ = true;
			}
			/*if (i% 16 == 0) cout << endl;
			if (atual < 128){
				cout << (char)atual << " ";
			} else {
				cout << "-" << (char)(256-atual) << " ";
			}*/
		}
		//cout << "X " << X << endl;
		if (atual == '1'){
			cout << "Case #" << t+1 << ": NO" << endl;
		} else if (atual == 256-'1'){
			if (X%2 == 0){
				cout << "Case #" << t+1 << ": NO" << endl;
			} else if (X == 1) {
				if (hasI && hasJ){
					cout << "Case #" << t+1 << ": YES" << endl;
				} else {
					cout << "Case #" << t+1 << ": NO" << endl;
				}
			} else {
				for (int i = 0; i < size(s); ++i){
					atual = multiplica[atual][(int)s[i]];
					if (atual == 'i'){
						hasI = true;
					}
					if (atual == 'k' && hasI){
						hasJ = true;
						break;
					}
				}
				if (hasJ){
					cout << "Case #" << t+1 << ": YES" << endl;
				} else if (!hasI){
					cout << "Case #" << t+1 << ": NO" << endl;
				} else {
					for (int i = 0; i < size(s); ++i){
						atual = multiplica[atual][(int)s[i]];
						if (atual == 'k'){
							hasJ = true;
							break;
						}
					}
					if (hasJ){
						cout << "Case #" << t+1 << ": YES" << endl;
					} else if (X == 3){
						cout << "Case #" << t+1 << ": NO" << endl;
					} else {
						for (int i = 0; i < size(s); ++i){
							atual = multiplica[atual][(int)s[i]];
							if (atual == 'k'){
								hasJ = true;
								break;
							}
						}
						if (hasJ){
							cout << "Case #" << t+1 << ": YES" << endl;
						} else {
							cout << "Case #" << t+1 << ": NO" << endl;
						}
					}
				}
			}
		} else {
			if (X%4 != 2){
				cout << "Case #" << t+1 << ": NO" << endl;
			} else {
				for (int i = 0; i < size(s); ++i){
					atual = multiplica[atual][(int)s[i]];
					if (atual == 'i'){
						hasI = true;
					}
					if (atual == 'k' && hasI){
						hasJ = true;
						break;
					}
				}
				if (hasJ){
					cout << "Case #" << t+1 << ": YES" << endl;
				} else if (X == 2) {
					cout << "Case #" << t+1 << ": NO" << endl;
				} else {
					s += s;
					for (int i = 0; i < size(s); ++i){
						atual = multiplica[atual][(int)s[i]];
						if (atual == 'i'){
							hasI = true;
						}
						if (atual == 'k' && hasI){
							hasJ = true;
							break;
						}
					}
					if (hasJ){
						cout << "Case #" << t+1 << ": YES" << endl;
					} else if (!hasI) {
						cout << "Case #" << t+1 << ": NO" << endl;
					} else {
						for (int i = 0; i < size(s); ++i){
							atual = multiplica[atual][(int)s[i]];
							if (atual == 'k'){
								hasJ = true;
								break;
							}
						}
						if (hasJ){
							cout << "Case #" << t+1 << ": YES" << endl;
						} else if (X == 6) {
							cout << "Case #" << t+1 << ": NO" << endl;
						} else {
							for (int i = 0; i < size(s); ++i){
								atual = multiplica[atual][(int)s[i]];
								if (atual == 'k'){
									hasJ = true;
									break;
								}
							}
							if (hasJ){
								cout << "Case #" << t+1 << ": YES" << endl;
							} else {
								cout << "Case #" << t+1 << ": NO" << endl;
							}
						}
					}
				}
			}
		}

		//cout << "Case #" << t+1 << ": " << endl;
	}
	return 0;
}
