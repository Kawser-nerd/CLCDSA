#include <iostream>
#define MAX_N 50
using namespace std;

int N, a[MAX_N];

int main(){
    cin >> N;
    for(int i = 0; i < N; ++i) cin >> a[i];

    int sum = INT_MIN;

    for(int i = 0; i < N; ++i){
        int takahashi = 0;
        int aoki = 0;
        int tmpTakahashi;
        int maxAoki = INT_MIN;
        for(int j = 0; j < N; ++j){
            if(i == j) continue;
            takahashi = 0;
            aoki = 0;
            for(int k = 0; k <= abs(j-i); ++k){
                if(k%2 == 0) takahashi += a[k+min(i,j)];
                else aoki += a[k+min(i,j)];
            }
            if(maxAoki < aoki){
                maxAoki = aoki;
                tmpTakahashi = takahashi;
            }
        }
        sum = max(sum, tmpTakahashi);
    }

    cout << sum << endl;

    return 0;
}