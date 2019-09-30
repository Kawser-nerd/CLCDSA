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
    int N,X;
    cin >> N >> X;
    vector<int> m(N);
    int sum = 0;
    for (int i = 0; i < N; i++){
        cin >> m[i];
        sum += m[i];
    }
    X -= sum;
    int minm = *min_element(all(m));
    cout << N + X/minm << endl;




    return 0;
}