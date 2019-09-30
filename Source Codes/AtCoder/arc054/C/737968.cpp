#include<iostream>
#include<vector>
using namespace std;
const int BUF = 305;


int n;
int mat[BUF][BUF];

void read() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            char ch;
            cin >> ch;
            mat[i][j] = ch - '0';
        }
}


void work() {
    for (int i = 0; i < n; ++i) {
        int pivot = -1;
        for (int r = i; r < n; ++r) {
            if (mat[r][i] == 1) {
                pivot = r;
                break;
            }
        }

        if (pivot == -1) {
            cout << "Even" << endl;
            return;
        }

        for (int c = 0; c < n; ++c) {
            swap(mat[i][c], mat[pivot][c]);
        }
        
        for (int r = i + 1; r < n; ++r) {
            if (mat[r][i] == 1) {
                for (int c = 0; c < n; ++c) {
                    mat[r][c] = (mat[r][c] + mat[i][c]) % 2;
                }
            }
        }
    }

    cout << "Odd" << endl;
}


int main() {
    read();
    work();
    return 0;
}