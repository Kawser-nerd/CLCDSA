#include <iostream>

using namespace std;

int gcd(int n, int m){
    if(n < m) swap(n, m);
    while(m != 0){
        int tmp = m;
        m = n%m;
        n = tmp;
    }
    return n;
}

int main(){
    int N, K;
    int A_max = 0;
    int A[100000];
    cin >> N >> K;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        A_max = max(A_max, A[i]);
    }
    int m = A[0];
    for(int i = 1; i < N; i++){
        m = gcd(m, A[i]);
    }
    if(K%m == 0 && K <= A_max) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
}