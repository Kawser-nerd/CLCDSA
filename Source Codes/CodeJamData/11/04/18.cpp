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

//ifstream cin("D-small.in"); ofstream cout("D-small.out");
ifstream cin("D-large.in"); ofstream cout("D-large.out");

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		int N; cin >> N;
		int tmp;
		vector <int> C;
		for (int i=0; i<N; i++) {
			cin >> tmp;
			C.push_back(tmp);
		}
		int ans = 0;
		while (true) {
			bool s = 1;
			int ci = 0;
			for (int i=0; i<N; i++)
				if (C[i]!=i+1) {
					s=0;
					ci = i;
					break;
				}
			if (s)
				break;
			int cc = 1;
			int cci = C[ci]-1;
			C[ci] = ci + 1;
			while (cci != ci) {
				cc++;
				int tci = C[cci]-1;
				C[cci] = cci + 1;
				cci = tci;
			}
			ans += cc;
		}
		cout << ans << ".000000" << endl;
	}
	return 0;
}
