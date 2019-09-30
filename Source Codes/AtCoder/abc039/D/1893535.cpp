#include <algorithm>
#include <complex>
#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::cerr;

using std::string;
using std::to_string;
using std::vector;
using std::set;
using std::queue;
using std::stack;
using std::priority_queue;

using std::min;
using std::max;
using std::sort;
using std::abs;

typedef long long int ll;
const int MOD = 1e9 + 7;


int main() {
    static int dx[] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    static int dy[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    for (int i = 0; i < h; i++) {
        cin >> a[i];
    }

    // a[h][w]
    vector<string> b(a);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            b[i][j] = '.';
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            bool black = true;
            for(int k = 0; k < 9; k++){
                int y = i + dy[k];
                int x = j + dx[k];
                if(0 <= y && y < h && 0 <= x && x < w && a[y][x] == '.'){
                    black = false;
                    break;
                }
            }
            if(black){
                b[i][j] = '#';
            }
        }
    }

    vector<string> c(b);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if(b[i][j] == '.'){
                continue;
            }
            for(int k = 0; k < 9; k++){
                int y = i + dy[k];
                int x = j + dx[k];
                if(0 <= y && y < h && 0 <= x && x < w){
                    c[y][x] = '#';
                }
            }
        }
    }

    if(a == c){
        cout << "possible" << endl;
        for (int i = 0; i < h; i++) {
            cout << b[i] << endl;
        }
    }else{
        cout << "impossible" << endl;
    }


    return 0;
}