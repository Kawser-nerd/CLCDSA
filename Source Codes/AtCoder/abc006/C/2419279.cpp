#include <iostream>
using namespace std;

int main() {
    int k, n, m;
    cin >> n >> m;
    
    if(4*n-m >= 0) {
        int i_border = 3*n-m, j_border = m-2*n;
        for(k=0; k<=n; k++) {
            if(i_border+k >= 0 && j_border-2*k >= 0) {
                cout << i_border+k << " " << j_border-2*k << " " << k << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;
}