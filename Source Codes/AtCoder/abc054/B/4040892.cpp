#include <iostream>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#define all(x) (x).begin(),(x).end()

void solve(){

}
int main(){
    int N,M;
    cin >> N >> M;
    vector<string> a(N),b(M);
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }

    for (int i = 0; i < M; i++){
        cin >> b[i];
    }

    bool ans = false;
    for (int i = 0; i < N; i++){
        for (int k = 0; k < N; k++){
            if (i + M <= N && k + M <= N){
                bool match = true;
                for (int p = 0; p < M; p++){
                    for (int r = 0; r < M; r++){
                        if (a[i+p][k+r] != b[p][r]){
                                match = false;
                        }
                    }
                }
                if (match){
                    ans = true;
                }
            }
        }
    }
    if (ans){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
}