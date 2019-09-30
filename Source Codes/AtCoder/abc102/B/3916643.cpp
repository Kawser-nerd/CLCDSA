using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <iostream>
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
    vector<int> a(N);
    for (int i = 0; i < N; i++){
        cin >> a[i];
    }
    sort(all(a));
    cout << a[(int)a.size()-1] - a[0] << endl;


    return 0;
} ./Main.cpp:1:17: warning: using directive refers to implicitly-defined namespace 'std'
using namespace std;
                ^
1 warning generated.