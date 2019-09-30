#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
#define ALL(obj) (obj).begin(), (obj).end()
#define REP(i, n) for (int i=0; i < (int)(n); i++)  // 0 ~ n-1 
 
int main() {
    // input
    int H, W;
    cin >> H >> W;
    char vec[55][55];
	for(int i = 0;i < H; i++)
	  scanf("%s",vec[i]);
    
    
    // calculation
    int cnt;
    REP(i, H) {
        REP(j, W) {
            if (vec[i][j] == '.') {
                cnt = 0;
                for (int k = i-1; k <= i+1; ++k) {
                    for (int l = j-1; l <= j+1; ++l) {
                        if (k < 0 || l <0) {
                            continue;
                        } else if (vec[k][l] == '#') {
                            cnt++;
                        }
                    }
                }
                cout << cnt;
            }
            else {
                cout << '#';
            }
        }
        cout << "\n";
    }
    
    return 0;
}