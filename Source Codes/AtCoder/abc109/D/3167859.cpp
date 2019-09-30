#include <iostream>
#include <vector>
#include <string>
#include <boost/format.hpp>

using namespace std;

int main(int argc, const char * argv[]) {
    int H, W; cin >> H >> W;
    vector<vector<int>> a(H, vector<int>(W));
    vector<string> ansTrack;
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int inp; cin >> inp;
            a[i][j] = inp;
        }
    }
    
    int N = 0;
    for (int j = 0; j < W; j++) {
        for (int i = 0; i < H - 1; i++) {
            if (a[i][j] % 2 == 1) {
                a[i][j]--; a[i+1][j]++;
                string oprHistory = (boost::format("%d %d %d %d") % (i+1) % (j+1) % (i+2) % (j+1)).str();
                ansTrack.push_back(oprHistory);
                N++;
            }
        }
    }
    
    for (int j = 0; j < W - 1; j++) {
        if (a[H-1][j] % 2 == 1) {
            a[H-1][j]--; a[H-1][j+1]++;
            string oprHistory = (boost::format("%d %d %d %d") % H % (j+1) % H % (j+2)).str();
            ansTrack.push_back(oprHistory);
            N++;
        }
    }
    
    cout << N << endl;
    for (int i = 0; i < N; i++) {
        cout << ansTrack[i] << endl;
    }

    return 0;
}