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

//ifstream cin("C-small.in"); ofstream cout("C-small.out");
ifstream cin("C-large.in"); ofstream cout("C-large.out");

int main() {
	int T;
	cin >> T;
	for (int t=1; t<=T; t++) {
		cout << "Case #" << t << ": ";
		int N;
		int tmp;
		cin >> N;
		vector <int> C;
		int ans = 0;
		for (int i=0; i<N; i++) {
			cin >> tmp;
			C.push_back(tmp);
			ans ^= tmp;
		}
		if (ans != 0)
			cout << "NO" << endl;
		else {
			sort(C.begin(), C.end());
			ans = 0;
			for (int i=1; i<N; i++)
				ans += C[i];
			cout << ans << endl;
		}

	}
	return 0;
}
