#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


int main()
{
    int N;
    long long K;
    cin >> N >> K;
    vector<pair<int,int>> num(N);
    for( int i = 0; i < N; ++i ){
        int a, b;
        cin >> a >> b;
        num[i] = make_pair( a, b );
    }


    sort( num.begin(), num.end() );
    long long sum = 0;
    for( int i = 0; i < N; ++i ){
        sum += num[i].second;
        if( K <= sum ){
            cout << num[i].first;
            break;
        } 
    } 

    return 0;
}