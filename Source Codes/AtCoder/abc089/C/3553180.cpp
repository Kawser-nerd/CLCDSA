#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <array>
using namespace std;
typedef long long unsigned int llui_t;
typedef long long int lli_t;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

/* inputs */
llui_t N;
vector<string> S;

int main() {
    cin >> N;

    vector<char> march = {'M', 'A', 'R', 'C', 'H'};
    vector<llui_t> march_n(5, 0);

	for(llui_t i=0; i<N; i++) {
		string s;
		cin >> s;
		S.push_back(s);
        for(int j=0; j<march.size(); j++) {
            if(s[0] == march[j]) {
                march_n[j] ++;
            }
        }
	}

    llui_t ans = 0;

    for(int i=0; i<march.size(); i++) {
        for(int j=i+1; j<march.size(); j++) {
            for(int k=j+1; k<march.size(); k++) {
                ans += march_n[i] * march_n[j] * march_n[k];
            }
        }
    }
	cout << ans << endl;
}