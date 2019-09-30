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
    int N;
    cin >> N;
    vector<int> t(N);
    int sum = 0;
    for (int i = 0; i < N; i++){
        cin >> t[i];
        sum += t[i];
    }
    int M;
    cin >> M;
    vector<int> p(M),x(M);
    for (int i = 0; i < M; i++){
        cin >> p[i] >> x[i];
        cout << sum + (x[i] - t[p[i]-1]) << endl;
    }





    return 0;
}