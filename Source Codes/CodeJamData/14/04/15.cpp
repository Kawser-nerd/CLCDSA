#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <string>
#include <complex>
#include <stack>
#include <iomanip>

using namespace std;
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;

int main() {
    int N;
    cin >> N;
    for(int z=1; z<=N; z++) {
        cout << "Case #" << z << ": ";
        int n; cin >> n;
        long double *x = new long double[n], *y = new long double[n];
        for(int i=0; i<n; i++) cin >> x[i];
        for(int i=0; i<n; i++) cin >> y[i];
        sort(x, x+n);
        sort(y, y+n);
        // cerr << endl;
        // for(int i=0; i<n; i++) cerr << x[i] << " "; cerr << endl;
        // for(int i=0; i<n; i++) cerr << y[i] << " "; cerr << endl;

        int i=0, j=0;
        for(; i<n; i++, j++) {
            if(j>=n) break;
            while(x[j] < y[i] && j < n) j++;
            if(j>=n) break;
            // cerr << "       " << x[j] << " beats " << y[i] << endl;
        }
        cout << i << " ";

        i=0, j=0;
        for(; i<n; i++, j++) {
            if(j>=n) break;
            while(y[j] < x[i] && j < n) j++;
            if(j>=n) break;
            // cerr << "       " << y[j] << " beats " << x[i] << endl;
        }
        cout << n-i << endl;
    }

    return 0;    
}
