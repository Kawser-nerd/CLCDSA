#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

const long long INF = 1LL << 50;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<int> a(M+1), b(M+1), c(M+1);
    for( int i = 0; i < M; ++i ){
        cin >> a[i] >> b[i] >> c[i];
        c[i] = - c[i];
    }

    // ?????????(???????????????????????)
    // ??? edge ??????????????????
    // ????????????1????????? N-1 ??????????
    vector<long long> distance(N+1, INF);
    distance[1] = 0;
    for( int loop = 1; loop < N; ++loop ){
        for( int i = 0; i < M; ++i ){
            if( distance[a[i]] == INF ) continue;
            if( distance[b[i]] > distance[a[i]] + c[i] ){
                distance[b[i]] = distance[a[i]] + c[i];
            }
        }
    }
    long long ans = distance[N];

    // ??????
    // N ???????? distance[N] ??????????????????????
    vector<bool> negative(N+1, false);
    for( int loop = 1; loop <= N; ++loop ){
        for( int i = 0; i < M; ++i ){
            if( distance[a[i]] == INF ) continue;
            if( distance[b[i]] > distance[a[i]] + c[i] ){
                distance[b[i]] = distance[a[i]] + c[i];
                negative[b[i]] = true;
            }
            if( negative[a[i]] == true ) negative[b[i]] = true;
        }
    }

    if( negative[N] ) cout << "inf" << endl;
    else cout << - ans << endl;

    return 0;
}