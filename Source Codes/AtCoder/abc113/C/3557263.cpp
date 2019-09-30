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
#include <sstream>
#include <iomanip>
using namespace std;
typedef long long unsigned int llui_t;
typedef long long int lli_t;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

struct city {
    llui_t index;
    llui_t p;
    llui_t y;
    string id;
};

/* inputs */
llui_t N, M;
vector<city> X;

int main() {
    cin >> N >> M;

	for(llui_t i=0; i<M; i++) {
		llui_t p, y;
		cin >> p >> y;
        city x = {i, p, y, ""};
		X.push_back(x);
	}

    sort(X.begin(), X.end(), [](city c1, city c2){return c1.y < c2.y;});

    vector<llui_t> pn(N, 1);

    for(city& c:X) {
        ostringstream sout;
        sout << setfill('0') << setw(6) << c.p;
        sout << setfill('0') << setw(6) << pn[c.p-1]++;
        c.id = sout.str();
	}

    sort(X.begin(), X.end(), [](city c1, city c2){return c1.index < c2.index;});

    for(city c:X) {
        cout << c.id << endl;
	}

}