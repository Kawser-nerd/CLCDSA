#include <iostream>

using namespace std;

int main(void) {
    const int MAX_W = 100;
    const int MAX_H = 100;
    int W, H, N;
    cin>>W>>H>>N;
    int matrix[W][H];
    for (int i=0; i<H; ++i) {
        for (int j=0; j<W; ++j) {
            matrix[j][i] = 0;
        }
    }

    int x, y, a;
    for (int n=0; n<N; ++n) {
        cin>>x>>y>>a;
        switch (a) {
        case 1:
            for (int i=0; i<H; ++i) {
                for (int j=0; j<x; ++j) {
                    matrix[j][i] = 1;
                }
            }
            break;
        case 2:
            for (int i=0; i<H; ++i) {
                for (int j=x; j<W; ++j) {
                    matrix[j][i] = 1;
                }
            }
            break;
        case 3:
            for (int i=0; i<y; ++i) {
                for (int j=0; j<W; ++j) {
                    matrix[j][i] = 1;
                }
            }
            break;
        case 4:
            for (int i=y; i<H; ++i) {
                for (int j=0; j<W; ++j) {
                    matrix[j][i] = 1;
                }
            }
            break;
        }
    }

    int cnt = 0;
    
    for (int i=0; i<H; ++i) {
        for (int j=0; j<W; ++j) {
            if (matrix[j][i] == 0) {
                cnt += 1;
            }
        }
    }
    cout<<cnt<<endl;
    
    return 0;
}