#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int H, W;
    vector<vector<char>> grid;
    cin >> H >> W;
    vector<int> dot_count_row(H, 0);
    vector<int> dot_count_col(W, 0);

    for (size_t i = 0; i < H; i++) {
        vector<char> row;
        for (size_t j = 0; j < W; j++) {
            char c;
            cin >> c;
            row.push_back(c);
            if(c == '.') {
                dot_count_row[i]++;
                dot_count_col[j]++;
            }
        }
        grid.push_back(row);
    }

    for (size_t i = 0; i < H; i++) {
        if(dot_count_row[i] != W) {
            for (size_t j = 0; j < W; j++) {
                if(dot_count_col[j] != H) {
                    cout << grid[i][j];
                }
            }
            cout << endl;
        }
    }
}