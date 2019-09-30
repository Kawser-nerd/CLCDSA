#include <iostream>
#define MAX_N 100000
#define MAX_M 100000
using namespace std;

typedef long long ll;

int N, M, X, Y;
int a[MAX_N], b[MAX_M];

int main(){
    cin >> N >> M >> X >> Y;
    for(int i = 0; i < N; ++i) cin >> a[i];
    for(int i = 0; i < M; ++i) cin >> b[i];

    int t1 = a[0], t2 = a[0]+X;
    int index1 = 0, index2 = 0;

    ll ans = 0;

    while(1){
        for(; index1 < N; ++index1){
            if(a[index1] >= t1){
                t2 = a[index1] + X;
                ans++;
                break;
            }
        }
        

        if(index1 >= N || t2 >= b[M-1]+Y) break;

        for(; index2 < M; ++index2){
            if(b[index2] >= t2){
                t1 = b[index2] + Y;
                ans++;
                break;
            }
        }

        if(index2 >= M || t1 >= a[N-1]+X) break;
    }

    cout << ans / 2 << endl;
    return 0;
}