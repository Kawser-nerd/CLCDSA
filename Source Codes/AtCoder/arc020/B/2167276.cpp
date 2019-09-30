#include <iostream>
#include <vector>
#include <algorithm>
#define REP(i,n) for(int (i)=0;(i)<(n);(i)++)

using namespace std;

int main() {
    int n, c, a;
    cin >> n >> c;
    vector<int> as;
    REP(i,n) {
        cin >> a;
        as.push_back(a);
    }
    
    int mi = n;
    int cr = 0;
    int crv = 0;
    
    for (int i = 1; i <= 10; i++) {
        for (int j = i + 1; j <= 10; j++) {
            REP(k,n) {
                if (k % 2) {
                    if (as[k] != i) cr++;
                    if (as[k] != j) crv++;
                } else {
                    if (as[k] != j) cr++;
                    if (as[k] != i) crv++;
                }
            }
            
            mi = min(mi, cr);
            mi = min(mi, crv);
            cr = 0;
            crv = 0;
        }
    }
    
    cout << mi * c << endl;
}