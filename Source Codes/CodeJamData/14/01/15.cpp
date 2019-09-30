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
        int a; cin >> a;
        int hmm[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                int x; cin >> x;
                if(i==a-1) hmm[x-1]++;
            }
        }
        cin >> a;
        for(int i=0; i<4; i++) {
            for(int j=0; j<4; j++) {
                int x; cin >> x;
                if(i==a-1) hmm[x-1]++;
            }
        }
        int two = 0, ans;
        for(int i=0; i<16; i++) {
            if(hmm[i] == 2) {
                two++;
                ans = i+1;
            }
        }
        if(two == 1) {
            cout << "Case #" << z << ": " << ans << endl;
        } else if(two == 0) {
            cout << "Case #" << z << ": " << "Volunteer cheated!" << endl;
        } else {
            cout << "Case #" << z << ": " << "Bad magician!" << endl;
        }
    }
    return 0;    
}
