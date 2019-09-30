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
        cout << "Case #" << z << ": " << endl;
        int c, r, m; cin >> r >> c >> m;
        int _ = c*r - m;
        if(_ == 1) {
            for(int i=0; i<r; i++) {
                for(int j=0; j<c; j++) {
                    cout << ((i||j)?'*':'c');
                } cout << endl;
            }
        } else if(c == 1) {
            cout << "c\n";
            for(int i=1; i<_; i++) {
                cout << "." << endl;
            }
            for(int i=_; i<r; i++) {
                cout << '*' << endl;
            }
        } else if(r == 1) {
            cout << "c";
            for(int i=1; i<_; i++) {
                cout << '.';
            }
            for(int i=_; i<c; i++ ) {
                cout << '*';
            } cout << endl;
        } else if(_ < 4) {
            cout << "Impossible" << endl;
        } else {
            char s[60][60];
            for(int i=0; i<r; i++) {
                for(int j=0; j<c; j++) {
                    s[i][j] = '*';
                }
                s[i][c] = '\n';
                s[i][c+1] = '\0';
            }
            s[0][0] = 'c';
            s[0][1] = '.';
            s[1][0] = '.';
            s[1][1] = '.';
            _-=4;
            int zxcv = 0, x = 2, y = 2;
            while(_ > 1) {
                zxcv = 0;
                if(_ > 1 && x < c) {
                    s[0][x] = '.';
                    s[1][x] = '.';
                    x++;
                    _-=2;
                    zxcv = 1;
                }
                if(_ > 1 && y < r) {
                    s[y][0] = '.';
                    s[y][1] = '.';
                    y++;
                    _-=2;
                    zxcv = 1;
                }
                if(!zxcv) break;
            }
            for(int j=2; j<x; j++) {
                for(int i=2; i<y; i++) {
                    if(_ > 0) {
                        s[i][j] = '.';
                        _--;
                    } else {
                        break;
                    }
                }
            }
            if(_ > 0) {
                cout << "Impossible" << endl;
                // cerr << "IMPOSSIBLE" << endl;
                // cerr << c << " " << r << " " << m << " " << _ << endl;
                for(int i=0; i<r; i++) {
                    // cerr << s[i];
                }
            } else
            for(int i=0; i<r; i++) {
                cout << s[i];
                // cerr << "POSSIBLE" << endl;
                // cerr << c << " " << r << " " << m << " " << _ << endl;
                for(int i=0; i<r; i++) {
                    // cerr << s[i];
                }
            }
        }
    }

    return 0;    
}
