//#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

//ifstream cin("B-small.in"); ofstream cout("B-small.out");
ifstream cin("B-large.in"); ofstream cout("B-large.out");

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		int C, D;
		cin >> C;
		vector <string> Cs, Ds;
		string ts;
		for (int i=0; i<C; i++) {
			cin >> ts;
			Cs.push_back(ts);
		}
		cin >> D;
		for (int i=0; i<D; i++) {
			cin >> ts;
			Ds.push_back(ts);
		}
		int N; string Ns;
		cin >> N >> Ns;

		vector <char> O;
		for (int i=0; i<N; i++) {
			if (O.size()==0) {
				O.push_back(Ns[i]);
			} else {
				bool ch = 0;
				for (int j=0; j<Cs.size(); j++) {
					if ((Cs[j][0]==Ns[i] && Cs[j][1]==O[O.size()-1]) || (Cs[j][1]==Ns[i] && Cs[j][0]==O[O.size()-1])) {
						O[O.size()-1] = Cs[j][2];
						ch = 1;
						break;
					}
				}
				if (!ch)
					O.push_back(Ns[i]);
				ch = 0;
				for (int j=0; j<Ds.size(); j++) {
					for (int k=0; k<O.size()-1; k++) {
						if ((Ds[j][0]==O[O.size()-1] && Ds[j][1]==O[k]) || (Ds[j][1]==O[O.size()-1] && Ds[j][0]==O[k])) {
							O.clear();
							ch = 1;
							break;
						}
					}
					if (ch)
						break;
				}

			}
		}
		cout << "[";
		if (O.size()!=0) {
			for (int i=0; i<O.size()-1; i++)
				cout << O[i] << ", ";
			cout << O[O.size()-1];
		}
		cout << "]" << endl;
	}
	return 0;
}
