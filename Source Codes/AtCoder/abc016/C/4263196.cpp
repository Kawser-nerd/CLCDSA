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
#include <set>
#define all(x) (x).begin(),(x).end()

const int MOD = 1e9 + 7;

void solve(){

}

template <typename T>
void warshallFloyd(T& d){
    for (int i = 0; i < d.size(); i++) d[i][i] = 0;

    for (int k = 0; k < d.size(); k++){
		for (int i = 0; i < d.size(); i++){
	    	for (int j = 0; j < d.size(); j++){
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
	    	}
		}
    }
}

int main(){
    int N,M;
    cin >> N >> M;
    vector<vector<int>> d(N,vector<int>(N, INT_MAX/5));

    for (int i = 0; i < M; i++) {
        int A,B;
        cin >> A >> B;
        d[A - 1][B - 1] = 1;
        d[B - 1][A - 1] = 1;
    }
    warshallFloyd(d);

    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++)
            if (d[i][j] == 2) cnt++;
        cout << cnt << endl;
    }



    return 0;
}