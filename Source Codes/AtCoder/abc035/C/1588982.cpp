#include <iostream>
#include <cstdio>
#define MAX_N 200001
using namespace std;

int N, Q, ans = 0;
int field[MAX_N] = {0};

int main(){
    cin >> N >> Q;
    for(int i = 0; i < Q; ++i){
        int l, r;
        scanf("%d %d", &l, &r);
        field[l]++;
        field[r+1]--;
    }

    for(int i = 0; i < N; ++i){
        field[i+1] = field[i+1] + field[i];
        printf("%d", field[i+1]&1);
    }

    cout << endl;

    return 0;
}