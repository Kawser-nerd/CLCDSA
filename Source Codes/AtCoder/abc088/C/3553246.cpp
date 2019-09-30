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
int c[3][3];

int main() {
	for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            int x;
            cin >> x;
            c[i][j] = x;
        }
	}

    bool ans = true;
	for(int i=0; i<3; i++){
        for(int j=i+1; j<3; j++){
            if (c[0][i] - c[0][j] != c[1][i] - c[1][j]) ans = false;
            if (c[1][i] - c[1][j] != c[2][i] - c[2][j]) ans = false;
            if (c[i][0] - c[j][0] != c[i][1] - c[j][1]) ans = false;
            if (c[i][1] - c[j][1] != c[i][2] - c[j][2]) ans = false;
        }
    }

	cout << (ans ? "Yes" : "No") << endl;
}