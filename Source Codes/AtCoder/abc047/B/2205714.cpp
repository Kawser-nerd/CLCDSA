#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int w, h, n;
    cin >> w >> h >> n;

    vector<vector<bool>> rec(w, vector<bool>(h, true));

    for (int i = 0; i < n; i++) {
        int x, y, a;
        cin >> x >> y >> a;
        switch (a) {
            case 1:
                for (int j = 0; j < x; j++) {
                    for (int k = 0; k < h; k++) {
                        rec[j][k] = false;
                    }
                }
                break;

            case 2:
                for (int j = x; j < w; j++) {
                    for (int k = 0; k < h; k++) {
                        rec[j][k] = false;
                    }
                }
                break;

            case 3:
                for (int j = 0; j < y; j++) {
                    for (int k = 0; k < w; k++) {
                        rec[k][j] = false;
                    }
                }
                break;

            case 4:
                for (int j = y; j < h; j++) {
                    for (int k = 0; k < w; k++) {
                        rec[k][j] = false;
                    }
                }
                break;
        }
    }

    int ans = 0;
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (rec[i][j]) {
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}