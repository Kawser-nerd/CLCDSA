#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define N_MAX 200
#define M_MAX 20000

using namespace std;

void find_shortest_pair(long dist[N_MAX][N_MAX], long edge[N_MAX][N_MAX], long n);

int main(){
    int N, M, R;
    int r[8];
    long A[M_MAX], B[M_MAX], C[M_MAX];
    long edge[N_MAX][N_MAX];
    long dist[N_MAX][N_MAX];
    long ans = __LONG_MAX__;
    long tmp = 0;
    cin >> N >> M >> R;
    vector<int> v(R);
    iota(v.begin(), v.end(), 1); 
    for(int i = 0; i < R; i++){
        cin >> r[i];
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            edge[i][j] = (long)INT32_MAX*1000;
        }
    }

    
    for(int i = 0; i < M; i++){
        cin >> A[i] >> B[i] >> C[i];
        edge[A[i]-1][B[i]-1] = C[i];
        edge[B[i]-1][A[i]-1] = C[i];
    }
    
    find_shortest_pair(dist, edge, N);

    do {
        for(int i = 1; i < R; i++){
            tmp += dist[r[v[i-1]-1]-1][r[v[i]-1]-1];
        }
        ans = min(tmp, ans);
        tmp = 0;
    } while( next_permutation(v.begin(), v.end()) );
    cout << ans << endl;
}

void find_shortest_pair(long dist[N_MAX][N_MAX], long edge[N_MAX][N_MAX], long n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = edge[i][j];
        }
        dist[i][i] = 0;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                long new_len = dist[j][i] + dist[i][k];
                dist[j][k] = min(new_len, dist[j][k]);
            }
        }
    }
}