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

//ifstream cin("A-small.in"); ofstream cout("A-small.out");
ifstream cin("A-large.in"); ofstream cout("A-large.out");

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		int N;
		cin >> N;
		vector <int> I;
		vector <char> C;
		int it; char ct;
		for (int i=0; i<N; i++) {
			cin >> ct;
			cin >> it;
			I.push_back(it);
			C.push_back(ct);
		}
		int ans = 0;
		int oi = 1, bi = 1;
		int ot = 0, bt = 0;
		for (int i=0; i<N; i++) {
			if (C[i]=='O') {
				ot += 1 + abs(I[i] - oi);
				oi = I[i];
				if (ot <= bt)
					ot = bt + 1;
				ans = ot;
			} else {
				bt += 1 + abs(I[i] - bi);
				bi = I[i];
				if (bt <= ot)
					bt = ot + 1;
				ans = bt;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
