#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int N, T;
    cin >> N >> T;
    int A[100000];
    int g[100000];
    cin >> A[0];
    int m = A[0];
    g[0] = 0;
    int m_idx = 0;
    for(int i = 1; i < N; i++){
        cin >> A[i];
        g[i] = A[i] - m;
        if(A[i] < m){
            m = A[i];
            m_idx = i;
        }
    }
    sort(g, g+N, greater<int>());
    int ans = 0;
    for(int i = 0; i <= m_idx; i++){
        if(g[i] == g[0]) ans++;
    }
    cout << ans << endl;
}